#include <pch.hpp>
#include <core/thread_pool.hpp>
#include <core/log.hpp>
#include <core/modules.hpp>

namespace opaline::core {

	namespace detail {

		using thread_fn = unsigned( __cdecl* )( void* );
		using create_simple_thread_fn = void* ( __cdecl* )( thread_fn, void*, DWORD*, int, int, void*, void* );
		using release_thread_handle_fn = void( __cdecl* )( void* );

		constexpr auto k_max_workers{ 7ull };
		constexpr auto k_exit_poll{ std::chrono::milliseconds( 1 ) };
		constexpr auto k_exit_timeout{ std::chrono::seconds( 2 ) };
		constexpr auto k_exit_grace{ std::chrono::milliseconds( 20 ) };

		template <typename type>
		[[nodiscard]] static type tier0_export( const char* name )
		{
			return reinterpret_cast< type >( GetProcAddress( reinterpret_cast< HMODULE >( g_modules.tier0.base( ) ), name ) );
		}

		[[nodiscard]] static std::size_t physical_cores( )
		{
			auto length{ 0ul };
			GetLogicalProcessorInformationEx( RelationProcessorCore, nullptr, &length );

			std::vector<std::uint8_t> buffer( length );
			if ( length == 0 || !GetLogicalProcessorInformationEx( RelationProcessorCore, reinterpret_cast< SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX* >( buffer.data( ) ), &length ) )
			{
				return 0;
			}

			auto count{ 0ull };

			for ( auto offset = 0ull; offset < length; )
			{
				const auto info = reinterpret_cast< const SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX* >( buffer.data( ) + offset );
				count += info->Relationship == RelationProcessorCore;
				offset += info->Size;
			}

			return count;
		}

		[[nodiscard]] static std::size_t worker_count( )
		{
			const auto cores = physical_cores( );
			const auto count = cores == 0 ? std::max( 1u, std::thread::hardware_concurrency( ) / 2 ) : cores > 2 ? cores - 1 : cores;

			return std::min<std::size_t>( count, k_max_workers );
		}

		static void drain( std::atomic<int>& next, int count, const std::function<void( int )>& body )
		{
			for ( auto index = next.fetch_add( 1 ); index < count; index = next.fetch_add( 1 ) )
			{
				body( index );
			}
		}

	} // namespace detail

	bool thread_pool::start( )
	{
		const auto create = detail::tier0_export<detail::create_simple_thread_fn>( "CreateSimpleThread" );
		if ( !create )
		{
			g_log.print( "[threads] CreateSimpleThread missing" );
			return false;
		}

		const auto count = detail::worker_count( );

		for ( auto index = 0ull; index < count; ++index )
		{
			auto id{ 0ul };

			this->m_alive.fetch_add( 1 );

			const auto handle = create( &thread_pool::entry, this, &id, 0, 0, nullptr, nullptr );
			if ( !handle )
			{
				this->m_alive.fetch_sub( 1 );
				continue;
			}

			this->m_threads.push_back( handle );
			this->m_thread_ids.push_back( id );
		}

		g_log.print( "[threads] {} workers", this->m_threads.size( ) );

		return !this->m_threads.empty( );
	}

	void thread_pool::stop( )
	{
		{
			std::lock_guard lock( this->m_mutex );
			this->m_stop = true;
		}

		this->m_wake.notify_all( );

		const auto deadline = std::chrono::steady_clock::now( ) + detail::k_exit_timeout;

		while ( this->m_alive.load( ) > 0 && std::chrono::steady_clock::now( ) < deadline )
		{
			std::this_thread::sleep_for( detail::k_exit_poll );
		}

		std::this_thread::sleep_for( detail::k_exit_grace );

		if ( const auto release = detail::tier0_export<detail::release_thread_handle_fn>( "ReleaseThreadHandle" ) )
		{
			for ( const auto handle : this->m_threads )
			{
				release( handle );
			}
		}

		this->m_threads.clear( );
		this->m_thread_ids.clear( );
	}

	void thread_pool::parallel_for( int count, const std::function<void( int )>& body )
	{
		if ( count <= 0 )
		{
			return;
		}

		if ( count == 1 || this->m_threads.empty( ) || this->is_worker( ) )
		{
			for ( auto index = 0; index < count; ++index )
			{
				body( index );
			}

			return;
		}

		std::lock_guard dispatch( this->m_dispatch );

		job current{};
		current.body = &body;
		current.count = count;

		{
			std::lock_guard lock( this->m_mutex );
			this->m_job = &current;
			++this->m_generation;
		}

		this->m_wake.notify_all( );
		detail::drain( current.next, count, body );

		std::unique_lock lock( this->m_mutex );
		this->m_job = nullptr;
		this->m_done.wait( lock, [ &current ] { return current.users == 0; } );
	}

	unsigned __cdecl thread_pool::entry( void* self )
	{
		static_cast< thread_pool* >( self )->work( );
		return 0;
	}

	void thread_pool::work( )
	{
		auto seen = std::size_t{};

		while ( true )
		{
			job* current{};

			{
				std::unique_lock lock( this->m_mutex );
				this->m_wake.wait( lock, [ & ] { return this->m_stop || ( this->m_job && this->m_generation != seen ); } );

				if ( this->m_stop )
				{
					break;
				}

				seen = this->m_generation;
				current = this->m_job;
				++current->users;
			}

			detail::drain( current->next, current->count, *current->body );

			std::lock_guard lock( this->m_mutex );

			if ( --current->users == 0 )
			{
				this->m_done.notify_all( );
			}
		}

		this->m_alive.fetch_sub( 1 );
	}

	bool thread_pool::is_worker( ) const
	{
		return std::ranges::contains( this->m_thread_ids, GetCurrentThreadId( ) );
	}

} // namespace opaline::core

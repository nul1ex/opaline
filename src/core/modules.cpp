#include <pch.hpp>
#include <core/modules.hpp>
#include <core/log.hpp>

namespace opaline::core {

	namespace detail {

		struct pattern
		{
			std::vector<std::optional<std::uint8_t>> bytes{};
			std::optional<std::size_t> operand{};
		};

		struct registration
		{
			void* ( *create )( );
			const char* name;
			registration* next;
		};

		[[nodiscard]] static int hex_value( char c )
		{
			if ( c >= '0' && c <= '9' )
			{
				return c - '0';
			}

			if ( c >= 'a' && c <= 'f' )
			{
				return c - 'a' + 10;
			}

			if ( c >= 'A' && c <= 'F' )
			{
				return c - 'A' + 10;
			}

			return -1;
		}

		[[nodiscard]] static std::optional<pattern> parse( std::string_view text )
		{
			pattern out{};
			std::optional<std::size_t> open{};

			for ( auto i = 0ull; i < text.size( ); )
			{
				const auto c = text[ i ];

				if ( c == ' ' )
				{
					++i;
				}
				else if ( c == '[' )
				{
					if ( open || out.operand )
					{
						return std::nullopt;
					}

					open = out.bytes.size( );
					++i;
				}
				else if ( c == ']' )
				{
					if ( !open || out.bytes.size( ) - *open != sizeof( std::int32_t ) )
					{
						return std::nullopt;
					}

					out.operand = std::exchange( open, std::nullopt );
					++i;
				}
				else if ( c == '?' )
				{
					out.bytes.emplace_back( std::nullopt );
					i += i + 1 < text.size( ) && text[ i + 1 ] == '?' ? 2 : 1;
				}
				else
				{
					const auto high = hex_value( c );
					const auto low = i + 1 < text.size( ) ? hex_value( text[ i + 1 ] ) : -1;

					if ( high < 0 || low < 0 )
					{
						return std::nullopt;
					}

					out.bytes.emplace_back( static_cast< std::uint8_t >( ( high << 4 ) | low ) );
					i += 2;
				}
			}

			if ( open || out.bytes.empty( ) )
			{
				return std::nullopt;
			}

			return out;
		}

		[[nodiscard]] static std::uintptr_t scan( std::uintptr_t base, std::size_t size, const pattern& p )
		{
			const auto anchor = std::ranges::find_if( p.bytes, [ ]( const auto& b ) { return b.has_value( ); } );
			if ( anchor == p.bytes.end( ) || p.bytes.size( ) > size )
			{
				return 0;
			}

			const auto anchor_index = static_cast< std::size_t >( std::distance( p.bytes.begin( ), anchor ) );
			const auto first = reinterpret_cast< const std::uint8_t* >( base );
			const auto last = first + size - p.bytes.size( );

			for ( auto cursor = first + anchor_index; cursor <= last + anchor_index; )
			{
				const auto hit = static_cast< const std::uint8_t* >( std::memchr( cursor, **anchor, static_cast< std::size_t >( last + anchor_index - cursor ) + 1 ) );
				if ( !hit )
				{
					return 0;
				}

				const auto start = hit - anchor_index;
				auto matched{ true };

				for ( auto j = 0ull; j < p.bytes.size( ); ++j )
				{
					if ( p.bytes[ j ].has_value( ) && start[ j ] != *p.bytes[ j ] )
					{
						matched = false;
						break;
					}
				}

				if ( matched )
				{
					return reinterpret_cast< std::uintptr_t >( start );
				}

				cursor = hit + 1;
			}

			return 0;
		}

	} // namespace detail

	dll::dll( std::string_view name )
	{
		const auto handle = GetModuleHandleA( std::string( name ).c_str( ) );
		if ( !handle )
		{
			return;
		}

		const auto base = reinterpret_cast< std::uintptr_t >( handle );
		const auto dos = reinterpret_cast< const IMAGE_DOS_HEADER* >( base );
		const auto nt = reinterpret_cast< const IMAGE_NT_HEADERS* >( base + dos->e_lfanew );

		this->m_base = base;
		this->m_size = nt->OptionalHeader.SizeOfImage;
	}

	address dll::find( std::string_view text ) const
	{
		const auto parsed = detail::parse( text );
		if ( !parsed )
		{
			g_log.print( "[pattern] invalid: {}", text );
			return {};
		}

		const auto match = this->valid( ) ? detail::scan( this->m_base, this->m_size, *parsed ) : 0;
		if ( !match )
		{
			g_log.print( "[pattern] no match: {}", text );
			return {};
		}

		if ( !parsed->operand )
		{
			return address{ match };
		}

		const auto operand = match + *parsed->operand;
		return address{ operand + sizeof( std::int32_t ) + *reinterpret_cast< const std::int32_t* >( operand ) };
	}

	void* dll::get_interface( std::string_view name ) const
	{
		const auto create_interface = this->valid( ) ? reinterpret_cast< std::uintptr_t >( GetProcAddress( reinterpret_cast< HMODULE >( this->m_base ), "CreateInterface" ) ) : 0;
		if ( !create_interface )
		{
			return nullptr;
		}

		const auto list = *reinterpret_cast< detail::registration** >( create_interface + 7 + *reinterpret_cast< const std::int32_t* >( create_interface + 3 ) );

		for ( auto current = list; current; current = current->next )
		{
			if ( current->name && current->create && name == current->name )
			{
				return current->create( );
			}
		}

		g_log.print( "[interface] not found: {}", name );
		return nullptr;
	}

	bool load_modules( )
	{
		g_modules.client = dll( "client.dll" );
		g_modules.render_system = dll( "rendersystemdx11.dll" );
		g_modules.schema_system = dll( "schemasystem.dll" );
		g_modules.input_system = dll( "inputsystem.dll" );
		g_modules.tier0 = dll( "tier0.dll" );
		g_modules.engine2 = dll( "engine2.dll" );

		return g_modules.client.valid( ) && g_modules.render_system.valid( ) && g_modules.schema_system.valid( ) && g_modules.input_system.valid( ) && g_modules.tier0.valid( ) && g_modules.engine2.valid( );
	}

} // namespace opaline::core

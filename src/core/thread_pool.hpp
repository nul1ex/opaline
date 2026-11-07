#pragma once

namespace opaline::core {

	class thread_pool
	{
	public:
		bool start( );
		void stop( );

		void parallel_for( int count, const std::function<void( int )>& body );

		[[nodiscard]] std::size_t workers( ) const noexcept { return this->m_threads.size( ); }

	private:
		struct job
		{
			const std::function<void( int )>* body{};
			int count{};
			std::atomic<int> next{};
			int users{};
		};

		static unsigned __cdecl entry( void* self );

		void work( );
		[[nodiscard]] bool is_worker( ) const;

		std::vector<void*> m_threads{};
		std::vector<DWORD> m_thread_ids{};
		std::mutex m_dispatch{};
		std::mutex m_mutex{};
		std::condition_variable m_wake{};
		std::condition_variable m_done{};
		job* m_job{};
		std::size_t m_generation{};
		std::atomic<std::size_t> m_alive{};
		bool m_stop{};
	};

	inline thread_pool g_thread_pool{};

} // namespace opaline::core

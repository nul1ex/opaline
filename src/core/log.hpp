#pragma once

namespace opaline::core {

	class log
	{
	public:
		void open( const std::filesystem::path& path );
		void close( );

		template <typename... args>
		void print( std::format_string<args...> fmt, args&&... values )
		{
			this->write( std::format( fmt, std::forward<args>( values )... ) );
		}

	private:
		void write( const std::string& line );

		std::ofstream m_file{};
		std::mutex m_mutex{};
	};

	inline log g_log{};

} // namespace opaline::core

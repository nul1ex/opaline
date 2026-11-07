#include <pch.hpp>
#include <core/log.hpp>

namespace opaline::core {

	void log::open( const std::filesystem::path& path )
	{
		std::scoped_lock lock( this->m_mutex );
		this->m_file.open( path, std::ios::out | std::ios::trunc );
	}

	void log::close( )
	{
		std::scoped_lock lock( this->m_mutex );
		this->m_file.close( );
	}

	void log::write( const std::string& line )
	{
		std::scoped_lock lock( this->m_mutex );

		OutputDebugStringA( std::format( "[opaline] {}\n", line ).c_str( ) );

		if ( this->m_file.is_open( ) )
		{
			this->m_file << line << '\n';
			this->m_file.flush( );
		}
	}

} // namespace opaline::core

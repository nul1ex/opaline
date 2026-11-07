#include <pch.hpp>
#include <ui/config.hpp>
#include <core/log.hpp>

namespace opaline::ui {

	namespace detail {

		[[nodiscard]] static bool valid_name( std::string_view name )
		{
			return !name.empty( ) && name.size( ) <= 48 && std::ranges::all_of( name, [ ]( char c ) { return std::isalnum( static_cast< unsigned char >( c ) ) || c == ' ' || c == '_' || c == '-'; } );
		}

	} // namespace detail

	setting_base::setting_base( std::string_view group, std::string_view name ) : m_group( group ), m_name( name )
	{
		g_config.add( this );
	}

	void config::initialize( )
	{
		std::array<wchar_t, MAX_PATH> app_data{};
		const auto length = GetEnvironmentVariableW( L"APPDATA", app_data.data( ), static_cast< DWORD >( app_data.size( ) ) );

		if ( length == 0 || length >= app_data.size( ) )
		{
			core::g_log.print( "[config] APPDATA is not available" );
			return;
		}

		this->m_directory = std::filesystem::path( app_data.data( ) ) / L"opaline" / L"configs";

		std::error_code error{};
		std::filesystem::create_directories( this->m_directory, error );

		if ( error )
		{
			core::g_log.print( "[config] cannot create {}: {}", this->m_directory.string( ), error.message( ) );
		}
	}

	void config::add( setting_base* setting )
	{
		this->m_settings.push_back( setting );
	}

	std::vector<std::string> config::list( ) const
	{
		std::vector<std::string> out{};
		std::error_code error{};

		for ( const auto& entry : std::filesystem::directory_iterator( this->m_directory, error ) )
		{
			if ( entry.is_regular_file( ) && entry.path( ).extension( ) == L".json" )
			{
				out.push_back( entry.path( ).stem( ).string( ) );
			}
		}

		std::ranges::sort( out );
		return out;
	}

	bool config::save( std::string_view name ) const
	{
		const auto file = this->path( name );
		if ( !file )
		{
			return false;
		}

		auto document = nlohmann::json::object( );

		for ( const auto* setting : this->m_settings )
		{
			document[ setting->group( ) ][ setting->name( ) ] = setting->save( );
		}

		std::ofstream stream( *file, std::ios::out | std::ios::trunc );
		stream << document.dump( 1, '\t' );

		return stream.good( );
	}

	bool config::load( std::string_view name )
	{
		const auto file = this->path( name );
		if ( !file )
		{
			return false;
		}

		std::ifstream stream( *file );
		const auto document = nlohmann::json::parse( stream, nullptr, false );

		if ( document.is_discarded( ) || !document.is_object( ) )
		{
			core::g_log.print( "[config] {} is not valid json", name );
			return false;
		}

		for ( auto* setting : this->m_settings )
		{
			setting->reset( );

			const auto group = document.find( setting->group( ) );
			if ( group == document.end( ) || !group->is_object( ) )
			{
				continue;
			}

			const auto value = group->find( setting->name( ) );
			if ( value == group->end( ) )
			{
				continue;
			}

			try
			{
				setting->load( *value );
			}
			catch ( const nlohmann::json::exception& )
			{
				setting->reset( );
				core::g_log.print( "[config] {} has a bad value for {} / {}", name, setting->group( ), setting->name( ) );
			}
		}

		return true;
	}

	bool config::remove( std::string_view name ) const
	{
		const auto file = this->path( name );
		std::error_code error{};

		return file && std::filesystem::remove( *file, error );
	}

	std::optional<std::filesystem::path> config::path( std::string_view name ) const
	{
		if ( this->m_directory.empty( ) || !detail::valid_name( name ) )
		{
			return std::nullopt;
		}

		return this->m_directory / std::filesystem::path( std::string( name ) + ".json" );
	}

} // namespace opaline::ui

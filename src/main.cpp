#include <pch.hpp>
#include <core/game.hpp>
#include <core/hooks.hpp>
#include <core/log.hpp>
#include <core/modules.hpp>
#include <core/thread_pool.hpp>
#include <ui/config.hpp>
#include <ui/menu.hpp>
#include <ui/render.hpp>

namespace opaline::detail {

	[[nodiscard]] static std::filesystem::path module_directory( HMODULE module )
	{
		std::array<wchar_t, MAX_PATH> path{};
		GetModuleFileNameW( module, path.data( ), static_cast< DWORD >( path.size( ) ) );

		return std::filesystem::path( path.data( ) ).parent_path( );
	}

	[[nodiscard]] static bool start( HMODULE module )
	{
		core::g_log.open( module_directory( module ) / L"opaline_log.txt" );
		core::g_log.print( "[init] loading." );

		if ( !core::load_modules( ) )
		{
			core::g_log.print( "[init] modules missing." );
			return false;
		}

		const auto resolved = core::resolve_game( );
		if ( !resolved )
		{
			return false;
		}

		ui::g_config.initialize( );
		core::g_thread_pool.start( );

		return core::install_hooks( );
	}

	static void stop( )
	{
		core::remove_hooks( );
		std::this_thread::sleep_for( std::chrono::milliseconds( 250 ) );
		core::g_thread_pool.stop( );

		ui::g_menu.shutdown( );
		ui::g_render.shutdown( );

		core::g_log.print( "[init] unloaded." );
		core::g_log.close( );
	}

} // namespace opaline::detail

BOOL APIENTRY DllMain( HMODULE module, DWORD reason, LPVOID reserved )
{
	if ( reason == DLL_PROCESS_ATTACH )
	{
		DisableThreadLibraryCalls( module );

		if ( !opaline::detail::start( module ) )
		{
			opaline::core::g_log.print( "[init] failed." );
			return FALSE;
		}

		opaline::core::g_log.print( "[init] loaded." );
	}
	else if ( reason == DLL_PROCESS_DETACH && !reserved )
	{
		opaline::detail::stop( );
	}

	return TRUE;
}

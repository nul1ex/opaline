#include <pch.hpp>
#include <features/movement/movement.hpp>
#include <ui/input.hpp>
#include <settings.hpp>

namespace opaline::movement {

	void slowwalk::run( input::command& command ) const
	{
		const auto& cfg = settings::g_movement;

		if ( !cfg.slowwalk.get( ) || !ui::key_held( cfg.slowwalk_key.get( ) ) || !prediction::g_engine.start( ).on_ground( ) )
		{
			return;
		}

		const auto forward = command.forward_move( );
		const auto left = command.left_move( );
		const auto length = std::hypot( forward, left );
		const auto ratio = static_cast< float >( cfg.slowwalk_speed.get( ) ) / 100.0f;

		if ( length <= ratio )
		{
			return;
		}

		command.set_move( forward * ratio / length, left * ratio / length );
	}

} // namespace opaline::movement

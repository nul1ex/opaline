#include <pch.hpp>
#include <features/movement/movement.hpp>
#include <settings.hpp>

namespace opaline::movement {

	namespace detail {

		constexpr auto k_when_step{ 1.0f / 64.0f };
		constexpr auto k_max_trials{ 6 };

	} // namespace detail

	void bhop::run( input::command& command )
	{
		this->m_active = false;

		if ( !settings::g_movement.bhop.get( ) || !command.holds( sdk::buttons::jump ) || g_jumpbug.active( ) )
		{
			return;
		}

		const auto& start = prediction::g_engine.start( );

		if ( start.move_type == sdk::move_types::ladder || start.move_type == sdk::move_types::noclip )
		{
			this->m_last_on_ground = false;
			return;
		}

		if ( settings::g_movement.jumpbug.get( ) )
		{
			if ( !start.on_ground( ) || this->m_last_on_ground )
			{
				command.strip( sdk::buttons::jump );
				this->m_last_on_ground = false;
				return;
			}

			this->m_last_on_ground = true;
			return;
		}

		command.strip( sdk::buttons::jump );

		auto from{ 0.0f };

		if ( !start.on_ground( ) )
		{
			if ( start.velocity.z > 0.0f )
			{
				return;
			}

			const auto fall = command.predict( );

			if ( !fall.touched_down( start ) )
			{
				return;
			}

			from = fall.landed_since( start ) ? fall.landed_fraction : 0.0f;
		}

		this->m_active = this->press_jump( command, from );
	}

	bool bhop::press_jump( input::command& command, float from ) const
	{
		const auto& start = prediction::g_engine.start( );
		const auto steps = command.step_count( );

		auto when = std::max( detail::k_when_step, std::ceil( from / detail::k_when_step ) * detail::k_when_step );

		for ( auto trial = 0; trial < detail::k_max_trials && when < 1.0f; ++trial, when += detail::k_when_step )
		{
			command.press( sdk::buttons::jump, when );

			if ( command.predict( ).jumped_since( start ) )
			{
				return true;
			}

			command.truncate_steps( steps );
		}

		return false;
	}

} // namespace opaline::movement

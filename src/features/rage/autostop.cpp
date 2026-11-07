#include <pch.hpp>
#include <features/rage/autostop.hpp>
#include <features/movement/movement.hpp>

namespace opaline::rage {

	namespace detail {

		constexpr auto k_settled_speed{ 0.1f };
		constexpr auto k_ground_margin{ 0.99f };
		constexpr auto k_bisect_steps{ 10 };

		static void hold( input::command& command, float target, float forward, float left )
		{
			const auto capped = [ & ]( float scale )
				{
					command.set_move( forward * scale, left * scale );
					return command.predict( ).velocity.length_2d( );
				};

			if ( ( forward == 0.0f && left == 0.0f ) || target <= 0.0f )
			{
				command.set_move( 0.0f, 0.0f );
				return;
			}

			if ( capped( 1.0f ) <= target )
			{
				return;
			}

			auto low{ 0.0f };
			auto high{ 1.0f };

			for ( auto step = 0; step < k_bisect_steps; ++step )
			{
				const auto middle = 0.5f * ( low + high );
				( capped( middle ) > target ? high : low ) = middle;
			}

			if ( capped( low ) > target )
			{
				command.set_move( 0.0f, 0.0f );
			}
		}

		static void brake_ground( input::command& command, float target )
		{
			const auto& start = prediction::g_engine.start( );
			const auto speed = start.velocity.length_2d( );
			const auto forward = command.forward_move( );
			const auto left = command.left_move( );

			if ( speed <= std::max( target, k_settled_speed ) )
			{
				hold( command, target, forward, left );
				return;
			}

			const auto direction_x = start.velocity.x / speed;
			const auto direction_y = start.velocity.y / speed;
			const auto relative = std::atan2( -direction_y, -direction_x ) - command.view_yaw( ) * sdk::k_rad_per_deg;

			const auto after = [ & ]( float scale )
				{
					command.set_move( std::cos( relative ) * scale, std::sin( relative ) * scale );

					const auto velocity = command.predict( ).velocity;
					return velocity.x * direction_x + velocity.y * direction_y;
				};

			if ( after( 0.0f ) <= target )
			{
				hold( command, target, forward, left );
				return;
			}

			if ( after( 1.0f ) >= target )
			{
				return;
			}

			auto low{ 0.0f };
			auto high{ 1.0f };

			for ( auto step = 0; step < k_bisect_steps; ++step )
			{
				const auto middle = 0.5f * ( low + high );
				( after( middle ) > target ? low : high ) = middle;
			}

			command.set_move( std::cos( relative ) * high, std::sin( relative ) * high );
		}

	} // namespace detail

	void autostop::run( input::command& command, float target_speed, bool in_air ) const
	{
		const auto& start = prediction::g_engine.start( );
		if ( start.move_type == sdk::move_types::ladder || start.move_type == sdk::move_types::noclip )
		{
			return;
		}

		if ( !start.on_ground( ) )
		{
			if ( in_air && start.velocity.length_2d( ) > detail::k_settled_speed && !movement::g_jumpbug.active( ) && !movement::g_bhop.active( ) )
			{
				movement::g_autostrafe.brake( command, target_speed );
			}

			return;
		}

		command.strip( sdk::buttons::jump );

		if ( start.velocity.length_2d( ) > detail::k_settled_speed )
		{
			detail::brake_ground( command, target_speed * detail::k_ground_margin );
		}
	}

} // namespace opaline::rage

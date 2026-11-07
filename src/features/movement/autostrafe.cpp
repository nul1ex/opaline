#include <pch.hpp>
#include <features/movement/movement.hpp>
#include <core/game.hpp>
#include <settings.hpp>

namespace opaline::movement {

	namespace detail {

		constexpr auto k_max_subticks{ 32 };
		constexpr auto k_tick_interval{ 1.0f / 64.0f };
		constexpr auto k_strafe_speed{ 10.0f };
		constexpr auto k_stop_epsilon{ 0.01f };
		constexpr auto k_reverse_delta{ 170.0f };
		constexpr auto k_min_wish{ 0.0001f };
		constexpr auto k_crouch_factor{ 0.34f };

		constexpr std::array<std::pair<std::uint64_t, std::uint64_t>, 4> k_key_pairs
		{ {
			{ sdk::buttons::move_left, sdk::buttons::move_right },
			{ sdk::buttons::move_right, sdk::buttons::move_left },
			{ sdk::buttons::forward, sdk::buttons::back },
			{ sdk::buttons::back, sdk::buttons::forward }
		} };

		struct strafe_context
		{
			sdk::vector3 velocity{};
			float seed_forward{};
			float seed_left{};
			float cmd_yaw{};
			float target_yaw{};
			float max_speed{};
			float surface_friction{ 1.0f };
			float fallback_forward{};
			float fallback_left{};
			float air_accelerate{};
			float air_max_wishspeed{};
			float stop_speed{};
			int subticks{ k_max_subticks };
			bool side_switch{};
			bool wants_stop{};
		};

		struct strafe_step
		{
			float when{};
			float forward_delta{};
			float left_delta{};
		};

		struct strafe_result
		{
			std::array<strafe_step, k_max_subticks> steps{};
			int count{};
			bool side_switch{};
		};

		[[nodiscard]] static float stamina_scale( float stamina )
		{
			if ( stamina <= 0.0f )
			{
				return 1.0f;
			}

			const auto scale = std::clamp( 1.0f - stamina / 100.0f, 0.0f, 1.0f );
			return scale * scale;
		}

		[[nodiscard]] static std::optional<float> max_speed( sdk::cs_player_pawn* pawn )
		{
			const auto services = pawn->weapons( );
			const auto weapon = services ? core::entities( )->get<sdk::cs_weapon_base>( services->active_weapon( ) ) : nullptr;
			const auto vdata = weapon ? weapon->vdata<sdk::weapon_vdata>( ) : nullptr;

			if ( !vdata )
			{
				return std::nullopt;
			}

			const auto movement = pawn->movement( );
			auto speed = vdata->max_speed( );

			if ( const auto duck = movement->duck_amount( ); duck > 0.0f )
			{
				speed *= 1.0f - ( 1.0f - k_crouch_factor ) * duck;
			}

			return speed * stamina_scale( movement->stamina( ) );
		}

		[[nodiscard]] static float key_offset( std::uint64_t pressed )
		{
			auto offset{ 0.0f };

			if ( pressed & sdk::buttons::move_left )
			{
				offset += 90.0f;
			}

			if ( pressed & sdk::buttons::move_right )
			{
				offset -= 90.0f;
			}

			if ( pressed & sdk::buttons::forward )
			{
				offset *= 0.5f;
			}
			else if ( pressed & sdk::buttons::back )
			{
				offset = -offset * 0.5f + 180.0f;
			}

			return offset;
		}

		[[nodiscard]] static float strafe_yaw( const strafe_context& ctx, const sdk::vector3& velocity, float speed, float frame_time, bool side_switch )
		{
			const auto accel = ctx.air_accelerate * ctx.max_speed * frame_time * ctx.surface_friction;
			const auto cap = std::min( ctx.max_speed, ctx.air_max_wishspeed );
			const auto cos_theta = std::clamp( std::max( cap - accel, 0.0f ) / speed, 0.0f, 1.0f );
			const auto theta = std::acos( cos_theta );
			const auto gain = std::min( accel, cap - speed * cos_theta );
			const auto turn = gain * std::sin( theta ) / speed * sdk::k_deg_per_rad;

			const auto velocity_yaw = std::atan2( velocity.y, velocity.x ) * sdk::k_deg_per_rad;
			const auto delta = sdk::normalize_yaw( ctx.target_yaw - velocity_yaw );

			const auto counter_clockwise = std::fabs( delta ) > k_reverse_delta || ( std::fabs( delta ) > turn ? delta > 0.0f : !side_switch );
			return velocity_yaw + ( counter_clockwise ? theta : -theta ) * sdk::k_deg_per_rad;
		}

		static void build_strafe( const strafe_context& ctx, strafe_result& out )
		{
			const auto subticks = std::clamp( ctx.subticks, 1, k_max_subticks );
			const auto frame_time = k_tick_interval / static_cast< float >( subticks );

			const auto cmd_yaw = ctx.cmd_yaw * sdk::k_rad_per_deg;
			const auto cmd_forward = sdk::vector3{ std::cos( cmd_yaw ), std::sin( cmd_yaw ), 0.0f };
			const auto cmd_left = sdk::vector3{ -std::sin( cmd_yaw ), std::cos( cmd_yaw ), 0.0f };

			auto velocity = ctx.velocity;
			auto last_forward = ctx.seed_forward;
			auto last_left = ctx.seed_left;
			auto side_switch = ctx.side_switch;

			out.count = 0;

			for ( auto i = 0; i < subticks; ++i )
			{
				auto forward = ctx.fallback_forward;
				auto left = ctx.fallback_left;

				const auto speed = velocity.length_2d( );

				if ( ctx.wants_stop )
				{
					forward = 0.0f;
					left = 0.0f;

					if ( speed > ctx.stop_speed + k_stop_epsilon )
					{
						const auto full = ctx.air_accelerate * ctx.max_speed * frame_time * ctx.surface_friction;
						const auto scale = full > 0.0f ? std::min( ( speed - ctx.stop_speed ) / full, 1.0f ) : 1.0f;
						const auto relative = std::atan2( -velocity.y, -velocity.x ) - cmd_yaw;

						forward = std::cos( relative ) * scale;
						left = std::sin( relative ) * scale;
					}
				}
				else if ( speed >= k_strafe_speed )
				{
					const auto relative = ( strafe_yaw( ctx, velocity, speed, frame_time, side_switch ) - ctx.cmd_yaw ) * sdk::k_rad_per_deg;

					forward = std::cos( relative );
					left = std::sin( relative );
				}

				out.steps[ out.count++ ] = { static_cast< float >( i ) / static_cast< float >( subticks ), forward - last_forward, left - last_left };

				last_forward = forward;
				last_left = left;

				const auto wish = cmd_forward * forward + cmd_left * left;
				const auto wish_length = wish.length_2d( );

				if ( wish_length > k_min_wish )
				{
					const auto wish_speed = std::min( wish_length * ctx.max_speed, ctx.max_speed );
					const auto add_speed = std::min( wish_speed, ctx.air_max_wishspeed ) - ( velocity.x * wish.x + velocity.y * wish.y ) / wish_length;

					if ( add_speed > 0.0f )
					{
						const auto gain = std::min( ctx.air_accelerate * wish_speed * frame_time * ctx.surface_friction, add_speed );

						velocity.x += wish.x / wish_length * gain;
						velocity.y += wish.y / wish_length * gain;
					}
				}

				if ( !ctx.wants_stop )
				{
					side_switch = !side_switch;
				}
			}

			out.side_switch = side_switch;
		}

		[[nodiscard]] static bool should_run( input::command& command )
		{
			const auto& start = prediction::g_engine.start( );

			if ( !settings::g_movement.autostrafe.get( ) || core::g_game.quantize_movement_input->get<bool>( ) )
			{
				return false;
			}

			if ( start.on_ground( ) || start.move_type == sdk::move_types::ladder || start.move_type == sdk::move_types::noclip )
			{
				return false;
			}

			return !command.predict( ).on_ground( );
		}

		static bool apply( input::command& command, std::uint64_t pressed, bool& side_switch, std::optional<float> stop )
		{
			const auto& cfg = settings::g_movement;
			const auto& start = prediction::g_engine.start( );
			const auto pawn = prediction::g_engine.pawn( );
			const auto speed = max_speed( pawn );

			if ( !speed )
			{
				return false;
			}

			const auto stop_on_shift = cfg.autostrafe_stop_on_shift.get( ) && command.holds( sdk::buttons::sprint );
			const auto stop_on_release = cfg.autostrafe_stop_on_release.get( ) && ( pressed & sdk::buttons::movement ) == 0;
			const auto wants_stop = stop.has_value( ) || stop_on_shift || stop_on_release;
			const auto view_yaw = command.view_yaw( );

			strafe_context ctx{};
			ctx.velocity = start.velocity;
			ctx.seed_forward = start.impulses.x;
			ctx.seed_left = start.impulses.y;
			ctx.cmd_yaw = view_yaw;
			ctx.target_yaw = sdk::normalize_yaw( core::view_angles( ).y + ( !wants_stop && cfg.autostrafe_movement_keys.get( ) ? key_offset( pressed ) : 0.0f ) );
			ctx.max_speed = *speed;
			ctx.surface_friction = pawn->movement( )->surface_friction( );
			ctx.fallback_forward = command.forward_move( );
			ctx.fallback_left = command.left_move( );
			ctx.air_accelerate = core::g_game.air_accelerate->get<float>( );
			ctx.air_max_wishspeed = core::g_game.air_max_wishspeed->get<float>( );
			ctx.subticks = std::max( 1, k_max_subticks - command.step_count( ) );
			ctx.side_switch = side_switch;
			ctx.wants_stop = wants_stop;
			ctx.stop_speed = stop.value_or( 0.0f );

			strafe_result result{};
			build_strafe( ctx, result );

			const auto flip = std::cos( command.view_pitch( ) * sdk::k_rad_per_deg ) < 0.0f;

			for ( auto i = 0; i < result.count; ++i )
			{
				const auto& step = result.steps[ static_cast< std::size_t >( i ) ];
				command.add_move( step.when, flip ? -step.forward_delta : step.forward_delta, step.left_delta );
			}

			command.clear_moves( );
			side_switch = result.side_switch;

			return true;
		}

		static void brake_direct( input::command& command, float stop_speed )
		{
			const auto& start = prediction::g_engine.start( );
			const auto pawn = prediction::g_engine.pawn( );
			const auto speed = start.velocity.length_2d( );
			const auto wish_speed = max_speed( pawn );

			if ( speed <= stop_speed || !wish_speed )
			{
				command.set_move( 0.0f, 0.0f );
				return;
			}

			const auto capacity = core::g_game.air_accelerate->get<float>( ) * *wish_speed * pawn->movement( )->surface_friction( ) * k_tick_interval;
			const auto scale = capacity > 0.0f ? std::min( ( speed - stop_speed ) / capacity, 1.0f ) : 1.0f;
			const auto relative = std::atan2( -start.velocity.y, -start.velocity.x ) - command.view_yaw( ) * sdk::k_rad_per_deg;

			command.set_move( std::cos( relative ) * scale, std::sin( relative ) * scale );
		}

	} // namespace detail

	void autostrafe::run( input::command& command )
	{
		this->m_applied = {};

		if ( g_bhop.active( ) || g_jumpbug.active( ) || prediction::g_engine.impulses_reset( ) || !detail::should_run( command ) )
		{
			return;
		}

		const auto buttons = command.user_buttons( );
		const auto pressed = this->tracked_keys( buttons );

		this->m_last_pressed = pressed;
		this->m_last_buttons = buttons;

		const applied before{ true, command.step_count( ), 0, command.forward_move( ), command.left_move( ), this->m_side_switch };

		if ( detail::apply( command, pressed, this->m_side_switch, std::nullopt ) )
		{
			this->m_applied = before;
			this->m_applied.steps_after = command.step_count( );
		}
	}

	void autostrafe::brake( input::command& command, float stop_speed )
	{
		const auto previous = std::exchange( this->m_applied, {} );
		if ( !previous.valid || command.step_count( ) != previous.steps_after )
		{
			detail::brake_direct( command, stop_speed );
			return;
		}

		command.truncate_steps( previous.steps_before );
		command.restore_move( previous.forward, previous.left );
		this->m_side_switch = previous.side_switch;

		detail::apply( command, 0, this->m_side_switch, stop_speed );
	}

	void autostrafe::preview( input::command& command ) const
	{
		if ( !detail::should_run( command ) )
		{
			return;
		}

		auto side_switch = this->m_side_switch;
		detail::apply( command, this->tracked_keys( command.user_buttons( ) ), side_switch, std::nullopt );
	}

	std::uint64_t autostrafe::tracked_keys( std::uint64_t buttons ) const
	{
		auto pressed = this->m_last_pressed;

		for ( const auto& [ button, opposite ] : detail::k_key_pairs )
		{
			if ( ( buttons & button ) && ( !( this->m_last_buttons & button ) || !( pressed & opposite ) ) )
			{
				pressed = ( pressed & ~opposite ) | button;
			}
			else if ( !( buttons & button ) )
			{
				pressed &= ~button;
			}
		}

		return pressed;
	}

} // namespace opaline::movement

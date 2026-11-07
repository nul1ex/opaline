#include <pch.hpp>
#include <features/movement/movement.hpp>
#include <settings.hpp>

namespace opaline::movement {

	namespace detail {

		using state = prediction::engine::state;

		constexpr auto k_when_grid{ 64.0f };
		constexpr auto k_when_step{ 1.0f / k_when_grid };
		constexpr auto k_preduck_ticks{ 3 };
		constexpr auto k_speed_margin{ 0.01f };

		struct jump_slot
		{
			float when{};
			bool landed{};
			float speed{};
		};

		struct first_tick
		{
			std::uint64_t buttons{};
			std::vector<input::button_step> steps{};
			bool strafe{};
		};

		[[nodiscard]] static std::vector<input::button_step> jumpbug_steps( float when, bool jump )
		{
			std::vector<input::button_step> steps{ { 0.0f, sdk::buttons::duck, true }, { when, sdk::buttons::duck, false } };

			if ( jump )
			{
				steps.push_back( { when, sdk::buttons::jump, false } );
				steps.push_back( { when, sdk::buttons::jump, true } );
			}

			return steps;
		}

		[[nodiscard]] static state simulate( input::command& command, const first_tick& first, std::span<const input::future_tick> ahead = {} )
		{
			const auto point = command.save( );
			command.set_buttons( first.buttons );

			if ( first.strafe )
			{
				g_autostrafe.preview( command );
			}

			command.add_buttons( first.steps );

			const auto result = command.predict( ahead );
			command.restore( point );

			return result;
		}

		template <typename simulator>
		[[nodiscard]] static std::optional<jump_slot> best_jumpbug( const state& from, simulator&& run )
		{
			std::optional<jump_slot> best{};

			for ( auto slot = 1; slot < static_cast< int >( k_when_grid ); ++slot )
			{
				const auto when = static_cast< float >( slot ) * k_when_step;
				const auto trial = run( jumpbug_steps( when, true ) );

				if ( trial.on_ground( ) || trial.velocity.z <= 0.0f )
				{
					continue;
				}

				const auto candidate = jump_slot{ when, trial.landed_since( from ), trial.velocity.length( ) };

				if ( !best || ( best->landed && ( !candidate.landed || candidate.speed > best->speed + k_speed_margin ) ) )
				{
					best = candidate;
				}

				if ( !best->landed )
				{
					break;
				}
			}

			return best;
		}

		[[nodiscard]] static std::vector<input::button_step> unduck_landing( input::command& command, const state& start, std::uint64_t buttons, float when, bool recrouch )
		{
			auto steps = jumpbug_steps( when, false );
			const auto recrouch_when = when + k_when_step;

			if ( !recrouch || recrouch_when >= 1.0f )
			{
				return steps;
			}

			auto with_recrouch = steps;
			with_recrouch.push_back( { recrouch_when, sdk::buttons::duck, true } );

			return simulate( command, { buttons, with_recrouch } ).landed_since( start ) ? steps : with_recrouch;
		}

		[[nodiscard]] static bool preduck( input::command& command, const state& start, std::uint64_t buttons )
		{
			const auto ducked = buttons | sdk::buttons::duck;
			const auto press = std::vector{ input::button_step{ 0.0f, sdk::buttons::duck, true } };
			const auto first = first_tick{ ducked, press };

			auto trial = simulate( command, first );

			if ( trial.touched_down( start ) )
			{
				return false;
			}

			std::vector<input::future_tick> ahead{};

			for ( auto tick = 0; tick < k_preduck_ticks; ++tick )
			{
				ahead.push_back( { buttons, jumpbug_steps( k_when_step, true ) } );
				const auto jumped = simulate( command, first, ahead );

				if ( !jumped.on_ground( ) && jumped.velocity.z > 0.0f && !jumped.touched_down( trial ) )
				{
					return true;
				}

				ahead.back( ) = { ducked, press };
				const auto held = simulate( command, first, ahead );

				if ( held.touched_down( trial ) )
				{
					return false;
				}

				trial = held;
			}

			return false;
		}

	} // namespace detail

	void jumpbug::run( input::command& command )
	{
		this->m_active = false;

		const auto& cfg = settings::g_movement;

		if ( !cfg.jumpbug.get( ) )
		{
			return;
		}

		const auto& start = prediction::g_engine.start( );

		if ( start.on_ground( ) || start.move_type != sdk::move_types::walk || start.velocity.z > 0.0f )
		{
			return;
		}

		const auto buttons = command.buttons( );
		const auto wants_jump = ( buttons & sdk::buttons::jump ) != 0;
		const auto duck_held = ( buttons & sdk::buttons::duck ) != 0;

		if ( !wants_jump && duck_held && cfg.jumpbug_keep_crouch.get( ) )
		{
			return;
		}

		const auto hold_duck = start.ducked && !duck_held;
		const auto wait_buttons = hold_duck ? buttons | sdk::buttons::duck : buttons;
		const auto release = std::vector{ input::button_step{ 0.0f, sdk::buttons::duck, false } };
		const auto waited = detail::first_tick{ wait_buttons, {}, true };

		const auto touchdown = [ & ]( ) -> std::optional<float>
			{
				const auto landing = detail::simulate( command, { buttons, release } );
				if ( !landing.touched_down( start ) )
				{
					return std::nullopt;
				}

				return landing.landed_since( start ) ? landing.landed_fraction : 1.0f;
			}( );

		const auto after = detail::simulate( command, waited );
		const auto next_tick = [ & ]( std::vector<input::button_step> steps )
			{
				const std::array ahead{ input::future_tick{ buttons, std::move( steps ) } };
				return detail::simulate( command, waited, ahead );
			};

		const auto after_landed = after.touched_down( start );
		const auto can_land_now = after_landed || touchdown || detail::simulate( command, { wait_buttons } ).touched_down( start );
		const auto can_land_next = !after_landed && ( next_tick( {} ).touched_down( after ) || next_tick( release ).touched_down( after ) );

		if ( !wants_jump )
		{
			if ( !can_land_now )
			{
				return;
			}

			const auto when = std::clamp( touchdown.value_or( 1.0f ), detail::k_when_step, 1.0f - detail::k_when_step );

			command.add_buttons( detail::unduck_landing( command, start, buttons, when, duck_held ) );
			this->m_active = true;
			return;
		}

		const auto now = can_land_now ? detail::best_jumpbug( start, [ & ]( std::vector<input::button_step> steps ) { return detail::simulate( command, { buttons, std::move( steps ) } ); } ) : std::nullopt;
		const auto later = can_land_next ? detail::best_jumpbug( after, next_tick ) : std::nullopt;
		const auto wait = later && ( !now || ( now->landed && !later->landed ) || ( now->landed == later->landed && later->speed > now->speed ) );

		if ( !( now && !now->landed ) && !( later && !later->landed ) && detail::preduck( command, start, buttons ) )
		{
			const auto press = std::array{ input::button_step{ 0.0f, sdk::buttons::duck, true } };

			command.add_buttons( press );
			command.set_buttons( command.buttons( ) | sdk::buttons::duck );
			this->m_active = true;
			return;
		}

		if ( wait || !can_land_now )
		{
			if ( wait && hold_duck )
			{
				command.set_buttons( command.buttons( ) | sdk::buttons::duck );
			}

			return;
		}

		const auto clean = now && !now->landed;
		const auto fallback = touchdown ? *touchdown : now ? now->when : 1.0f;
		const auto when = clean ? now->when : std::clamp( fallback, detail::k_when_step, 1.0f - detail::k_when_step );

		command.add_buttons( detail::jumpbug_steps( when, true ) );
		this->m_active = true;
	}

} // namespace opaline::movement

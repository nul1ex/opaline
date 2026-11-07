#include <pch.hpp>
#include <input/command.hpp>
#include <core/game.hpp>

namespace opaline::input {

	namespace detail {

		constexpr auto k_commit{ 6ull };
		constexpr auto k_max_steps{ 32 };
		constexpr auto k_move_deadzone{ 0.001f };
		constexpr auto k_carry_epsilon{ 0.0001f };
		constexpr auto k_step_fields{ sdk::step_fields::button | sdk::step_fields::pressed | sdk::step_fields::when | sdk::step_fields::analog_forward_delta | sdk::step_fields::analog_left_delta };

		struct step_list
		{
			int allocated_size{};
			std::array<sdk::subtick_move_step*, k_max_steps> elements{};
		};

		[[nodiscard]] static bool moves( const sdk::subtick_move_step* step )
		{
			return ( step->button & sdk::buttons::movement ) != 0 || ( step->button == 0 && ( step->analog_forward_delta != 0.0f || step->analog_left_delta != 0.0f ) );
		}

		static void reset_interpolation( sdk::interpolation_info* info )
		{
			info->fraction = 0.0f;
			info->source_tick = -1;
			info->destination_tick = -1;
			info->has_bits |= sdk::interpolation_fields::fraction | sdk::interpolation_fields::source_tick | sdk::interpolation_fields::destination_tick;
		}

		[[nodiscard]] static bool earlier( const sdk::subtick_move_step* a, const sdk::subtick_move_step* b )
		{
			return a->when < b->when;
		}

		static void write_button( sdk::subtick_move_step* step, const button_step& source )
		{
			step->button = source.button;
			step->pressed = source.pressed;
			step->when = source.when;
			step->has_bits |= k_step_fields;
		}

	} // namespace detail

	command::command( sdk::csgo_input* input, sdk::user_cmd* cmd, const sdk::vector3& impulses ) : m_input( input ), m_cmd( cmd ), m_impulses( impulses ), m_user_buttons( cmd->buttons.value ) {}

	float command::view_pitch( ) const noexcept
	{
		const auto angles = this->m_cmd->pb.base->view_angles;
		return angles ? angles->x : 0.0f;
	}

	float command::view_yaw( ) const noexcept
	{
		const auto angles = this->m_cmd->pb.base->view_angles;
		return angles ? angles->y : 0.0f;
	}

	command::checkpoint command::save( ) const
	{
		return { this->step_count( ), this->forward_move( ), this->left_move( ), this->buttons( ) };
	}

	void command::restore( const checkpoint& point )
	{
		this->truncate_steps( point.steps );

		const auto base = this->m_cmd->pb.base;
		base->forward_move = point.forward;
		base->left_move = point.left;

		this->m_cmd->buttons.value = point.buttons;
	}

	void command::clear_steps( )
	{
		this->m_cmd->pb.base->subtick_moves.current_size = 0;
	}

	void command::truncate_steps( int count )
	{
		auto& moves = this->m_cmd->pb.base->subtick_moves;
		moves.current_size = std::min( moves.current_size, count );
	}

	void command::set_buttons( std::uint64_t value )
	{
		this->m_cmd->buttons.value = value;
	}

	void command::set_view_angles( float pitch, float yaw )
	{
		const auto base = this->m_cmd->pb.base;
		const auto angles = base->view_angles;

		if ( !angles )
		{
			return;
		}

		angles->x = pitch;
		angles->y = yaw;
		angles->has_bits |= sdk::qangle_fields::x | sdk::qangle_fields::y;
		base->has_bits |= sdk::base_fields::view_angles;
	}

	void command::turn( float pitch, float yaw )
	{
		const auto base = this->m_cmd->pb.base;
		const auto angles = base->view_angles;

		if ( !angles )
		{
			return;
		}

		const auto old_pitch = angles->x;
		const auto old_yaw = angles->y;

		this->set_view_angles( pitch, yaw );

		const auto flip = ( std::cos( old_pitch * sdk::k_rad_per_deg ) < 0.0f ) != ( std::cos( pitch * sdk::k_rad_per_deg ) < 0.0f );
		const auto delta = ( yaw - old_yaw ) * sdk::k_rad_per_deg;
		const auto cosine = std::cos( delta );
		const auto sine = std::sin( delta );

		const auto rotate = [ & ]( float forward, float left )
			{
				const auto turned = forward * cosine + left * sine;
				return std::pair{ flip ? -turned : turned, left * cosine - forward * sine };
			};

		const auto [ forward, left ] = rotate( base->forward_move, base->left_move );
		auto& moves = base->subtick_moves;

		if ( moves.current_size <= 0 || !moves.data )
		{
			this->set_move( std::clamp( forward, -1.0f, 1.0f ), std::clamp( left, -1.0f, 1.0f ) );
			return;
		}

		this->restore_move( std::clamp( forward, -1.0f, 1.0f ), std::clamp( left, -1.0f, 1.0f ) );

		sdk::subtick_move_step* start{};

		for ( auto index = 0; index < moves.current_size; ++index )
		{
			const auto step = moves.data->elements[ index ];
			if ( step->button != 0 )
			{
				continue;
			}

			if ( !start && step->when <= 0.0f )
			{
				start = step;
			}

			const auto [ step_forward, step_left ] = rotate( step->analog_forward_delta, step->analog_left_delta );
			step->analog_forward_delta = step_forward;
			step->analog_left_delta = step_left;
		}

		const auto [ seed_forward, seed_left ] = rotate( this->m_impulses.x, this->m_impulses.y );
		const auto carry_forward = seed_forward - this->m_impulses.x;
		const auto carry_left = seed_left - this->m_impulses.y;

		if ( std::fabs( carry_forward ) < detail::k_carry_epsilon && std::fabs( carry_left ) < detail::k_carry_epsilon )
		{
			return;
		}

		if ( !start )
		{
			start = this->add_step( );
		}

		if ( start )
		{
			start->analog_forward_delta += carry_forward;
			start->analog_left_delta += carry_left;
			start->has_bits |= detail::k_step_fields;
		}
	}

	void command::strip( std::uint64_t button )
	{
		auto& buttons = this->m_cmd->buttons;
		buttons.value &= ~button;
		buttons.value_changed &= ~button;
		buttons.value_scroll &= ~button;

		const auto base = this->m_cmd->pb.base;
		if ( base->buttons )
		{
			for ( auto& state : base->buttons->states )
			{
				state &= ~button;
			}
		}

		auto& moves = base->subtick_moves;
		if ( !moves.data )
		{
			return;
		}

		const auto first = moves.data->elements;
		const auto kept = std::stable_partition( first, first + moves.current_size, [ button ]( const sdk::subtick_move_step* step ) { return ( step->button & button ) == 0; } );
		moves.current_size = static_cast< int >( kept - first );
	}

	void command::press( std::uint64_t button, float when )
	{
		const std::array steps{ button_step{ when, button, false }, button_step{ when, button, true } };
		this->add_buttons( steps );
	}

	void command::add_buttons( std::span<const button_step> steps )
	{
		for ( const auto& source : steps )
		{
			if ( const auto step = this->add_step( ) )
			{
				detail::write_button( step, source );
			}
		}
	}

	void command::add_move( float when, float forward_delta, float left_delta )
	{
		if ( const auto step = this->add_step( ) )
		{
			step->when = when;
			step->analog_forward_delta = forward_delta;
			step->analog_left_delta = left_delta;
			step->has_bits |= detail::k_step_fields;
		}
	}

	void command::clear_moves( )
	{
		const auto base = this->m_cmd->pb.base;
		base->forward_move = 0.0f;
		base->left_move = 0.0f;
		base->has_bits |= sdk::base_fields::forward_move | sdk::base_fields::left_move;
	}

	void command::restore_move( float forward, float left )
	{
		const auto base = this->m_cmd->pb.base;
		base->forward_move = forward;
		base->left_move = left;
		base->has_bits |= sdk::base_fields::forward_move | sdk::base_fields::left_move;
	}

	void command::set_move( float forward, float left )
	{
		const auto base = this->m_cmd->pb.base;
		base->forward_move = forward;
		base->left_move = left;
		base->has_bits |= sdk::base_fields::forward_move | sdk::base_fields::left_move;

		auto& value = this->m_cmd->buttons.value;
		value &= ~sdk::buttons::movement;

		if ( forward > detail::k_move_deadzone )
		{
			value |= sdk::buttons::forward;
		}
		else if ( forward < -detail::k_move_deadzone )
		{
			value |= sdk::buttons::back;
		}

		if ( left > detail::k_move_deadzone )
		{
			value |= sdk::buttons::move_left;
		}
		else if ( left < -detail::k_move_deadzone )
		{
			value |= sdk::buttons::move_right;
		}
	}

	template <typename callback>
	auto command::synced( callback&& run )
	{
		const auto count = this->step_count( );

		this->sync_moves( );

		const auto synced = this->step_count( );
		const auto& moves = this->m_cmd->pb.base->subtick_moves;
		const auto order = moves.data ? std::vector<sdk::subtick_move_step*>( moves.data->elements, moves.data->elements + synced ) : std::vector<sdk::subtick_move_step*>{};

		this->sort_steps( );

		const auto result = run( synced );

		if ( moves.data )
		{
			std::ranges::copy( order, moves.data->elements );
		}

		this->truncate_steps( count );

		return result;
	}

	prediction::engine::state command::predict( std::span<const future_tick> ahead )
	{
		return this->synced( [ & ]( int sorted_steps )
			{
				std::vector<sdk::user_cmd> ticks{ *this->m_cmd };
				std::vector<sdk::base_user_cmd> bases( ahead.size( ), *this->m_cmd->pb.base );
				std::vector<detail::step_list> lists( ahead.size( ) );

				ticks.reserve( ahead.size( ) + 1 );

				auto previous = this->buttons( );

				for ( std::size_t index = 0; index < ahead.size( ); ++index )
				{
					const auto& tick = ahead[ index ];
					auto& list = lists[ index ];

					for ( const auto& source : tick.steps )
					{
						const auto step = list.allocated_size < detail::k_max_steps ? this->append_step( ) : nullptr;
						if ( !step )
						{
							break;
						}

						detail::write_button( step, source );
						list.elements[ static_cast< std::size_t >( list.allocated_size++ ) ] = step;
					}

					std::stable_sort( list.elements.begin( ), list.elements.begin( ) + list.allocated_size, detail::earlier );

					auto& future = bases[ index ].subtick_moves;
					future.current_size = list.allocated_size;
					future.total_size = static_cast< int >( list.elements.size( ) );
					future.data = reinterpret_cast< sdk::repeated_ptr_field<sdk::subtick_move_step>::rep* >( &list );

					auto& next = ticks.emplace_back( *this->m_cmd );
					next.command_number += static_cast< std::int64_t >( index + 1 );
					next.pb.base = &bases[ index ];
					next.buttons.value = tick.buttons;
					next.buttons.value_changed = tick.buttons ^ previous;
					next.buttons.value_scroll = 0;

					previous = tick.buttons;
				}

				this->truncate_steps( sorted_steps );

				return prediction::g_engine.predict( ticks );
			} );
	}

	float command::predict_inaccuracy( std::optional<sdk::vector3> velocity )
	{
		return this->synced( [ this, velocity ]( int ) { return prediction::g_engine.predict_inaccuracy( std::span<const sdk::user_cmd>( this->m_cmd, 1 ), velocity ); } );
	}

	sdk::vector3 command::predict_shot_eye( double label )
	{
		return this->synced( [ this, label ]( int ) { return prediction::g_engine.predict_shot_eye( std::span<const sdk::user_cmd>( this->m_cmd, 1 ), label ); } );
	}

	bool command::shoot( const shot& info )
	{
		auto& pb = this->m_cmd->pb;
		const auto& history = pb.input_history;

		if ( history.current_size <= 0 || !history.data || !history.data->elements[ 0 ] )
		{
			return false;
		}

		const auto entry = history.data->elements[ 0 ];

		if ( const auto view = entry->view_angles )
		{
			view->x = info.angles.x;
			view->y = info.angles.y;
			view->has_bits |= sdk::qangle_fields::x | sdk::qangle_fields::y;
			entry->has_bits |= sdk::history_fields::view_angles;
		}

		entry->render_tick_count = info.render_tick;
		entry->render_tick_fraction = 0.0f;
		entry->player_tick_count = info.player_tick;
		entry->player_tick_fraction = 0.0f;
		entry->has_bits |= sdk::history_fields::render_tick_count | sdk::history_fields::render_tick_fraction | sdk::history_fields::player_tick_count | sdk::history_fields::player_tick_fraction;

		if ( ( entry->has_bits & sdk::history_fields::sv_interp0 ) && entry->sv_interp0 )
		{
			detail::reset_interpolation( entry->sv_interp0 );
		}

		if ( ( entry->has_bits & sdk::history_fields::sv_interp1 ) && entry->sv_interp1 )
		{
			detail::reset_interpolation( entry->sv_interp1 );
		}

		if ( ( entry->has_bits & sdk::history_fields::cl_interp ) && entry->cl_interp )
		{
			entry->cl_interp->fraction = 0.0f;
			entry->cl_interp->has_bits |= sdk::interpolation_fields::fraction;
		}

		this->m_cmd->buttons.value |= sdk::buttons::attack;
		this->m_cmd->buttons.value_changed |= sdk::buttons::attack;

		pb.attack1_start_history_index = 0;
		pb.has_bits |= sdk::csgo_fields::attack1_start_history_index;

		return true;
	}

	void command::commit( )
	{
		this->sync_moves( );
		this->sort_steps( );

		sdk::vfunc<detail::k_commit>( this->m_input, this->m_cmd );
	}

	sdk::subtick_move_step* command::add_step( )
	{
		return this->step_count( ) < detail::k_max_steps ? this->append_step( ) : nullptr;
	}

	sdk::subtick_move_step* command::append_step( )
	{
		using create_step_fn = sdk::subtick_move_step*( __fastcall* )( void* );
		using add_allocated_fn = void( __fastcall* )( void*, void* );

		auto& moves = this->m_cmd->pb.base->subtick_moves;

		if ( moves.data && moves.current_size < moves.data->allocated_size )
		{
			const auto step = moves.data->elements[ moves.current_size++ ];

			step->has_bits = 0;
			step->cached_size = 0;
			step->button = 0;
			step->pressed = false;
			step->when = 0.0f;
			step->analog_forward_delta = 0.0f;
			step->analog_left_delta = 0.0f;
			step->pitch_delta = 0.0f;
			step->yaw_delta = 0.0f;

			return step;
		}

		const auto step = reinterpret_cast< create_step_fn >( core::g_game.create_subtick_move_step )( moves.arena );
		if ( step )
		{
			reinterpret_cast< add_allocated_fn >( core::g_game.add_allocated )( &moves, step );
		}

		return step;
	}

	void command::sort_steps( )
	{
		auto& moves = this->m_cmd->pb.base->subtick_moves;

		if ( moves.data && moves.current_size > 1 )
		{
			std::stable_sort( moves.data->elements, moves.data->elements + moves.current_size, detail::earlier );
		}
	}

	void command::sync_moves( )
	{
		auto& moves = this->m_cmd->pb.base->subtick_moves;

		if ( moves.current_size <= 0 || !moves.data || std::any_of( moves.data->elements, moves.data->elements + moves.current_size, detail::moves ) )
		{
			return;
		}

		const auto forward = this->forward_move( ) - this->m_impulses.x;
		const auto left = this->left_move( ) - this->m_impulses.y;

		if ( forward == 0.0f && left == 0.0f )
		{
			return;
		}

		if ( const auto step = this->add_step( ) )
		{
			step->analog_forward_delta = forward;
			step->analog_left_delta = left;
			step->has_bits |= detail::k_step_fields;
		}
	}

} // namespace opaline::input

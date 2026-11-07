#include <pch.hpp>
#include <prediction/engine.hpp>
#include <core/game.hpp>
#include <core/log.hpp>

namespace opaline::prediction {

	namespace detail {

		namespace client = sdk::offsets::client;

		constexpr auto k_tick_interval{ 1.0f / 64.0f };
		constexpr auto k_view_height{ 64.0f };

		constexpr auto k_on_ground{ 1u << 0 };

		constexpr auto k_global_vars_size{ 0x60ull };
		constexpr auto k_node_to_world_size{ 0x20ull };

		class backup
		{
		public:
			backup( ) = default;
			~backup( ) { this->restore( ); }

			backup( const backup& ) = delete;
			backup& operator=( const backup& ) = delete;

			void save( void* object, std::uintptr_t offset, std::size_t size )
			{
				const auto address = static_cast< std::uint8_t* >( object ) + offset;

				this->m_entries.push_back( { address, size, this->m_data.size( ) } );
				this->m_data.insert( this->m_data.end( ), address, address + size );
			}

			template <typename type>
			void save( void* object, std::uintptr_t offset )
			{
				this->save( object, offset, sizeof( type ) );
			}

			template <typename type>
			void save( type& value )
			{
				this->save( &value, 0, sizeof( type ) );
			}

			void save_range( void* object, std::uintptr_t first, std::uintptr_t last )
			{
				this->save( object, first, last - first );
			}

		private:
			struct entry
			{
				std::uint8_t* address;
				std::size_t size;
				std::size_t data;
			};

			void restore( )
			{
				for ( auto it = this->m_entries.rbegin( ); it != this->m_entries.rend( ); ++it )
				{
					std::memcpy( it->address, this->m_data.data( ) + it->data, it->size );
				}
			}

			std::vector<entry> m_entries{};
			std::vector<std::uint8_t> m_data{};
		};

		static void save_weapon( backup& out, sdk::cs_weapon_base* weapon )
		{
			out.save<float>( weapon, client::c_csweaponbase::m_flNextClientFireBulletTime );
			out.save<float>( weapon, client::c_csweaponbase::m_flNextClientFireBulletTime_Repredict );
			out.save_range( weapon, client::c_csweaponbase::m_weaponMode, client::c_csweaponbase::m_flRecoilIndex + sizeof( float ) );
			out.save_range( weapon, client::c_csweaponbase::m_nPostponeFireReadyTicks, client::c_csweaponbase::m_bIsHauledBack + sizeof( bool ) );
			out.save<float>( weapon, client::c_csweaponbase::m_fLastShotTime );
			out.save<float>( weapon, client::c_csweaponbase::m_flNextAttackRenderTimeOffset );
			out.save<float>( weapon, client::c_csweaponbase::m_flWatTickOffset );
			out.save<std::int16_t>( weapon, client::c_csweaponbase::m_iWeaponGameplayAnimState );
			out.save<float>( weapon, client::c_csweaponbase::m_flWeaponGameplayAnimStateTimestamp );
			out.save<bool>( weapon, client::c_csweaponbase::m_bInReload );

			out.save<int>( weapon, client::c_baseplayerweapon::m_nNextPrimaryAttackTick );
			out.save<float>( weapon, client::c_baseplayerweapon::m_flNextPrimaryAttackTickRatio );
			out.save<int>( weapon, client::c_baseplayerweapon::m_nNextSecondaryAttackTick );
			out.save<float>( weapon, client::c_baseplayerweapon::m_flNextSecondaryAttackTickRatio );
			out.save<int>( weapon, client::c_baseplayerweapon::m_iClip1 );
			out.save<int>( weapon, client::c_baseplayerweapon::m_iClip2 );
			out.save( weapon, client::c_baseplayerweapon::m_pReserveAmmo, sizeof( int ) * 2 );

			const auto vdata = weapon->vdata<sdk::weapon_vdata>( );

			if ( vdata && vdata->type( ) == sdk::weapon_type::grenade )
			{
				out.save<bool>( weapon, client::c_basecsgrenade::m_bClientPredictDelete );
				out.save<bool>( weapon, client::c_basecsgrenade::m_bRedraw );
				out.save<bool>( weapon, client::c_basecsgrenade::m_bIsHeldByPlayer );
				out.save<bool>( weapon, client::c_basecsgrenade::m_bPinPulled );
				out.save<bool>( weapon, client::c_basecsgrenade::m_bJumpThrow );
				out.save<bool>( weapon, client::c_basecsgrenade::m_bThrowAnimating );
				out.save<float>( weapon, client::c_basecsgrenade::m_fThrowTime );
				out.save<float>( weapon, client::c_basecsgrenade::m_flThrowStrength );
				out.save<float>( weapon, client::c_basecsgrenade::m_fDropTime );
				out.save<float>( weapon, client::c_basecsgrenade::m_fPinPullTime );
				out.save<bool>( weapon, client::c_basecsgrenade::m_bJustPulledPin );
				out.save<int>( weapon, client::c_basecsgrenade::m_nNextHoldTick );
				out.save<float>( weapon, client::c_basecsgrenade::m_flNextHoldFrac );
				out.save<std::uint32_t>( weapon, client::c_basecsgrenade::m_hSwitchToWeaponAfterThrow );
			}
			else
			{
				out.save<int>( weapon, client::c_csweaponbasegun::m_zoomLevel );
				out.save<int>( weapon, client::c_csweaponbasegun::m_iBurstShotsRemaining );
			}
		}

		static void save_state( backup& out, sdk::cs_player_controller* controller, sdk::cs_player_pawn* pawn, sdk::movement_services* movement, sdk::game_scene_node* scene_node, sdk::global_vars* globals )
		{
			out.save( globals, 0, k_global_vars_size );
			out.save<std::uint32_t>( core::g_game.prediction_seed, 0 );
			out.save<void*>( core::g_game.simulation_player, 0 );
			out.save<void*>( core::g_game.prediction_player, 0 );
			out.save<std::int32_t>( core::g_game.prediction_phase, 0 );
			out.save( core::g_game.client_prediction->state( ) );

			out.save<int>( controller, client::cbaseplayercontroller::m_nTickBase );

			out.save<std::uint32_t>( pawn, client::c_baseentity::m_fFlags );
			out.save<sdk::vector3>( pawn, client::c_baseentity::m_vecAbsVelocity );
			out.save<sdk::network_vector>( pawn, client::c_baseentity::m_vecVelocity );
			out.save<sdk::vector3>( pawn, client::c_baseentity::m_vecBaseVelocity );
			out.save_range( pawn, client::c_baseentity::m_flWaterLevel, client::c_baseentity::m_nGroundBodyIndex + sizeof( int ) );
			out.save<sdk::network_vector>( pawn, client::c_basemodelentity::m_vecViewOffset );

			out.save<bool>( pawn, client::c_csplayerpawn::m_bInLanding );
			out.save<float>( pawn, client::c_csplayerpawn::m_lastLandTime );
			out.save<bool>( pawn, client::c_csplayerpawn::m_bOnGroundLastTick );
			out.save<bool>( pawn, client::c_csplayerpawn::m_bIsScoped );
			out.save<bool>( pawn, client::c_csplayerpawn::m_bOldIsScoped );
			out.save<float>( pawn, client::c_csplayerpawn::m_flEmitSoundTime );
			out.save<int>( pawn, client::c_csplayerpawn::m_iShotsFired );
			out.save<float>( pawn, client::c_csplayerpawn::m_grenadeParameterStashTime );
			out.save<bool>( pawn, client::c_csplayerpawn::m_bGrenadeParametersStashed );
			out.save_range( pawn, client::c_csplayerpawn::m_angStashedShootAngles, client::c_csplayerpawn::m_vecStashedVelocity + sizeof( sdk::vector3 ) );
			out.save<sdk::vector3>( pawn, client::c_csplayerpawn::m_angEyeAngles );
			out.save_range( pawn, client::c_csplayerpawn::m_arrOldEyeAnglesTimes, client::c_csplayerpawn::m_angEyeAnglesVelocity + sizeof( sdk::vector3 ) );
			out.save_range( pawn, client::c_csplayerpawn::m_aimPunchAngle, client::c_csplayerpawn::m_aimPunchTickFraction + sizeof( float ) );

			out.save( scene_node, client::cgamescenenode::m_nodeToWorld, k_node_to_world_size );
			out.save_range( scene_node, client::cgamescenenode::m_vecOrigin, client::cgamescenenode::m_nParentAttachmentOrBone );

			out.save_range( movement, client::cplayer_movementservices::m_nImpulse, client::cplayer_movementservices_humanoid::m_flStepSoundTime );
			out.save_range( movement, client::cplayer_movementservices_humanoid::m_flStepSoundTime, client::ccsplayer_movementservices::m_vecLadderNormal );
			out.save_range( movement, client::ccsplayer_movementservices::m_vecLadderNormal, client::ccsplayer_movementservices::m_bInStuckTest + sizeof( bool ) );
			out.save_range( movement, client::ccsplayer_movementservices::m_nTraceCount, client::ccsplayer_movementservices::m_bWasSurfing + sizeof( bool ) );
			out.save<sdk::vector3>( movement, client::ccsplayer_movementservices::m_vecInputRotated );

			if ( const auto weapons = pawn->weapons( ) )
			{
				out.save<float>( weapons, client::ccsplayer_weaponservices::m_flNextAttack );
				out.save<std::uint32_t>( weapons, client::ccsplayer_weaponservices::m_nOldTotalShootPositionHistoryCount );
				out.save<std::uint32_t>( weapons, client::ccsplayer_weaponservices::m_nOldTotalInputHistoryCount );
				out.save( weapons->shot_eyes( ) );
				out.save( weapons->shot_eye_tail( ) );
				out.save( weapons->shot_eye_count( ) );

				if ( const auto weapon = core::entities( )->get<sdk::cs_weapon_base>( weapons->active_weapon( ) ) )
				{
					save_weapon( out, weapon );
				}
			}

			if ( const auto camera = pawn->camera( ) )
			{
				out.save_range( camera, client::ccsplayerbase_cameraservices::m_iFOV, client::ccsplayerbase_cameraservices::m_hZoomOwner + sizeof( std::uint32_t ) );
			}
		}

		[[nodiscard]] static sdk::move_data* run_command( sdk::movement_services* movement, sdk::cs_player_controller* controller, sdk::global_vars* globals, sdk::user_cmd& cmd )
		{
			using subtick_loop_fn = void( __fastcall* )( sdk::movement_services*, sdk::user_cmd*, sdk::move_data* );

			const auto tick = ++controller->tick_base( );

			movement->held_snapshot( ) = movement->held_buttons( );
			movement->toggle_snapshot( ) = movement->toggle_buttons( );

			globals->current_time( ) = static_cast< float >( tick ) * k_tick_interval;
			globals->frame_time( ) = k_tick_interval;
			globals->tick_count( ) = tick;
			globals->tick_fraction( ) = 0.0f;

			movement->update_input_state( &cmd );

			const auto data = movement->move_data( );
			if ( !data )
			{
				return nullptr;
			}

			data->flags( ) &= static_cast< std::uint8_t >( ~1u );
			data->previous_tick( ) = tick - 1;
			data->tick( ) = tick;
			data->tick_offset( ) = 0;
			data->tick_scale( ) = 1.0f;

			movement->setup_move( &cmd, data );

			movement->tick_presses( ) = 0;
			reinterpret_cast< subtick_loop_fn >( core::g_game.subtick_loop )( movement, &cmd, data );
			movement->tick_presses_final( ) = movement->tick_presses( );

			return data;
		}

		static void finish_move( sdk::cs_player_pawn* pawn, sdk::move_data* data )
		{
			const auto origin = data->origin( );
			const auto scene_node = pawn->scene_node( );

			scene_node->origin( ) = origin;
			scene_node->abs_origin( ) = origin;
			scene_node->transform_position( ) = origin;

			pawn->velocity( ) = data->velocity( );
			pawn->network_velocity( ).value = data->velocity( );
			pawn->movement( )->last_movement_impulses( ) = data->impulses( );
		}

		[[nodiscard]] static sdk::prediction_slot* find_network_slot( sdk::prediction_system* system, sdk::cs_player_controller* controller )
		{
			const auto slots = system->slots( );
			if ( !slots )
			{
				return nullptr;
			}

			for ( auto index = 0; index < system->slot_count( ); ++index )
			{
				if ( slots[ index ].controller == controller )
				{
					return &slots[ index ];
				}
			}

			return nullptr;
		}

		[[nodiscard]] static int stored_frames( sdk::cs_player_controller* controller )
		{
			const auto data = controller->prediction_data( );
			return data ? data->stored_frames( ) : 0;
		}

		constexpr auto k_shot_ring_size{ static_cast< int >( std::tuple_size_v<sdk::shot_eye_ring> ) };

		[[nodiscard]] static double shot_label( const sdk::shot_eye& entry )
		{
			return static_cast< double >( entry.tick ) + static_cast< double >( entry.fraction );
		}

		[[nodiscard]] static bool ring_valid( const shot_history& ring )
		{
			return ring.count > 0 && ring.count <= k_shot_ring_size && ring.tail >= 0 && ring.tail < k_shot_ring_size;
		}

		[[nodiscard]] static sdk::shot_eye& ring_at( shot_history& ring, int index )
		{
			return ring.entries[ static_cast< std::size_t >( ( ring.tail + index ) % k_shot_ring_size ) ];
		}

		[[nodiscard]] static const sdk::shot_eye& ring_at( const shot_history& ring, int index )
		{
			return ring.entries[ static_cast< std::size_t >( ( ring.tail + index ) % k_shot_ring_size ) ];
		}

		[[nodiscard]] static double newest_label( const shot_history& ring )
		{
			return ring_valid( ring ) ? shot_label( ring_at( ring, ring.count - 1 ) ) : 0.0;
		}

		[[nodiscard]] static shot_history live_ring( sdk::cs_player_pawn* pawn )
		{
			const auto services = pawn ? pawn->weapons( ) : nullptr;
			if ( !services )
			{
				return {};
			}

			return { services->shot_eyes( ), services->shot_eye_tail( ), services->shot_eye_count( ) };
		}

		static void append( shot_history& ring, const sdk::shot_eye& entry )
		{
			if ( !ring_valid( ring ) )
			{
				ring = {};
				ring.entries[ 0 ] = entry;
				ring.count = 1;
				return;
			}

			auto& newest = ring_at( ring, ring.count - 1 );
			if ( newest.tick == entry.tick && newest.fraction == entry.fraction )
			{
				newest = entry;
				return;
			}

			if ( ring.count == k_shot_ring_size )
			{
				ring.entries[ static_cast< std::size_t >( ring.tail ) ] = entry;
				ring.tail = ( ring.tail + 1 ) % k_shot_ring_size;
				return;
			}

			ring_at( ring, ring.count ) = entry;
			++ring.count;
		}

		static void append_written( shot_history& ring, const shot_history& before, const shot_history& after )
		{
			if ( !ring_valid( after ) )
			{
				return;
			}

			const auto known = newest_label( before );

			for ( auto index = 0; index < after.count; ++index )
			{
				if ( const auto& entry = ring_at( after, index ); shot_label( entry ) > known )
				{
					append( ring, entry );
				}
			}
		}

		[[nodiscard]] static engine::state current_state( sdk::cs_player_pawn* pawn )
		{
			const auto movement = pawn->movement( );

			engine::state out{};
			out.flags = pawn->flags( );
			out.move_type = pawn->move_type( );
			out.ducked = movement->ducked( );
			out.velocity = pawn->velocity( );
			out.origin = pawn->scene_node( )->origin( );
			out.eye = out.origin + pawn->view_offset( ).value;
			out.impulses = movement->last_movement_impulses( );
			out.jump_tick = movement->last_jump_tick( );
			out.jump_fraction = movement->last_jump_fraction( );
			out.landed_tick = movement->last_landed_tick( );
			out.landed_fraction = movement->last_landed_fraction( );

			return out;
		}

		[[nodiscard]] static engine::state predicted_state( sdk::cs_player_pawn* pawn, sdk::move_data* data )
		{
			auto out = current_state( pawn );

			if ( data )
			{
				out.origin = data->origin( );
				out.velocity = data->velocity( );
				out.impulses = data->impulses( );
			}

			const auto view = pawn->view_offset( ).value;
			out.eye = out.origin + sdk::vector3{ view.x, view.y, k_view_height + pawn->movement( )->duck_offset( ) - pawn->slope_drop_offset( ) };

			return out;
		}

		[[nodiscard]] static sdk::vector3 serve( const shot_history& history, double label )
		{
			if ( history.count < 2 || !ring_valid( history ) )
			{
				return history.uninterpolated;
			}

			for ( auto index = 0; index + 1 < history.count; ++index )
			{
				const auto& older = ring_at( history, index );
				const auto from = shot_label( older );
				if ( from > label )
				{
					return history.uninterpolated;
				}

				const auto& newer = ring_at( history, index + 1 );
				const auto to = shot_label( newer );
				if ( to < label )
				{
					continue;
				}

				const auto fraction = to > from ? static_cast< float >( ( label - from ) / ( to - from ) ) : 1.0f;
				return older.position + ( newer.position - older.position ) * fraction;
			}

			return history.uninterpolated;
		}

	} // namespace detail

	bool engine::begin( sdk::cs_player_controller* controller, sdk::cs_player_pawn* pawn, std::int64_t command_number )
	{
		this->m_controller = nullptr;
		this->m_pawn = nullptr;

		if ( !pawn->movement( ) || !pawn->scene_node( ) )
		{
			return false;
		}

		this->reset_impulses( pawn );
		this->record_input( pawn, command_number - 1 );

		this->m_controller = controller;
		this->m_pawn = pawn;
		this->m_start = detail::current_state( pawn );

		return true;
	}

	void engine::before_network_update( sdk::prediction_system* system )
	{
		const auto controller = core::local_controller( );

		this->m_network_slot = controller ? detail::find_network_slot( system, controller ) : nullptr;
		this->m_stored_frames = this->m_network_slot ? detail::stored_frames( controller ) : 0;
	}

	void engine::after_network_update( )
	{
		const auto controller = core::local_controller( );

		if ( !this->m_network_slot || this->m_stored_frames <= 0 || !controller || detail::stored_frames( controller ) != 0 )
		{
			return;
		}

		const auto last_acked = this->m_network_slot->last_acked_command;
		const auto current = core::current_user_cmd( controller );

		if ( !current || current->command_number == last_acked )
		{
			return;
		}

		const auto pawn = core::local_pawn( controller );
		const auto& record = this->m_inputs[ static_cast< std::size_t >( last_acked ) % this->m_inputs.size( ) ];

		if ( pawn && pawn->movement( ) && record.command_number == last_acked )
		{
			pawn->movement( )->held_buttons( ) = record.buttons;
		}

		const auto acked = core::user_cmd( controller, last_acked );

		if ( acked && acked->command_number == last_acked && acked->pb.base && acked->pb.base->subtick_moves.current_size > 0 )
		{
			this->m_impulse_reset_pending = true;
		}
	}

	void engine::reset_impulses( sdk::cs_player_pawn* pawn )
	{
		this->m_impulses_reset = std::exchange( this->m_impulse_reset_pending, false ) && !( pawn->flags( ) & detail::k_on_ground );

		if ( this->m_impulses_reset )
		{
			pawn->movement( )->last_movement_impulses( ) = {};
		}
	}

	void engine::record_input( sdk::cs_player_pawn* pawn, std::int64_t command_number )
	{
		if ( command_number <= 0 )
		{
			return;
		}

		auto& record = this->m_inputs[ static_cast< std::size_t >( command_number ) % this->m_inputs.size( ) ];
		record.command_number = command_number;
		record.buttons = pawn->movement( )->held_buttons( );
	}

	template <typename callback>
	auto engine::simulate( std::span<const sdk::user_cmd> ticks, callback&& read )
	{
		const auto controller = this->m_controller;
		const auto pawn = this->m_pawn;
		const auto movement = pawn->movement( );
		const auto scene_node = pawn->scene_node( );
		const auto globals = core::globals( );

		detail::backup backup{};
		detail::save_state( backup, controller, pawn, movement, scene_node, globals );

		scene_node->abs_origin( ) = scene_node->origin( );
		scene_node->transform_position( ) = scene_node->origin( );

		*core::g_game.simulation_player = pawn;
		*core::g_game.prediction_player = pawn;

		this->m_simulating = true;

		sdk::move_data* data{};

		for ( const auto& cmd : ticks )
		{
			if ( data )
			{
				detail::finish_move( pawn, data );
			}

			auto command = cmd;
			command.buttons.value &= ~( sdk::buttons::attack | sdk::buttons::attack2 | sdk::buttons::reload | sdk::buttons::use );
			command.unknown_88 = 0;

			data = detail::run_command( movement, controller, globals, command );

			if ( !data )
			{
				break;
			}
		}

		this->m_simulating = false;

		return read( pawn, data );
	}

	engine::state engine::predict( std::span<const sdk::user_cmd> ticks )
	{
		return this->simulate( ticks, [ ]( sdk::cs_player_pawn* pawn, sdk::move_data* data ) { return detail::predicted_state( pawn, data ); } );
	}

	sdk::vector3 engine::predict_shot_eye( std::span<const sdk::user_cmd> ticks, double label )
	{
		return detail::serve( this->predict_shot_history( ticks ), label );
	}

	shot_history engine::predict_shot_history( std::span<const sdk::user_cmd> ticks )
	{
		const auto live = detail::live_ring( this->m_pawn );
		const auto expected = static_cast< double >( this->m_controller->tick_base( ) );

		const auto live_complete = detail::newest_label( live ) >= expected;
		auto out = !live_complete && this->m_server_ring_valid && detail::newest_label( this->m_server_ring ) == expected ? this->m_server_ring : live;
		const auto after = this->simulate_shot_history( ticks );

		detail::append_written( out, live, after );
		out.uninterpolated = after.uninterpolated;

		return out;
	}

	void engine::commit_shot_history( std::span<const sdk::user_cmd> ticks )
	{
		if ( !this->m_pawn || !this->m_controller )
		{
			return;
		}

		this->m_server_ring = this->predict_shot_history( ticks );
		this->m_server_ring_valid = detail::ring_valid( this->m_server_ring );
	}

	shot_history engine::simulate_shot_history( std::span<const sdk::user_cmd> ticks )
	{
		return this->simulate( ticks, [ ]( sdk::cs_player_pawn* pawn, sdk::move_data* data )
			{
				auto out = detail::live_ring( pawn );
				out.uninterpolated = detail::predicted_state( pawn, data ).eye;

				return out;
			} );
	}

	float engine::predict_inaccuracy( std::span<const sdk::user_cmd> ticks, std::optional<sdk::vector3> velocity )
	{
		return this->simulate( ticks, [ velocity ]( sdk::cs_player_pawn* pawn, sdk::move_data* data )
			{
				using update_accuracy_penalty_fn = void( __fastcall* )( sdk::cs_weapon_base* );
				using get_inaccuracy_fn = float( __fastcall* )( sdk::cs_weapon_base*, float*, float* );

				const auto services = pawn->weapons( );
				const auto weapon = services ? core::entities( )->get<sdk::cs_weapon_base>( services->active_weapon( ) ) : nullptr;

				if ( !weapon || !data )
				{
					return 0.0f;
				}

				detail::finish_move( pawn, data );

				if ( velocity )
				{
					pawn->velocity( ) = *velocity;
					pawn->network_velocity( ).value = *velocity;
				}

				reinterpret_cast< update_accuracy_penalty_fn >( core::g_game.update_accuracy_penalty )( weapon );
				return reinterpret_cast< get_inaccuracy_fn >( core::g_game.get_inaccuracy )( weapon, nullptr, nullptr );
			} );
	}

} // namespace opaline::prediction

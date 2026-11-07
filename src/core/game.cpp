#include <pch.hpp>
#include <core/game.hpp>
#include <core/modules.hpp>
#include <core/log.hpp>

namespace opaline::core {

	namespace detail {

		constexpr auto k_user_cmd_sequence{ 0x5910ull };
		constexpr auto k_net_tick_state{ 23ull };
		constexpr auto k_frame_input_count{ 10u };
		constexpr auto k_frame_input_size{ 40ull };
		constexpr auto k_frame_input_tick{ 0x0Cull };

		[[nodiscard]] static IDXGISwapChain* find_swap_chain( )
		{
			const auto device = g_modules.render_system.find( "48 8B 4F 38 48 8B 05 [? ? ? ?] 48 F7 D9 F0 48 01 88" ).deref( ).as<sdk::render_device>( );
			if ( !device || !device->swap_chains( ) || device->swap_chain_head( ) < 0 )
			{
				return nullptr;
			}

			const auto owner = device->swap_chains( )[ device->swap_chain_head( ) ].owner;
			return owner ? owner->swap_chain( ) : nullptr;
		}

	} // namespace detail

	bool resolve_game( )
	{
		auto& client = g_modules.client;

		g_game.entity_system = client.find( "48 8B 0D [? ? ? ?] 8B FB C1 EB 0E" ).as<sdk::entity_system*>( );
		g_game.local_controller = client.find( "48 39 1D [? ? ? ?] 75 04 B0 01" ).as<sdk::cs_player_controller*>( );
		g_game.global_vars = client.find( "48 8B 05 [? ? ? ?] 44 8B 40 44" ).as<sdk::global_vars*>( );
		g_game.schema_system = g_modules.schema_system.get_interface<sdk::schema_system>( "SchemaSystem_001" );
		g_game.input_stack = g_modules.input_system.get_interface<sdk::input_stack_system>( "InputStackSystemVersion001" );
		g_game.cvar_system = g_modules.tier0.get_interface<sdk::cvar_system>( "VEngineCvar007" );
		g_game.swap_chain = detail::find_swap_chain( );
		g_game.client_prediction = client.get_interface<sdk::client_prediction>( "Source2ClientPrediction001" );
		g_game.view_matrix = client.find( "48 8D 0D [? ? ? ?] 48 C1 E0 06" ).as<sdk::matrix4x4>( );
		g_game.prediction_seed = client.find( "8B 3D [? ? ? ?] 48 8B 03 48 8B CB" ).as<std::uint32_t>( );
		g_game.simulation_player = client.find( "4C 39 05 [? ? ? ?] 41 0F 94 C6" ).as<sdk::cs_player_pawn*>( );
		g_game.prediction_player = client.find( "B9 FF FF FF FF E8 ? ? ? ? 48 89 3D [? ? ? ?] 48 8B 5C 24 30" ).as<sdk::cs_player_pawn*>( );
		g_game.prediction_phase = client.find( "8B 15 [? ? ? ?] 0F B6 41 30" ).as<std::int32_t>( );
		g_game.process_input = client.find( "CC CC 48 89 5C 24 08 57 48 83 EC 20 C6 41 08 00 48 8D 05 [? ? ? ?] 48 89 01 48 8B D9" ).add( 0x20 ).deref( ).as<void>( );
		g_game.create_move = client.find( "FF FF FF FF 48 8D 05 [? ? ? ?] 48 89 0D ? ? ? ?" ).add( 0x28 ).deref( ).as<void>( );
		g_game.render_view = client.find( "48 89 5C 24 10 48 89 6C 24 18 56 57 41 56 48 81 EC B0 00 00 00" ).as<void>( );
		g_game.play_landing_sound = client.find( "40 55 53 48 8D AC 24 58 FD FF FF 48 81 EC A8 03 00 00" ).as<void>( );
		g_game.emit_sound_by_handle = client.find( "30 48 89 44 24 20 48 8B D3 48 8D 0D ? ? ? ? E8 [? ? ? ?] 48 8D 05 ? ? ? ?" ).as<void>( );
		g_game.get_user_cmd_base = client.find( "48 83 EC 28 E8 [? ? ? ?] 8B 80 10 59 00 00" ).as<void>( );
		g_game.get_user_cmd = client.find( "40 53 48 83 EC 20 8B DA E8 ? ? ? ? 4C 8B C0 85 DB 7F 0A 33 C9 8B C1" ).as<void>( );
		g_game.subtick_loop = client.find( "48 8B C4 57 48 81 EC 20 01 00 00 41 80 B8 90 00 00 00 00" ).as<void>( );
		g_game.post_network_data_received = client.find( "48 89 5C 24 10 48 89 4C 24 08 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 B0 FC FF FF 48 81 EC 50 04 00 00" ).as<void>( );
		g_game.create_subtick_move_step = client.find( "48 8B 54 CA 08 8D 41 01 89 47 08 EB 16 48 8B 0F E8 [? ? ? ?] 48 8B D0 48 8B CF" ).as<void>( );
		g_game.add_allocated = client.find( "E8 [? ? ? ?] 4C 8B D0 45 8B 4A 10" ).as<void>( );
		g_game.csgo_input = client.find( "84 C0 74 0C 48 8D 0D [? ? ? ?] E8 ? ? ? ?" ).as<sdk::csgo_input>( );
		g_game.trace_manager = client.find( "48 8B 0D [? ? ? ?] 48 8D 34 52" ).as<void*>( );
		g_game.net_client = client.find( "48 8B 0D [? ? ? ?] FF 54 24 30" ).as<void*>( );
		g_game.frame_input_index = g_modules.engine2.find( "48 63 15 [? ? ? ?] 83 FA 0A 7D 61" ).as<std::int32_t>( );
		g_game.frame_inputs = g_modules.engine2.find( "48 8D 05 [? ? ? ?] 0F 10 04 C8" ).as<std::uint8_t>( );
		g_game.server_tick_offset = g_modules.engine2.find( "2B C1 89 BB ? ? ? ? 4C 8D 83 90 00 00 00" ).add( 4 ).as<std::uint32_t>( );
		g_game.get_view_angles = client.find( "8B 0D ? ? ? ? 8B D3 E8 [? ? ? ?] F2 0F 10 00" ).as<void>( );
		g_game.set_view_angles = client.find( "85 D2 75 3D 48 63 81 50 0B 00 00 F2 41 0F 10 00 85 C0 74 1B 48 69 D0 40" ).as<void>( );
		g_game.finalize_move = client.find( "FF FF FF FF 48 8D 05 [? ? ? ?] 48 89 0D ? ? ? ?" ).add( 0x40 ).deref( ).as<void>( );
		g_game.render_scope = client.find( "48 8B C4 53 57 48 83 EC 68 48 8B FA" ).as<void>( );
		g_game.trace_shape = client.find( "48 89 5C 24 20 48 89 4C 24 08 55 57 41 54 41 55 41 56 48 8D AC 24 10 E0 FF FF B8 F0 20 00 00" ).as<void>( );
		g_game.create_trace_filter = client.find( "48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 20 0F B6 41 39 33 FF 24 C9 C7 41 34 FF FF 00 0F 0C 49" ).as<void>( );
		g_game.override_view = client.find( "48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 20 57 41 56 41 57 48 83 EC 40 48 8B FA E8 ? ? ? ? 65 48 8B 04 25 58 00 00 00" ).as<void>( );
		g_game.update_fov_sensitivity = client.find( "48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 48 83 EC 20 48 8B B9 10 14 00 00" ).as<void>( );
		g_game.frame_stage_notify = client.find( "48 89 5C 24 18 48 89 6C 24 20 57 48 83 EC 40 48 8B F9" ).as<void>( );
		g_game.setup_bones = client.find( "E8 [? ? ? ?] 8B 85 2C 85 01 00" ).as<void>( );
		g_game.invalidate_bones = client.find( "40 53 48 83 EC 20 48 8B D9 C7 81 90 04 00 00 00 00 00 00 48 8B 89 E8 01 00 00" ).as<void>( );
		g_game.hitbox_transforms = client.find( "48 89 5C 24 20 57 41 54 41 56 48 83 EC 20 48 8D 99 00 02 00 00 4C 8B F1 48 8B 0B 41 8B C1 49 8B F8 4C 8B E2" ).as<void>( );
		g_game.hitbox_broadphase = client.find( "48 8B C4 48 89 58 08 48 89 70 10 48 89 78 18 55 41 54 41 55 41 56 41 57 48 81 EC A0 01 00 00 0F 29 70 C8 48 8D 6C 24 50 48 83 E5 E0" ).as<void>( );
		g_game.hitbox_bone = client.find( "48 89 5C 24 10 48 89 6C 24 18 56 48 83 EC 30 48 63 6A 08 48 8B F1 4C 8B 02 39 A9 E8 02 00 00" ).as<void>( );
		g_game.create_trace = client.find( "48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 41 56 41 57 48 83 EC 50 F2 0F 10 02 4D 8D 71 08 F2 0F 11 81 F8 18 00 00" ).as<void>( );
		g_game.handle_bullet_penetration = client.find( "40 53 57 41 56 48 83 EC 50 8B 84 24 90 00 00 00 4C 8B F1 48 81 C1 04 19 00 00 F3 0F 11 4C 24 30 F3 0F 11 54 24 34" ).as<void>( );
		g_game.calculate_spread = client.find( "28 F3 44 0F 11 44 24 20 E8 [? ? ? ?] 48 8D 85 B0 00 00 00" ).as<void>( );
		g_game.get_inaccuracy = client.find( "48 89 5C 24 10 55 56 57 48 81 EC B0 00 00 00 44 0F 29 84 24 80 00 00 00 49 8B F8 48 8B EA 48 8B D9 E8 ? ? ? ? 48 8B F0 45 0F 57 C0" ).as<void>( );
		g_game.update_accuracy_penalty = client.find( "40 53 57 48 83 EC 68 48 8B F9 E8 ? ? ? ? 48 8B D8 48 85 C0 0F 84" ).as<void>( );
		g_game.get_lerp_seconds = client.find( "E8 [? ? ? ?] 41 8B 96 68 03 00 00" ).as<void>( );

		if ( g_game.cvar_system )
		{
			g_game.air_accelerate = g_game.cvar_system->find( "sv_airaccelerate" );
			g_game.air_max_wishspeed = g_game.cvar_system->find( "sv_air_max_wishspeed" );
			g_game.quantize_movement_input = g_game.cvar_system->find( "sv_quantize_movement_input" );
			g_game.zoom_sensitivity_ratio = g_game.cvar_system->find( "zoom_sensitivity_ratio" );
			g_game.max_unlag = g_game.cvar_system->find( "sv_maxunlag" );
			g_game.gravity = g_game.cvar_system->find( "sv_gravity" );
			g_game.interp_ratio = g_game.cvar_system->find( "cl_interp_ratio" );
			g_game.min_interp_ratio = g_game.cvar_system->find( "sv_client_min_interp_ratio" );
			g_game.max_interp_ratio = g_game.cvar_system->find( "sv_client_max_interp_ratio" );
			g_game.game_type = g_game.cvar_system->find( "game_type" );
			g_game.game_mode = g_game.cvar_system->find( "game_mode" );
			g_game.damage_scale_ct_head = g_game.cvar_system->find( "mp_damage_scale_ct_head" );
			g_game.damage_scale_t_head = g_game.cvar_system->find( "mp_damage_scale_t_head" );
			g_game.damage_scale_ct_body = g_game.cvar_system->find( "mp_damage_scale_ct_body" );
			g_game.damage_scale_t_body = g_game.cvar_system->find( "mp_damage_scale_t_body" );
		}

		const std::array<const void*, 65> required
		{
			g_game.entity_system, g_game.local_controller, g_game.global_vars, g_game.schema_system, g_game.input_stack, g_game.swap_chain, g_game.client_prediction,
			g_game.view_matrix, g_game.prediction_seed, g_game.simulation_player, g_game.prediction_player, g_game.prediction_phase, g_game.process_input,
			g_game.create_move, g_game.render_view, g_game.play_landing_sound, g_game.emit_sound_by_handle, g_game.get_user_cmd_base, g_game.get_user_cmd, g_game.subtick_loop,
			g_game.post_network_data_received, g_game.create_subtick_move_step, g_game.add_allocated, g_game.cvar_system, g_game.air_accelerate, g_game.air_max_wishspeed,
			g_game.quantize_movement_input, g_game.zoom_sensitivity_ratio, g_game.csgo_input, g_game.trace_manager, g_game.net_client, g_game.frame_input_index, g_game.frame_inputs, g_game.server_tick_offset, g_game.get_view_angles, g_game.set_view_angles, g_game.finalize_move, g_game.render_scope, g_game.trace_shape,
			g_game.create_trace_filter, g_game.override_view, g_game.update_fov_sensitivity,
			g_game.max_unlag, g_game.gravity, g_game.interp_ratio, g_game.min_interp_ratio, g_game.max_interp_ratio, g_game.game_type, g_game.game_mode, g_game.damage_scale_ct_head, g_game.damage_scale_t_head, g_game.damage_scale_ct_body, g_game.damage_scale_t_body, g_game.frame_stage_notify,
			g_game.setup_bones, g_game.invalidate_bones, g_game.hitbox_transforms, g_game.hitbox_broadphase, g_game.hitbox_bone, g_game.create_trace,
			g_game.handle_bullet_penetration, g_game.calculate_spread, g_game.get_inaccuracy, g_game.update_accuracy_penalty, g_game.get_lerp_seconds
		};

		return std::ranges::all_of( required, [ ]( const void* pointer ) { return pointer != nullptr; } );
	}

	sdk::entity_system* entities( )
	{
		return *g_game.entity_system;
	}

	sdk::global_vars* globals( )
	{
		return *g_game.global_vars;
	}

	sdk::cs_player_controller* local_controller( )
	{
		return *g_game.local_controller;
	}

	sdk::cs_player_pawn* local_pawn( sdk::cs_player_controller* controller )
	{
		const auto system = entities( );

		if ( !controller || !system || !controller->pawn_alive( ) )
		{
			return nullptr;
		}

		return system->get<sdk::cs_player_pawn>( controller->player_pawn( ) );
	}

	sdk::user_cmd* user_cmd( sdk::cs_player_controller* controller, std::int64_t sequence )
	{
		using get_cmd_fn = sdk::user_cmd*( __fastcall* )( std::uintptr_t, std::uintptr_t );

		if ( !controller || sequence <= 0 )
		{
			return nullptr;
		}

		return reinterpret_cast< get_cmd_fn >( g_game.get_user_cmd )( reinterpret_cast< std::uintptr_t >( controller ), static_cast< std::uintptr_t >( static_cast< std::uint32_t >( sequence ) ) );
	}

	sdk::user_cmd* current_user_cmd( sdk::cs_player_controller* controller )
	{
		using get_base_fn = std::uintptr_t( __fastcall* )( std::uintptr_t );

		const auto base = controller ? reinterpret_cast< get_base_fn >( g_game.get_user_cmd_base )( reinterpret_cast< std::uintptr_t >( controller ) ) : 0;
		if ( !base )
		{
			return nullptr;
		}

		return user_cmd( controller, *reinterpret_cast< const std::int32_t* >( base + detail::k_user_cmd_sequence ) );
	}

	sdk::vector3 view_angles( )
	{
		using get_view_angles_fn = const sdk::vector3*( __fastcall* )( sdk::csgo_input*, int );

		const auto angles = reinterpret_cast< get_view_angles_fn >( g_game.get_view_angles )( g_game.csgo_input, 0 );
		return angles ? *angles : sdk::vector3{};
	}

	void set_view_angles( const sdk::vector3& angles )
	{
		using set_view_angles_fn = void( __fastcall* )( sdk::csgo_input*, int, const sdk::vector3* );
		reinterpret_cast< set_view_angles_fn >( g_game.set_view_angles )( g_game.csgo_input, 0, &angles );
	}

	bool is_enemy( std::uint8_t local_team, std::uint8_t other_team )
	{
		const auto type = g_game.game_type->get<int>( );
		const auto mode = g_game.game_mode->get<int>( );
		const auto free_for_all = ( type == 1 && mode == 2 ) || ( type == 2 && mode == 0 );

		return free_for_all || local_team != other_team;
	}

	int server_tick( )
	{
		const auto client = *g_game.net_client;
		const auto state = client ? sdk::vfunc<detail::k_net_tick_state, std::uintptr_t>( client ) : 0;

		if ( !state )
		{
			return 0;
		}

		return *reinterpret_cast< const int* >( state + *g_game.server_tick_offset );
	}

	int client_tick( )
	{
		const auto slot = static_cast< std::uint32_t >( *g_game.frame_input_index ) % detail::k_frame_input_count;
		return *reinterpret_cast< const int* >( g_game.frame_inputs + detail::k_frame_input_size * slot + detail::k_frame_input_tick );
	}

	sdk::trace_filter trace_filter( void* skip, std::uint64_t mask, std::uint8_t layer, int type )
	{
		using create_trace_filter_fn = void( __fastcall* )( sdk::trace_filter*, void*, std::uint64_t, std::uint8_t, int );

		sdk::trace_filter filter{};
		reinterpret_cast< create_trace_filter_fn >( g_game.create_trace_filter )( &filter, skip, mask, layer, type );

		return filter;
	}

	sdk::trace_result trace_hull( const sdk::vector3& start, const sdk::vector3& end, const sdk::vector3& mins, const sdk::vector3& maxs, const sdk::trace_filter& filter )
	{
		using trace_shape_fn = bool( __fastcall* )( void*, const sdk::trace_ray*, const sdk::vector3*, const sdk::vector3*, const sdk::trace_filter*, sdk::trace_result* );

		sdk::trace_ray ray{};
		ray.mins = mins;
		ray.maxs = maxs;
		ray.type = sdk::ray_types::hull;

		sdk::trace_result result{};
		result.fraction = 1.0f;

		reinterpret_cast< trace_shape_fn >( g_game.trace_shape )( *g_game.trace_manager, &ray, &start, &end, &filter, &result );

		return result;
	}

} // namespace opaline::core

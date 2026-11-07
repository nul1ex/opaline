#pragma once

#include <sdk/engine.hpp>
#include <sdk/entities.hpp>
#include <sdk/trace.hpp>
#include <sdk/usercmd.hpp>

namespace opaline::core {

	struct game
	{
		sdk::entity_system** entity_system{};
		sdk::cs_player_controller** local_controller{};
		sdk::global_vars** global_vars{};
		sdk::schema_system* schema_system{};
		sdk::input_stack_system* input_stack{};
		sdk::cvar_system* cvar_system{};
		sdk::convar* air_accelerate{};
		sdk::convar* air_max_wishspeed{};
		sdk::convar* quantize_movement_input{};
		sdk::convar* zoom_sensitivity_ratio{};
		sdk::convar* max_unlag{};
		sdk::convar* gravity{};
		sdk::convar* interp_ratio{};
		sdk::convar* min_interp_ratio{};
		sdk::convar* max_interp_ratio{};
		sdk::convar* game_type{};
		sdk::convar* game_mode{};
		sdk::convar* damage_scale_ct_head{};
		sdk::convar* damage_scale_t_head{};
		sdk::convar* damage_scale_ct_body{};
		sdk::convar* damage_scale_t_body{};
		sdk::csgo_input* csgo_input{};
		void** trace_manager{};
		void** net_client{};
		std::int32_t* frame_input_index{};
		std::uint8_t* frame_inputs{};
		std::uint32_t* server_tick_offset{};
		IDXGISwapChain* swap_chain{};
		sdk::client_prediction* client_prediction{};
		sdk::matrix4x4* view_matrix{};
		std::uint32_t* prediction_seed{};
		sdk::cs_player_pawn** simulation_player{};
		sdk::cs_player_pawn** prediction_player{};
		std::int32_t* prediction_phase{};
		void* process_input{};
		void* create_move{};
		void* render_view{};
		void* play_landing_sound{};
		void* emit_sound_by_handle{};
		void* get_user_cmd_base{};
		void* get_user_cmd{};
		void* subtick_loop{};
		void* post_network_data_received{};
		void* create_subtick_move_step{};
		void* add_allocated{};
		void* get_view_angles{};
		void* set_view_angles{};
		void* finalize_move{};
		void* render_scope{};
		void* trace_shape{};
		void* create_trace_filter{};
		void* override_view{};
		void* update_fov_sensitivity{};
		void* frame_stage_notify{};
		void* setup_bones{};
		void* invalidate_bones{};
		void* hitbox_transforms{};
		void* hitbox_broadphase{};
		void* hitbox_bone{};
		void* create_trace{};
		void* handle_bullet_penetration{};
		void* calculate_spread{};
		void* get_inaccuracy{};
		void* update_accuracy_penalty{};
		void* get_lerp_seconds{};
	};

	inline game g_game{};

	[[nodiscard]] bool resolve_game( );

	[[nodiscard]] sdk::entity_system* entities( );
	[[nodiscard]] sdk::global_vars* globals( );
	[[nodiscard]] sdk::cs_player_controller* local_controller( );
	[[nodiscard]] sdk::cs_player_pawn* local_pawn( sdk::cs_player_controller* controller );
	[[nodiscard]] sdk::user_cmd* user_cmd( sdk::cs_player_controller* controller, std::int64_t sequence );
	[[nodiscard]] sdk::user_cmd* current_user_cmd( sdk::cs_player_controller* controller );
	[[nodiscard]] sdk::vector3 view_angles( );
	void set_view_angles( const sdk::vector3& angles );
	[[nodiscard]] bool is_enemy( std::uint8_t local_team, std::uint8_t other_team );
	[[nodiscard]] int server_tick( );
	[[nodiscard]] int client_tick( );
	[[nodiscard]] sdk::trace_filter trace_filter( void* skip, std::uint64_t mask, std::uint8_t layer, int type );
	[[nodiscard]] sdk::trace_result trace_hull( const sdk::vector3& start, const sdk::vector3& end, const sdk::vector3& mins, const sdk::vector3& maxs, const sdk::trace_filter& filter );

} // namespace opaline::core

#pragma once

#include <sdk/sdk.hpp>

namespace opaline::sdk {

	namespace command_states {

		constexpr int building{ 2 };

	} // namespace command_states

	namespace buttons {

		constexpr auto attack{ 1ull << 0 };
		constexpr auto jump{ 1ull << 1 };
		constexpr auto duck{ 1ull << 2 };
		constexpr auto forward{ 1ull << 3 };
		constexpr auto back{ 1ull << 4 };
		constexpr auto use{ 1ull << 5 };
		constexpr auto move_left{ 1ull << 9 };
		constexpr auto move_right{ 1ull << 10 };
		constexpr auto attack2{ 1ull << 11 };
		constexpr auto reload{ 1ull << 13 };
		constexpr auto sprint{ 1ull << 16 };
		constexpr auto movement{ forward | back | move_left | move_right };

	} // namespace buttons

	template <typename type>
	struct repeated_ptr_field
	{
		struct rep
		{
			int allocated_size;
			type* elements[ 1 ];
		};

		void* arena;
		int current_size;
		int total_size;
		rep* data;
	};

	struct subtick_move_step
	{
		void* vtable;
		void* metadata;
		std::uint32_t has_bits;
		std::uint32_t cached_size;
		std::uint64_t button;
		bool pressed;
		float when;
		float analog_forward_delta;
		float analog_left_delta;
		float pitch_delta;
		float yaw_delta;
	};

	namespace step_fields {

		constexpr std::uint32_t button{ 1u << 0 };
		constexpr std::uint32_t pressed{ 1u << 1 };
		constexpr std::uint32_t when{ 1u << 2 };
		constexpr std::uint32_t analog_forward_delta{ 1u << 3 };
		constexpr std::uint32_t analog_left_delta{ 1u << 4 };

	} // namespace step_fields

	struct button_state_pb
	{
		void* vtable;
		void* metadata;
		std::uint32_t has_bits;
		std::uint32_t cached_size;
		std::array<std::uint64_t, 3> states;
	};

	struct qangle_pb
	{
		void* vtable;
		void* metadata;
		std::uint32_t has_bits;
		std::uint32_t cached_size;
		float x;
		float y;
		float z;
	};

	namespace qangle_fields {

		constexpr auto x{ 1u << 0 };
		constexpr auto y{ 1u << 1 };

	} // namespace qangle_fields

	struct interpolation_info
	{
		void* vtable;
		void* metadata;
		std::uint32_t has_bits;
		std::uint32_t cached_size;
		float fraction;
		std::int32_t source_tick;
		std::int32_t destination_tick;
	};

	struct client_interpolation_info
	{
		void* vtable;
		void* metadata;
		std::uint32_t has_bits;
		std::uint32_t cached_size;
		float fraction;
	};

	namespace interpolation_fields {

		constexpr auto fraction{ 1u << 0 };
		constexpr auto source_tick{ 1u << 1 };
		constexpr auto destination_tick{ 1u << 2 };

	} // namespace interpolation_fields

	struct input_history_entry
	{
		void* vtable;
		void* metadata;
		std::uint32_t has_bits;
		std::uint32_t cached_size;
		qangle_pb* view_angles;
		client_interpolation_info* cl_interp;
		interpolation_info* sv_interp0;
		interpolation_info* sv_interp1;
		interpolation_info* player_interp;
		void* shoot_position;
		void* target_head_position_check;
		void* target_abs_position_check;
		void* target_abs_angle_check;
		std::int32_t render_tick_count;
		float render_tick_fraction;
		std::int32_t player_tick_count;
		float player_tick_fraction;
		std::int32_t frame_number;
		std::int32_t target_entity_index;
	};

	namespace history_fields {

		constexpr auto view_angles{ 1u << 0 };
		constexpr auto cl_interp{ 1u << 1 };
		constexpr auto sv_interp0{ 1u << 2 };
		constexpr auto sv_interp1{ 1u << 3 };
		constexpr auto render_tick_count{ 1u << 9 };
		constexpr auto render_tick_fraction{ 1u << 10 };
		constexpr auto player_tick_count{ 1u << 11 };
		constexpr auto player_tick_fraction{ 1u << 12 };

	} // namespace history_fields

	struct base_user_cmd
	{
		void* vtable;
		void* metadata;
		std::uint32_t has_bits;
		std::uint32_t cached_size;
		repeated_ptr_field<subtick_move_step> subtick_moves;
		void* move_crc;
		button_state_pb* buttons;
		qangle_pb* view_angles;
		void* execution_notes;
		std::int32_t legacy_command_number;
		std::int32_t client_tick;
		float forward_move;
		float left_move;
		float up_move;
		std::int32_t impulse;
		std::int32_t weapon_select;
	};

	namespace base_fields {

		constexpr auto view_angles{ 1u << 2 };
		constexpr auto forward_move{ 1u << 6 };
		constexpr auto left_move{ 1u << 7 };
		constexpr auto weapon_select{ 1u << 10 };

	} // namespace base_fields

	namespace csgo_fields {

		constexpr auto attack1_start_history_index{ 1u << 5 };

	} // namespace csgo_fields

	struct csgo_user_cmd
	{
		std::uint32_t has_bits;
		std::uint32_t cached_size;
		repeated_ptr_field<input_history_entry> input_history;
		base_user_cmd* base;
		bool left_hand_desired;
		bool predicting_body_shot_fx;
		bool predicting_head_shot_fx;
		bool predicting_kill_ragdolls;
		std::int32_t attack1_start_history_index;
		std::int32_t attack2_start_history_index;
	};

	struct button_state
	{
		void* vtable;
		std::uint64_t value;
		std::uint64_t value_changed;
		std::uint64_t value_scroll;
	};

	struct user_cmd
	{
		void* vtable;
		std::int64_t command_number;
		void* proto_vtable;
		void* proto_arena;
		csgo_user_cmd pb;
		button_state buttons;
		std::uint64_t unknown_78;
		double last_server_time;
		std::uint32_t unknown_88;
		bool has_been_predicted;
		int unknown_90;
		int command_state;
	};

	class csgo_input
	{
	public:
		FIELD( std::uint32_t, selected_weapon, 0x694 )
	};

} // namespace opaline::sdk

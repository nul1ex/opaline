#pragma once

#include <sdk/entities.hpp>
#include <sdk/usercmd.hpp>
#include <sdk/engine.hpp>

namespace opaline::prediction {

	constexpr auto k_command_history{ 150ull };

	struct shot_history
	{
		sdk::shot_eye_ring entries{};
		int tail{};
		int count{};
		sdk::vector3 uninterpolated{};
	};

	class engine
	{
	public:
		struct state
		{
			std::uint32_t flags{};
			std::uint8_t move_type{};
			bool ducked{};
			sdk::vector3 velocity{};
			sdk::vector3 origin{};
			sdk::vector3 eye{};
			sdk::vector3 impulses{};
			std::int32_t jump_tick{};
			float jump_fraction{};
			std::int32_t landed_tick{};
			float landed_fraction{};

			[[nodiscard]] bool on_ground( ) const noexcept { return ( this->flags & 1u ) != 0; }
			[[nodiscard]] bool jumped_since( const state& before ) const noexcept { return this->jump_tick != before.jump_tick || this->jump_fraction != before.jump_fraction; }
			[[nodiscard]] bool landed_since( const state& before ) const noexcept { return this->landed_tick != before.landed_tick || this->landed_fraction != before.landed_fraction; }
			[[nodiscard]] bool touched_down( const state& before ) const noexcept { return this->on_ground( ) || this->landed_since( before ); }
		};

		[[nodiscard]] bool begin( sdk::cs_player_controller* controller, sdk::cs_player_pawn* pawn, std::int64_t command_number );
		[[nodiscard]] state predict( std::span<const sdk::user_cmd> ticks );
		[[nodiscard]] float predict_inaccuracy( std::span<const sdk::user_cmd> ticks, std::optional<sdk::vector3> velocity );
		[[nodiscard]] sdk::vector3 predict_shot_eye( std::span<const sdk::user_cmd> ticks, double label );
		void commit_shot_history( std::span<const sdk::user_cmd> ticks );
		void before_network_update( sdk::prediction_system* system );
		void after_network_update( );

		[[nodiscard]] const state& start( ) const noexcept { return this->m_start; }
		[[nodiscard]] sdk::cs_player_pawn* pawn( ) const noexcept { return this->m_pawn; }
		[[nodiscard]] bool simulating( ) const noexcept { return this->m_simulating; }
		[[nodiscard]] bool impulses_reset( ) const noexcept { return this->m_impulses_reset; }

	private:
		struct input_record
		{
			std::int64_t command_number{ -1 };
			sdk::button_block buttons{};
		};

		void reset_impulses( sdk::cs_player_pawn* pawn );
		void record_input( sdk::cs_player_pawn* pawn, std::int64_t command_number );

		template <typename callback>
		[[nodiscard]] auto simulate( std::span<const sdk::user_cmd> ticks, callback&& read );

		[[nodiscard]] shot_history predict_shot_history( std::span<const sdk::user_cmd> ticks );
		[[nodiscard]] shot_history simulate_shot_history( std::span<const sdk::user_cmd> ticks );

		state m_start{};
		sdk::cs_player_controller* m_controller{};
		sdk::cs_player_pawn* m_pawn{};
		std::array<input_record, k_command_history> m_inputs{};
		sdk::prediction_slot* m_network_slot{};
		int m_stored_frames{};
		bool m_impulse_reset_pending{};
		bool m_impulses_reset{};
		bool m_simulating{};
		shot_history m_server_ring{};
		bool m_server_ring_valid{};
	};

	inline engine g_engine{};

} // namespace opaline::prediction

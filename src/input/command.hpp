#pragma once

#include <sdk/usercmd.hpp>
#include <prediction/engine.hpp>

namespace opaline::input {

	struct button_step
	{
		float when{};
		std::uint64_t button{};
		bool pressed{};
	};

	struct future_tick
	{
		std::uint64_t buttons{};
		std::vector<button_step> steps{};
	};

	class command
	{
	public:
		struct shot
		{
			sdk::vector3 angles{};
			std::int32_t render_tick{};
			std::int32_t player_tick{};
		};

		struct checkpoint
		{
			int steps{};
			float forward{};
			float left{};
			std::uint64_t buttons{};
		};

		command( sdk::csgo_input* input, sdk::user_cmd* cmd, const sdk::vector3& impulses );

		[[nodiscard]] std::int64_t number( ) const noexcept { return this->m_cmd->command_number; }
		[[nodiscard]] std::uint64_t buttons( ) const noexcept { return this->m_cmd->buttons.value; }
		[[nodiscard]] std::uint64_t user_buttons( ) const noexcept { return this->m_user_buttons; }
		[[nodiscard]] bool holds( std::uint64_t button ) const noexcept { return ( this->m_cmd->buttons.value & button ) != 0; }
		[[nodiscard]] float forward_move( ) const noexcept { return this->m_cmd->pb.base->forward_move; }
		[[nodiscard]] float left_move( ) const noexcept { return this->m_cmd->pb.base->left_move; }
		[[nodiscard]] float view_pitch( ) const noexcept;
		[[nodiscard]] float view_yaw( ) const noexcept;
		[[nodiscard]] int step_count( ) const noexcept { return this->m_cmd->pb.base->subtick_moves.current_size; }

		[[nodiscard]] checkpoint save( ) const;
		void restore( const checkpoint& point );

		void clear_steps( );
		void truncate_steps( int count );
		void set_buttons( std::uint64_t value );
		void set_view_angles( float pitch, float yaw );
		void turn( float pitch, float yaw );
		void strip( std::uint64_t button );
		void press( std::uint64_t button, float when );
		void add_buttons( std::span<const button_step> steps );
		void add_move( float when, float forward_delta, float left_delta );
		void set_move( float forward, float left );
		void clear_moves( );
		void restore_move( float forward, float left );

		[[nodiscard]] prediction::engine::state predict( std::span<const future_tick> ahead = {} );
		[[nodiscard]] float predict_inaccuracy( std::optional<sdk::vector3> velocity = std::nullopt );
		[[nodiscard]] sdk::vector3 predict_shot_eye( double label );
		[[nodiscard]] bool shoot( const shot& info );
		void commit( );

	private:
		[[nodiscard]] sdk::subtick_move_step* add_step( );
		[[nodiscard]] sdk::subtick_move_step* append_step( );
		void sync_moves( );
		void sort_steps( );

		template <typename callback>
		[[nodiscard]] auto synced( callback&& run );

		sdk::csgo_input* m_input{};
		sdk::user_cmd* m_cmd{};
		sdk::vector3 m_impulses{};
		std::uint64_t m_user_buttons{};
	};

} // namespace opaline::input

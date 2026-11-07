#pragma once

#include <sdk/engine.hpp>
#include <sdk/entities.hpp>

namespace opaline::misc {

	class camera
	{
	public:
		void override_view( sdk::view_setup* setup );
		void update_fov_sensitivity( sdk::cs_player_pawn* pawn ) const;

	private:
		void thirdperson( sdk::view_setup* setup, sdk::cs_player_pawn* pawn ) const;

		[[nodiscard]] float wanted_fov( ) const;

		float m_last_game_fov{ 90.0f };
	};

	inline camera g_camera{};

} // namespace opaline::misc

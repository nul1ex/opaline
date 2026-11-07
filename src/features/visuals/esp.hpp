#pragma once

#include <sdk/math.hpp>

namespace opaline::visuals {

	class esp
	{
	public:
		void collect( );
		void draw( ImDrawList* draw_list );

	private:
		struct player
		{
			sdk::vector3 mins{};
			sdk::vector3 maxs{};
			std::string name{};
			std::string weapon{};
			int health{};
			int armor{};
			bool helmet{};
			bool scoped{};
			bool flashed{};
			bool defusing{};
		};

		void draw_player( ImDrawList* draw_list, const player& target, const ImVec2& min, const ImVec2& max ) const;

		std::mutex m_mutex{};
		std::vector<player> m_players{};
		sdk::matrix4x4 m_view_matrix{};
		std::chrono::steady_clock::time_point m_collected{};
	};

	inline esp g_esp{};

} // namespace opaline::visuals

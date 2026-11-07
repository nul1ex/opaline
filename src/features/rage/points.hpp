#pragma once

#include <features/rage/hitboxes.hpp>
#include <settings.hpp>

namespace opaline::rage {

	struct aim_box
	{
		int index{};
		float scale{};
		std::span<const float> outline{};
	};

	[[nodiscard]] std::vector<aim_box> aim_boxes( const settings::rage_weapon& cfg );
	void add_points( std::vector<sdk::vector3>& out, const capsule& shape, const aim_box& box, const sdk::vector3& eye, float spread_angle, float needed );

} // namespace opaline::rage

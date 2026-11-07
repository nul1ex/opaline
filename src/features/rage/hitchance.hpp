#pragma once

#include <features/rage/hitboxes.hpp>

namespace opaline::rage {

	constexpr auto k_spread_seeds{ 256ull };

	struct weapon_spread
	{
		std::uint16_t item_definition_index{};
		int mode{};
		float inaccuracy{};
		float spread{};
		float recoil_index{};
		float range{};
	};

	struct spread_table
	{
		std::array<std::pair<float, float>, k_spread_seeds> offsets{};
		float range{};
	};

	[[nodiscard]] spread_table build_spread( const weapon_spread& weapon );
	[[nodiscard]] std::pair<sdk::vector3, sdk::vector3> spread_axes( const sdk::vector3& forward );
	[[nodiscard]] float hitchance( const sdk::vector3& eye, const sdk::vector3& point, std::span<const capsule> shapes, const spread_table& table );

} // namespace opaline::rage

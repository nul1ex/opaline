#pragma once

#include <sdk/entities.hpp>

namespace opaline::rage {

	[[nodiscard]] sdk::vector3 aim_punch( sdk::cs_player_pawn* pawn, int tick, float fraction );

} // namespace opaline::rage

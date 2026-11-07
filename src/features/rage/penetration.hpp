#pragma once

#include <sdk/entities.hpp>
#include <sdk/trace.hpp>

namespace opaline::rage {

	class penetration
	{
	public:
		struct target
		{
			sdk::cs_player_pawn* pawn{};
			int armor{};
			bool helmet{};
			std::uint8_t team{};
			std::uint32_t hitbox_mask{};
		};

		struct result
		{
			float damage{};
			int hitgroup{};
			int hitbox{};
		};

		[[nodiscard]] bool prepare( sdk::cs_player_pawn* shooter, sdk::weapon_vdata* vdata );
		[[nodiscard]] std::optional<result> run( const sdk::vector3& start, const sdk::vector3& end, const target& victim ) const;

	private:
		[[nodiscard]] float scale_damage( float damage, int hitgroup, const target& victim ) const;

		sdk::trace_filter m_filter{};
		std::uint8_t m_team{};
		float m_damage{};
		float m_penetration{};
		float m_range{};
		float m_range_modifier{};
		float m_armor_ratio{};
		float m_headshot_multiplier{};
	};

	inline penetration g_penetration{};

} // namespace opaline::rage

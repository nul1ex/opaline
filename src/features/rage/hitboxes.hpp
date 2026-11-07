#pragma once

#include <sdk/entities.hpp>

namespace opaline::rage {

	constexpr auto k_max_hitboxes{ 20 };

	struct hitbox
	{
		int index{ -1 };
		int bone{ -1 };
		sdk::vector3 mins{};
		sdk::vector3 maxs{};
		float radius{};
	};

	struct hitbox_set
	{
		std::array<hitbox, k_max_hitboxes> entries{};
		int count{};

		[[nodiscard]] const hitbox* begin( ) const noexcept { return this->entries.data( ); }
		[[nodiscard]] const hitbox* end( ) const noexcept { return this->entries.data( ) + this->count; }
	};

	struct capsule
	{
		sdk::vector3 start{};
		sdk::vector3 end{};
		float radius{};
	};

	[[nodiscard]] hitbox_set query_hitboxes( sdk::game_scene_node* node );
	[[nodiscard]] capsule to_world( const hitbox& box, const sdk::bone_transform& bone );

} // namespace opaline::rage

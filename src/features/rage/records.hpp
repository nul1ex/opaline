#pragma once

#include <sdk/entities.hpp>
#include <sdk/trace.hpp>

namespace opaline::rage {

	constexpr auto k_max_bones{ 128 };

	struct record
	{
		sdk::cs_player_pawn* pawn{};
		sdk::game_scene_node* node{};
		std::array<sdk::bone_transform, k_max_bones> bones{};
		int bone_count{};
		sdk::bone_transform node_to_world{};
		sdk::vector3 origin{};
		sdk::vector3 velocity{};
		float simulation_time{};
		int tick{};
		bool was_valid{};
	};

	class records
	{
	public:
		class scope
		{
		public:
			explicit scope( const record& target ) noexcept;
			~scope( );

			scope( const scope& ) = delete;
			scope& operator=( const scope& ) = delete;
		};

		void update( );

		[[nodiscard]] std::vector<const record*> records_for( sdk::cs_player_pawn* pawn ) const;
		[[nodiscard]] int lerp_ticks( ) const;
		[[nodiscard]] sdk::vector3 shot_view( const sdk::vector3& base, const sdk::vector3& eye, const sdk::vector3& target, const record& source, const sdk::vector3& punch, const sdk::vector3& shooter_origin, int lead_ticks ) const;

		void override_transforms( sdk::game_scene_node* skeleton, const sdk::hitbox_shapes* shapes, sdk::hitbox_transforms* transforms ) const;
		void override_broadphase( const sdk::broadphase_tree* tree, sdk::broadphase_candidates* candidates ) const;

	private:
		[[nodiscard]] bool valid( const record& entry ) const;

		std::unordered_map<sdk::cs_player_pawn*, std::deque<record>> m_records{};
		std::atomic<const record*> m_applied{};
	};

	inline records g_records{};

} // namespace opaline::rage

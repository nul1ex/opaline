#include <pch.hpp>
#include <features/rage/hitboxes.hpp>

namespace opaline::rage {

	namespace detail {

		constexpr auto k_max_radius{ 100.0f };

	} // namespace detail

	hitbox_set query_hitboxes( sdk::game_scene_node* node )
	{
		hitbox_set out{};

		const auto handle = node ? node->model( ) : nullptr;
		const auto model = handle ? *handle : nullptr;
		const auto meshes = model ? model->render_meshes( ) : nullptr;
		const auto mesh = meshes ? *meshes : nullptr;
		const auto list = mesh ? mesh->hitboxes( ) : nullptr;

		if ( !list )
		{
			return out;
		}

		const auto count = list->count( );
		const auto entries = list->entries( );
		const auto remap = model->bone_remap( );
		const auto offset_a = model->remap_offset_a( );
		const auto offset_b = model->remap_offset_b( );

		if ( count <= 0 || count > k_max_hitboxes || !entries || !remap || !offset_a || !offset_b )
		{
			return out;
		}

		for ( auto index = 0; index < count; ++index )
		{
			const auto& entry = entries[ index ];
			const auto slot = static_cast< int >( entry.index ) + *offset_a + *offset_b;

			if ( slot >= model->bone_remap_count( ) )
			{
				continue;
			}

			const auto bone = static_cast< int >( remap[ slot ] );
			if ( bone < 0 || entry.radius < 0.0f || entry.radius > detail::k_max_radius )
			{
				continue;
			}

			out.entries[ static_cast< std::size_t >( out.count++ ) ] = { index, bone, entry.mins, entry.maxs, entry.radius };
		}

		return out;
	}

	capsule to_world( const hitbox& box, const sdk::bone_transform& bone )
	{
		return { bone.rotation.rotate( box.mins ) + bone.position, bone.rotation.rotate( box.maxs ) + bone.position, box.radius };
	}

} // namespace opaline::rage

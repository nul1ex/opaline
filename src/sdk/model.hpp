#pragma once

#include <sdk/sdk.hpp>
#include <sdk/math.hpp>

namespace opaline::sdk {

	struct bone_transform
	{
		vector3 position;
		float scale;
		quaternion rotation;
	};

	struct hitbox_desc
	{
		std::array<std::byte, 0x18> unknown_0;
		vector3 mins;
		vector3 maxs;
		float radius;
		std::array<std::byte, 0x14> unknown_34;
		std::uint16_t index;
		std::array<std::byte, 0x26> unknown_4a;
	};

	class hitbox_list
	{
	public:
		FIELD( int, count, 0x28 )
		FIELD( hitbox_desc*, entries, 0x30 )
	};

	class render_mesh
	{
	public:
		FIELD( hitbox_list*, hitboxes, 0x150 )
	};

	class model
	{
	public:
		FIELD( render_mesh**, render_meshes, 0x78 )
		FIELD( int, bone_remap_count, 0x220 )
		FIELD( std::int16_t*, bone_remap, 0x228 )
		FIELD( std::uint16_t*, remap_offset_a, 0x240 )
		FIELD( std::uint16_t*, remap_offset_b, 0x2F0 )
	};

} // namespace opaline::sdk

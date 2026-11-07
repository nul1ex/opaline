#pragma once

#include <sdk/sdk.hpp>
#include <sdk/math.hpp>
#include <sdk/model.hpp>

namespace opaline::sdk {

	struct trace_filter
	{
		void* vtable;
		std::uint64_t mask;
		std::uint64_t exclude_mask;
		std::array<std::byte, 0x1C> unknown_18;
		std::int16_t unknown_34;
		std::array<std::byte, 0x3> unknown_36;
		std::uint8_t options;
		std::array<std::byte, 0xE> unknown_3a;
	};

	struct trace_ray
	{
		vector3 mins;
		vector3 maxs;
		std::array<std::byte, 0x10> unknown_18;
		std::uint8_t type;
		std::array<std::byte, 0x7> unknown_29;
	};

	namespace ray_types {

		constexpr std::uint8_t hull{ 2 };

	} // namespace ray_types

	struct trace_contact
	{
		std::array<std::byte, 0x10> unknown_0;
		void* body;
		std::array<std::byte, 0xC> unknown_18;
		std::uint32_t entity;
		std::array<std::byte, 0x3> unknown_28;
		std::uint8_t is_body;
		std::array<std::byte, 0x4> unknown_2c;
	};

	struct trace_body
	{
		std::array<std::byte, 0x38> unknown_0;
		std::int32_t hitgroup;
		std::array<std::byte, 0xC> unknown_3c;
		std::uint16_t hitbox;
	};

	struct bullet_hit
	{
		float enter_fraction;
		float exit_fraction;
		float damage;
		std::int32_t penetrations_left;
		std::uint16_t enter_contact;
		std::uint16_t exit_contact;
		std::uint8_t can_penetrate;
		std::array<std::byte, 0x3> unknown_15;
	};

	struct trace_data
	{
		std::int32_t contact_count{};
		float unknown_4{ 52.0f };
		trace_contact* contacts{};
		std::int32_t capacity{ 0x80 };
		std::uint32_t flags{ 0x80000000 };
		std::array<trace_contact, 0x80> storage{};
		std::array<std::byte, 0x8> unknown_1818{};
		std::int32_t hit_count{};
		std::int32_t unknown_1824{};
		bullet_hit* hits{};
		std::array<std::byte, 0xC8> unknown_1830{};
		vector3 start{};
		vector3 end{};
		std::array<std::byte, 0x50> unknown_1910{};
	};

	class hitbox_shape
	{
	public:
		FIELD( bool, root_attached, 0x4A )
	};

	struct hitbox_shape_entry
	{
		hitbox_shape* shape;
		std::array<std::byte, 0x8> unknown_8;
	};

	struct hitbox_shapes
	{
		int count;
		hitbox_shape_entry* entries;
	};

	struct hitbox_transforms
	{
		std::array<std::byte, 0x10> unknown_0;
		bone_transform* entries;
	};

	struct broadphase_tree
	{
		std::array<std::byte, 0x18> unknown_0;
		int slot_count;
		std::array<std::byte, 0xC> unknown_1c;
		std::uint32_t* handles;
	};

	struct broadphase_candidates
	{
		int count;
		int* slots;
		int capacity;
	};

	struct trace_result
	{
		std::array<std::byte, 0xAC> unknown_0;
		float fraction;
		std::array<std::byte, 0x58> unknown_b0;
	};

} // namespace opaline::sdk

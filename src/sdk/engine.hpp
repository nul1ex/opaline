#pragma once

#include <sdk/sdk.hpp>
#include <sdk/math.hpp>

namespace opaline::sdk {

	class global_vars
	{
	public:
		FIELD( float, current_time, 0x30 )
		FIELD( float, frame_time, 0x34 )
		FIELD( int, tick_count, 0x44 )
		FIELD( float, tick_fraction, 0x50 )
	};

	class schema_system
	{
	public:
		[[nodiscard]] std::optional<std::uint32_t> field_offset( const char* module, const char* class_name, std::string_view field ) const;
	};

	class cs_player_controller;

	struct prediction_slot
	{
		std::array<std::byte, 0x10> unknown_0;
		cs_player_controller* controller;
		std::array<std::byte, 0x60> unknown_18;
		int last_acked_command;
		std::array<std::byte, 0x34> unknown_7c;
	};

	class prediction_system
	{
	public:
		FIELD( int, slot_count, 0x50 )
		FIELD( prediction_slot*, slots, 0x58 )
	};

	class client_prediction
	{
	public:
		FIELD( std::uint8_t, state, 0xD5 )
	};

	class swap_chain_owner
	{
	public:
		FIELD( IDXGISwapChain*, swap_chain, 0x170 )
	};

	struct swap_chain_entry
	{
		swap_chain_owner* owner;
		std::array<std::byte, 0x8> unknown_8;
	};

	class render_device
	{
	public:
		FIELD( swap_chain_entry*, swap_chains, 0x18588 )
		FIELD( int, swap_chain_head, 0x18590 )
	};

	class scope_render
	{
	public:
		FIELD( bool, visible, 0x4 )
	};

	class view_setup
	{
	public:
		FIELD( float, fov, 0x498 )
		FIELD( vector3, origin, 0x4A0 )
		FIELD( float, aspect_ratio, 0x4D8 )
	};

	class convar
	{
	public:
		[[nodiscard]] const char* name( ) const { return *reinterpret_cast< const char* const* >( this ); }

		template <typename type>
		[[nodiscard]] type get( ) const
		{
			return *reinterpret_cast< const type* >( reinterpret_cast< std::uintptr_t >( this ) + 0x58 );
		}
	};

	class cvar_system
	{
	public:
		[[nodiscard]] convar* find( std::string_view name ) const;
	};

	class input_stack_system
	{
	public:
		[[nodiscard]] void* push( const char* name, int flags ) const { return vfunc<11, void*>( this, name, flags ); }
		void pop( void* context ) const { vfunc<13, bool>( this, context ); }
	};

} // namespace opaline::sdk

#pragma once

#include <sdk/sdk.hpp>
#include <sdk/math.hpp>
#include <sdk/model.hpp>
#include <sdk/generated/client.hpp>

namespace opaline::sdk {

	namespace client = offsets::client;

	struct user_cmd;

	namespace move_types {

		constexpr std::uint8_t walk{ 2 };
		constexpr std::uint8_t noclip{ 7 };
		constexpr std::uint8_t ladder{ 9 };

	} // namespace move_types

	namespace item_definitions {

		constexpr std::uint16_t desert_eagle{ 1 };
		constexpr std::uint16_t dual_berettas{ 2 };
		constexpr std::uint16_t five_seven{ 3 };
		constexpr std::uint16_t glock{ 4 };
		constexpr std::uint16_t ak47{ 7 };
		constexpr std::uint16_t aug{ 8 };
		constexpr std::uint16_t awp{ 9 };
		constexpr std::uint16_t famas{ 10 };
		constexpr std::uint16_t g3sg1{ 11 };
		constexpr std::uint16_t galil{ 13 };
		constexpr std::uint16_t m249{ 14 };
		constexpr std::uint16_t m4a4{ 16 };
		constexpr std::uint16_t mac10{ 17 };
		constexpr std::uint16_t p90{ 19 };
		constexpr std::uint16_t mp5sd{ 23 };
		constexpr std::uint16_t ump45{ 24 };
		constexpr std::uint16_t xm1014{ 25 };
		constexpr std::uint16_t bizon{ 26 };
		constexpr std::uint16_t mag7{ 27 };
		constexpr std::uint16_t negev{ 28 };
		constexpr std::uint16_t sawed_off{ 29 };
		constexpr std::uint16_t tec9{ 30 };
		constexpr std::uint16_t p2000{ 32 };
		constexpr std::uint16_t mp7{ 33 };
		constexpr std::uint16_t mp9{ 34 };
		constexpr std::uint16_t nova{ 35 };
		constexpr std::uint16_t p250{ 36 };
		constexpr std::uint16_t scar20{ 38 };
		constexpr std::uint16_t sg553{ 39 };
		constexpr std::uint16_t ssg08{ 40 };
		constexpr std::uint16_t m4a1_s{ 60 };
		constexpr std::uint16_t usp_s{ 61 };
		constexpr std::uint16_t cz75{ 63 };
		constexpr std::uint16_t revolver{ 64 };

	} // namespace item_definitions

	enum class weapon_type : std::uint32_t
	{
		knife,
		pistol,
		submachine_gun,
		rifle,
		shotgun,
		sniper_rifle,
		machine_gun,
		c4,
		taser,
		grenade,
		equipment,
		healthshot
	};

	struct network_float
	{
		float value;
		std::uint32_t encoding;
	};

	struct network_vector
	{
		vector3 value;
		std::int16_t chain_offset;
		std::array<network_float, 3> quantized;
	};

	struct handle
	{
		std::uint32_t value{ 0xFFFFFFFF };

		[[nodiscard]] bool valid( ) const noexcept { return this->value != 0xFFFFFFFF && this->value != 0; }
		[[nodiscard]] int index( ) const noexcept { return static_cast< int >( this->value & 0x7FFF ); }
	};

	class game_scene_node
	{
	public:
		FIELD( vector3, transform_position, client::cgamescenenode::m_nodeToWorld )
		FIELD( bone_transform, node_to_world, client::cgamescenenode::m_nodeToWorld )
		FIELD( vector3, origin, client::cgamescenenode::m_vecOrigin )
		FIELD( vector3, rotation, client::cgamescenenode::m_angRotation )
		FIELD( vector3, abs_origin, client::cgamescenenode::m_vecAbsOrigin )
		FIELD( vector3, abs_rotation, client::cgamescenenode::m_angAbsRotation )
		FIELD( bool, dormant, client::cgamescenenode::m_bDormant )
		FIELD( sdk::model**, model, client::cskeletoninstance::m_modelState + client::cmodelstate::m_hModel )
		FIELD( bone_transform*, bone_cache, client::cskeletoninstance::m_modelState + 0x80 )
		FIELD( std::uint16_t, bone_count, client::cskeletoninstance::m_modelState + 0x94 )
		FIELD( bool, force_bone_setup, 0x118 )
	};

	class entity_identity
	{
	public:
		FIELD( sdk::handle, handle, 0x10 )
	};

	class collision_property
	{
	public:
		FIELD( vector3, mins, client::ccollisionproperty::m_vecMins )
		FIELD( vector3, maxs, client::ccollisionproperty::m_vecMaxs )
	};

	class base_entity
	{
	public:
		FIELD( entity_identity*, identity, client::centityinstance::m_pEntity )
		FIELD( game_scene_node*, scene_node, client::c_baseentity::m_pGameSceneNode )
		FIELD( collision_property*, collision, client::c_baseentity::m_pCollision )
		FIELD( int, health, client::c_baseentity::m_iHealth )
		FIELD( std::uint8_t, life_state, client::c_baseentity::m_lifeState )
		FIELD( std::uint8_t, team, client::c_baseentity::m_iTeamNum )
		FIELD( std::uint32_t, flags, client::c_baseentity::m_fFlags )
		FIELD( vector3, velocity, client::c_baseentity::m_vecAbsVelocity )
		FIELD( network_vector, network_velocity, client::c_baseentity::m_vecVelocity )
		FIELD( float, simulation_time, client::c_baseentity::m_flSimulationTime )
		FIELD( std::uint8_t, move_type, client::c_baseentity::m_nActualMoveType )

		template <typename type>
		[[nodiscard]] type* vdata( )
		{
			return *reinterpret_cast< type** >( reinterpret_cast< std::uintptr_t >( this ) + client::c_baseentity::m_nSubclassID + sizeof( std::uintptr_t ) );
		}
	};

	class base_model_entity : public base_entity
	{
	public:
		FIELD( network_vector, view_offset, client::c_basemodelentity::m_vecViewOffset )
	};

	using mode_values = std::array<float, 2>;

	class weapon_vdata
	{
	public:
		FIELD( const char*, name, client::ccsweaponbasevdata::m_szName )
		FIELD( weapon_type, type, client::ccsweaponbasevdata::m_WeaponType )
		FIELD( float, max_speed, client::ccsweaponbasevdata::m_flMaxSpeed )
		FIELD( mode_values, max_speeds, client::ccsweaponbasevdata::m_flMaxSpeed )
		FIELD( int, damage, client::ccsweaponbasevdata::m_nDamage )
		FIELD( float, penetration, client::ccsweaponbasevdata::m_flPenetration )
		FIELD( float, range, client::ccsweaponbasevdata::m_flRange )
		FIELD( float, range_modifier, client::ccsweaponbasevdata::m_flRangeModifier )
		FIELD( float, armor_ratio, client::ccsweaponbasevdata::m_flArmorRatio )
		FIELD( float, headshot_multiplier, client::ccsweaponbasevdata::m_flHeadshotMultiplier )
		FIELD( mode_values, spread, client::ccsweaponbasevdata::m_flSpread )
		FIELD( int, num_bullets, client::ccsweaponbasevdata::m_nNumBullets )
	};

	class cs_weapon_base : public base_model_entity
	{
	public:
		FIELD( int, clip, client::c_baseplayerweapon::m_iClip1 )
		FIELD( int, zoom_level, client::c_csweaponbasegun::m_zoomLevel )
		FIELD( int, next_primary_attack_tick, client::c_baseplayerweapon::m_nNextPrimaryAttackTick )
		FIELD( int, weapon_mode, client::c_csweaponbase::m_weaponMode )
		FIELD( float, recoil_index, client::c_csweaponbase::m_flRecoilIndex )
		FIELD( bool, in_reload, client::c_csweaponbase::m_bInReload )
		FIELD( std::uint16_t, item_definition_index, client::c_econentity::m_AttributeManager + client::c_attributecontainer::m_Item + client::c_econitemview::m_iItemDefinitionIndex )
	};

	class base_grenade : public cs_weapon_base
	{
	public:
		FIELD( bool, pin_pulled, client::c_basecsgrenade::m_bPinPulled )
		FIELD( float, throw_time, client::c_basecsgrenade::m_fThrowTime )
	};

	class move_data
	{
	public:
		FIELD( std::uint8_t, flags, 0x0 )
		FIELD( vector3, impulses, 0x20 )
		FIELD( vector3, velocity, 0x38 )
		FIELD( vector3, origin, 0xC8 )
		FIELD( int, previous_tick, 0xD4 )
		FIELD( int, tick, 0xD8 )
		FIELD( int, tick_offset, 0xDC )
		FIELD( float, tick_scale, 0xE0 )
	};

	using button_block = std::array<std::uint8_t, 0x30>;

	class movement_services
	{
	public:
		FIELD( button_block, held_buttons, client::cplayer_movementservices::m_nButtons + sizeof( void* ) )
		FIELD( std::uint64_t, toggle_buttons, client::cplayer_movementservices::m_nToggleButtonDownMask )
		FIELD( std::uint64_t, tick_presses, 0x198 )
		FIELD( button_block, held_snapshot, 0x1D8 )
		FIELD( std::uint64_t, toggle_snapshot, 0x208 )
		FIELD( std::uint64_t, tick_presses_final, 0x220 )
		FIELD( bool, ducked, client::ccsplayer_movementservices::m_bDucked )
		FIELD( float, duck_amount, client::ccsplayer_movementservices::m_flDuckAmount )
		FIELD( float, duck_offset, client::ccsplayer_movementservices::m_flDuckOffset )
		FIELD( float, stamina, client::ccsplayer_movementservices::m_flStamina )
		FIELD( float, surface_friction, client::cplayer_movementservices_humanoid::m_flSurfaceFriction )
		FIELD( vector3, last_movement_impulses, client::cplayer_movementservices::m_vecLastMovementImpulses )
		FIELD( std::int32_t, last_jump_tick, client::ccsplayer_movementservices::m_nLastJumpTick )
		FIELD( float, last_jump_fraction, client::ccsplayer_movementservices::m_flLastJumpFrac )
		FIELD( std::int32_t, last_landed_tick, client::ccsplayer_movementservices::m_ModernJump + client::ccsplayermodernjump::m_nLastLandedTick )
		FIELD( float, last_landed_fraction, client::ccsplayer_movementservices::m_ModernJump + client::ccsplayermodernjump::m_flLastLandedFrac )

		void update_input_state( user_cmd* cmd ) const { vfunc<26>( this, cmd ); }
		[[nodiscard]] sdk::move_data* move_data( ) const { return vfunc<34, sdk::move_data*>( this ); }
		void setup_move( user_cmd* cmd, sdk::move_data* data ) const { vfunc<35>( this, cmd, data ); }
	};

	struct shot_eye
	{
		std::int32_t tick;
		float fraction;
		vector3 position;
	};

	using shot_eye_ring = std::array<shot_eye, 32>;

	class weapon_services
	{
	public:
		FIELD( handle, active_weapon, client::cplayer_weaponservices::m_hActiveWeapon )
		FIELD( shot_eye_ring, shot_eyes, 0xE8 )
		FIELD( std::int32_t, shot_eye_tail, 0x368 )
		FIELD( std::int32_t, shot_eye_count, 0x36C )

		[[nodiscard]] vector3 shoot_position( ) const
		{
			vector3 out{};
			vfunc<28>( this, &out );
			return out;
		}
	};

	class item_services
	{
	public:
		FIELD( bool, has_helmet, client::ccsplayer_itemservices::m_bHasHelmet )
		FIELD( bool, has_defuser, client::ccsplayer_itemservices::m_bHasDefuser )
	};

	class base_player_pawn : public base_model_entity
	{
	public:
		FIELD( movement_services*, movement, client::c_baseplayerpawn::m_pMovementServices )
		FIELD( weapon_services*, weapons, client::c_baseplayerpawn::m_pWeaponServices )
		FIELD( item_services*, items, client::c_baseplayerpawn::m_pItemServices )
		FIELD( void*, camera, client::c_baseplayerpawn::m_pCameraServices )
		FIELD( handle, controller, client::c_baseplayerpawn::m_hController )
		FIELD( float, fov_sensitivity_adjust, client::c_baseplayerpawn::m_flFOVSensitivityAdjust )
	};

	class cs_player_pawn : public base_player_pawn
	{
	public:
		FIELD( bool, is_scoped, client::c_csplayerpawn::m_bIsScoped )
		FIELD( bool, is_defusing, client::c_csplayerpawn::m_bIsDefusing )
		FIELD( bool, gun_game_immunity, client::c_csplayerpawn::m_bGunGameImmunity )
		FIELD( int, armor, client::c_csplayerpawn::m_ArmorValue )
		FIELD( float, slope_drop_offset, client::c_csplayerpawn::m_flSlopeDropOffset )
		FIELD( float, flash_end_time, client::c_csplayerpawnbase::m_flFlashBangTime )
		FIELD( vector3, aim_punch_angle, client::c_csplayerpawn::m_aimPunchAngle )
		FIELD( vector3, aim_punch_velocity, client::c_csplayerpawn::m_aimPunchAngleVel )
		FIELD( int, aim_punch_tick_base, client::c_csplayerpawn::m_aimPunchTickBase )
		FIELD( float, aim_punch_tick_fraction, client::c_csplayerpawn::m_aimPunchTickFraction )

		[[nodiscard]] vector3 eye_position( ) const
		{
			vector3 out{};
			vfunc<166>( this, &out );
			return out;
		}
	};

	class prediction_data
	{
	public:
		FIELD( int, stored_frames, 0x138 )
	};

	class base_player_controller : public base_model_entity
	{
	public:
		FIELD( sdk::prediction_data*, prediction_data, 0x5A8 )
		FIELD( handle, pawn, client::cbaseplayercontroller::m_hPawn )
		FIELD( int, tick_base, client::cbaseplayercontroller::m_nTickBase )
	};

	class cs_player_controller : public base_player_controller
	{
	public:
		FIELD( handle, player_pawn, client::ccsplayercontroller::m_hPlayerPawn )
		FIELD( bool, pawn_alive, client::ccsplayercontroller::m_bPawnIsAlive )
		FIELD( const char*, name, client::ccsplayercontroller::m_sSanitizedPlayerName )
	};

	class entity_system
	{
	public:
		[[nodiscard]] base_entity* get( int index ) const;

		template <typename type>
		[[nodiscard]] type* get( handle h ) const
		{
			return h.valid( ) ? static_cast< type* >( this->get( h.index( ) ) ) : nullptr;
		}
	};

} // namespace opaline::sdk

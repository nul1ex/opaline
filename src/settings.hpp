#pragma once

#include <ui/config.hpp>

namespace opaline::settings {

	enum class weapon_group : std::size_t
	{
		ssg,
		awp,
		auto_sniper,
		heavy_pistol,
		light_pistol,
		rifle,
		shotgun,
		heavy_smg,
		light_smg,
		lmg,
		count
	};

	constexpr std::array<const char*, static_cast< std::size_t >( weapon_group::count )> k_weapon_group_names{ "ssg", "awp", "auto sniper", "heavy pistol", "light pistol", "rifle", "shotgun", "heavy smg", "light smg", "lmg" };

	struct rage_weapon
	{
		explicit rage_weapon( std::string_view group )
			: hitchance{ group, "hitchance", 75 }, min_damage{ group, "minimum damage", 100 }, head{ group, "head", true }, chest{ group, "chest", true }, stomach{ group, "stomach", true },
			arms{ group, "arms", false }, legs{ group, "legs", false }, feet{ group, "feet", false }, head_scale{ group, "head scale", 95 }, chest_scale{ group, "chest scale", 75 },
			stomach_scale{ group, "stomach scale", 75 }, autostop{ group, "autostop", true }, autostop_in_air{ group, "autostop in air", true },
			autostop_between_shots{ group, "autostop between shots", false } {}

		ui::setting<int> hitchance;
		ui::setting<int> min_damage;
		ui::setting<bool> head;
		ui::setting<bool> chest;
		ui::setting<bool> stomach;
		ui::setting<bool> arms;
		ui::setting<bool> legs;
		ui::setting<bool> feet;
		ui::setting<int> head_scale;
		ui::setting<int> chest_scale;
		ui::setting<int> stomach_scale;
		ui::setting<bool> autostop;
		ui::setting<bool> autostop_in_air;
		ui::setting<bool> autostop_between_shots;
	};

	struct rage
	{
		ui::setting<bool> enabled{ "rage", "enabled", false };

		std::array<rage_weapon, static_cast< std::size_t >( weapon_group::count )> weapons
		{
			rage_weapon{ "rage ssg" },
			rage_weapon{ "rage awp" },
			rage_weapon{ "rage auto sniper" },
			rage_weapon{ "rage heavy pistol" },
			rage_weapon{ "rage light pistol" },
			rage_weapon{ "rage rifle" },
			rage_weapon{ "rage shotgun" },
			rage_weapon{ "rage heavy smg" },
			rage_weapon{ "rage light smg" },
			rage_weapon{ "rage lmg" }
		};

		[[nodiscard]] rage_weapon& weapon( weapon_group group ) { return this->weapons[ static_cast< std::size_t >( group ) ]; }
	};

	namespace yaw_base {

		constexpr int view{ 0 };
		constexpr int at_targets{ 1 };

	} // namespace yaw_base

	constexpr std::array<const char*, 2> k_yaw_base_names{ "static", "at targets" };

	struct antiaim
	{
		ui::setting<bool> enabled{ "antiaim", "enabled", false };
		ui::setting<int> yaw_base{ "antiaim", "yaw base", yaw_base::view };
		ui::setting<int> yaw_offset{ "antiaim", "yaw offset", 180 };
		ui::setting<int> manual_left{ "antiaim", "manual left", 0 };
		ui::setting<int> manual_right{ "antiaim", "manual right", 0 };
	};

	struct esp
	{
		ui::setting<bool> enabled{ "esp", "enabled", true };
		ui::setting<bool> teammates{ "esp", "teammates", false };
		ui::setting<bool> box{ "esp", "box", true };
		ui::setting<ui::color> box_color{ "esp", "box color", { 1.0f, 1.0f, 1.0f, 1.0f } };
		ui::setting<bool> name{ "esp", "name", true };
		ui::setting<bool> health{ "esp", "health", true };
		ui::setting<bool> weapon{ "esp", "weapon", true };
		ui::setting<bool> flags{ "esp", "flags", true };
	};

	struct view
	{
		ui::setting<bool> change_fov{ "view", "custom fov", false };
		ui::setting<float> fov{ "view", "fov", 90.0f };
		ui::setting<float> scope_fov_1{ "view", "scope fov stage 1", 0.0f };
		ui::setting<float> scope_fov_2{ "view", "scope fov stage 2", 0.0f };

		ui::setting<bool> thirdperson{ "view", "thirdperson", false };
		ui::setting<float> thirdperson_distance{ "view", "thirdperson distance", 85.0f };

		ui::setting<bool> remove_scope{ "view", "remove scope", false };
	};

	struct movement
	{
		ui::setting<bool> bhop{ "movement", "bhop", false };
		ui::setting<bool> jumpbug{ "movement", "jumpbug", false };
		ui::setting<bool> jumpbug_keep_crouch{ "movement", "jumpbug keep crouch", false };
		ui::setting<bool> autostrafe{ "movement", "autostrafe", false };
		ui::setting<bool> autostrafe_movement_keys{ "movement", "autostrafe movement keys", true };
		ui::setting<bool> autostrafe_stop_on_shift{ "movement", "autostrafe stop on shift", false };
		ui::setting<bool> autostrafe_stop_on_release{ "movement", "autostrafe stop on key release", false };
		ui::setting<bool> slowwalk{ "movement", "slowwalk", false };
		ui::setting<int> slowwalk_key{ "movement", "slowwalk key", VK_SHIFT };
		ui::setting<int> slowwalk_speed{ "movement", "slowwalk speed", 34 };
	};

	struct misc
	{
		ui::setting<int> menu_key{ "misc", "menu key", VK_INSERT };
		ui::setting<ui::color> accent{ "misc", "accent", { 0.58f, 0.80f, 0.86f, 1.0f } };
	};

	inline rage g_rage{};
	inline antiaim g_antiaim{};
	inline esp g_esp{};
	inline view g_view{};
	inline movement g_movement{};
	inline misc g_misc{};

} // namespace opaline::settings

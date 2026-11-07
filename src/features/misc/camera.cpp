#include <pch.hpp>
#include <features/misc/camera.hpp>
#include <core/game.hpp>
#include <settings.hpp>

namespace opaline::misc {

	namespace detail {

		constexpr auto k_base_fov{ 90.0f };
		constexpr auto k_widescreen_scale{ 9.0f / 16.0f };
		constexpr auto k_camera_extent{ 9.0f };
		constexpr std::uint8_t k_first_playing_team{ 2 };

		constexpr auto k_camera_mask{ 0x80ull };
		constexpr auto k_camera_exclude_mask{ 0xc0000ull };
		constexpr std::uint8_t k_camera_layer{ 3 };
		constexpr int k_camera_filter_type{ 0x0f };

		[[nodiscard]] static sdk::vector3 forward( const sdk::vector3& angles )
		{
			const auto pitch = angles.x * sdk::k_rad_per_deg;
			const auto yaw = angles.y * sdk::k_rad_per_deg;

			return { std::cos( pitch ) * std::cos( yaw ), std::cos( pitch ) * std::sin( yaw ), -std::sin( pitch ) };
		}

	} // namespace detail

	void camera::override_view( sdk::view_setup* setup )
	{
		this->m_last_game_fov = setup->fov( );

		const auto pawn = core::local_pawn( core::local_controller( ) );

		if ( !pawn || pawn->team( ) < detail::k_first_playing_team )
		{
			return;
		}

		this->thirdperson( setup, pawn );

		if ( settings::g_view.change_fov.get( ) )
		{
			setup->fov( ) = this->wanted_fov( );
		}
	}

	void camera::update_fov_sensitivity( sdk::cs_player_pawn* pawn ) const
	{
		if ( !settings::g_view.change_fov.get( ) || pawn != core::local_pawn( core::local_controller( ) ) )
		{
			return;
		}

		auto& adjust = pawn->fov_sensitivity_adjust( );
		if ( adjust == 1.0f )
		{
			return;
		}

		adjust = core::g_game.zoom_sensitivity_ratio->get<float>( ) * ( this->wanted_fov( ) / detail::k_base_fov );
	}

	void camera::thirdperson( sdk::view_setup* setup, sdk::cs_player_pawn* pawn ) const
	{
		const auto& cfg = settings::g_view;
		if ( !cfg.thirdperson.get( ) )
		{
			return;
		}

		const auto eye = pawn->eye_position( );
		const auto wanted = eye - detail::forward( core::view_angles( ) ) * cfg.thirdperson_distance.get( );
		const auto scale = setup->aspect_ratio( ) * detail::k_widescreen_scale;
		const auto mins = sdk::vector3{ -detail::k_camera_extent * scale, -detail::k_camera_extent * scale, -detail::k_camera_extent };
		const auto maxs = sdk::vector3{ detail::k_camera_extent * scale, detail::k_camera_extent * scale, detail::k_camera_extent };

		auto filter = core::trace_filter( pawn, detail::k_camera_mask, detail::k_camera_layer, detail::k_camera_filter_type );
		filter.exclude_mask = detail::k_camera_exclude_mask;
		filter.unknown_34 = -1;

		const auto result = core::trace_hull( eye, wanted, mins, maxs, filter );
		setup->origin( ) = eye + ( wanted - eye ) * std::min( result.fraction, 1.0f );
	}

	float camera::wanted_fov( ) const
	{
		const auto& cfg = settings::g_view;
		const auto custom = cfg.fov.get( );
		const auto pawn = core::local_pawn( core::local_controller( ) );

		if ( !pawn || !pawn->is_scoped( ) )
		{
			return custom;
		}

		const auto services = pawn->weapons( );
		const auto weapon = services ? core::entities( )->get<sdk::cs_weapon_base>( services->active_weapon( ) ) : nullptr;
		const auto stage = weapon ? weapon->zoom_level( ) : 0;

		if ( stage <= 0 )
		{
			return custom;
		}

		const auto percent = std::clamp( stage >= 2 ? cfg.scope_fov_2.get( ) : cfg.scope_fov_1.get( ), 0.0f, 100.0f ) / 100.0f;
		return this->m_last_game_fov + ( custom - this->m_last_game_fov ) * percent;
	}

} // namespace opaline::misc

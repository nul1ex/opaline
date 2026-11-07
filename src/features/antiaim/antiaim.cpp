#include <pch.hpp>
#include <features/antiaim/antiaim.hpp>
#include <core/game.hpp>
#include <settings.hpp>

namespace opaline::antiaim {

	namespace detail {

		constexpr auto k_max_players{ 64 };
		constexpr auto k_pitch_down{ 89.0f };
		constexpr auto k_manual_yaw{ 90.0f };

		[[nodiscard]] static bool throwing_grenade( const input::command& command, sdk::cs_player_pawn* pawn )
		{
			const auto services = pawn->weapons( );
			const auto weapon = services ? core::entities( )->get<sdk::base_grenade>( services->active_weapon( ) ) : nullptr;
			const auto vdata = weapon ? weapon->vdata<sdk::weapon_vdata>( ) : nullptr;

			if ( !vdata || vdata->type( ) != sdk::weapon_type::grenade )
			{
				return false;
			}

			return weapon->throw_time( ) > 0.0f || ( weapon->pin_pulled( ) && !command.holds( sdk::buttons::attack | sdk::buttons::attack2 ) );
		}

		[[nodiscard]] static std::optional<float> target_yaw( sdk::cs_player_pawn* local, float view_yaw )
		{
			const auto system = core::entities( );
			const auto controller = core::local_controller( );
			const auto origin = local->scene_node( )->origin( );

			std::optional<float> best{};
			auto best_fov{ std::numeric_limits<float>::max( ) };

			for ( auto index = 1; index <= k_max_players; ++index )
			{
				const auto owner = static_cast< sdk::cs_player_controller* >( system->get( index ) );

				if ( !owner || owner == controller || !owner->pawn_alive( ) )
				{
					continue;
				}

				const auto pawn = system->get<sdk::cs_player_pawn>( owner->player_pawn( ) );
				const auto node = pawn ? pawn->scene_node( ) : nullptr;

				if ( !node || pawn == local || pawn->health( ) <= 0 || node->dormant( ) || !core::is_enemy( local->team( ), pawn->team( ) ) )
				{
					continue;
				}

				const auto delta = node->origin( ) - origin;
				const auto yaw = std::atan2( delta.y, delta.x ) * sdk::k_deg_per_rad;
				const auto fov = std::fabs( sdk::normalize_yaw( yaw - view_yaw ) );

				if ( fov < best_fov )
				{
					best = yaw;
					best_fov = fov;
				}
			}

			return best;
		}

	} // namespace detail

	void antiaim::run( input::command& command ) const
	{
		const auto& cfg = settings::g_antiaim;
		const auto& start = prediction::g_engine.start( );
		const auto pawn = prediction::g_engine.pawn( );

		if ( !cfg.enabled.get( ) || command.holds( sdk::buttons::use ) || start.move_type == sdk::move_types::ladder || start.move_type == sdk::move_types::noclip || detail::throwing_grenade( command, pawn ) )
		{
			return;
		}

		const auto view_yaw = core::view_angles( ).y;
		auto yaw = view_yaw;

		switch ( this->m_manual.load( ) )
		{
		case manual::left:
			yaw += detail::k_manual_yaw;
			break;
		case manual::right:
			yaw -= detail::k_manual_yaw;
			break;
		default:
			yaw = ( cfg.yaw_base.get( ) == settings::yaw_base::at_targets ? detail::target_yaw( pawn, view_yaw ).value_or( view_yaw ) : view_yaw ) + static_cast< float >( cfg.yaw_offset.get( ) );
			break;
		}

		command.turn( detail::k_pitch_down, sdk::normalize_yaw( yaw ) );
	}

	void antiaim::on_key( int key )
	{
		const auto& cfg = settings::g_antiaim;
		const auto side = key == cfg.manual_left.get( ) ? manual::left : key == cfg.manual_right.get( ) ? manual::right : manual::none;

		if ( side != manual::none )
		{
			this->m_manual.store( this->m_manual.load( ) == side ? manual::none : side );
		}
	}

} // namespace opaline::antiaim

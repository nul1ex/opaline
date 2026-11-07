#include <pch.hpp>
#include <features/visuals/esp.hpp>
#include <core/game.hpp>
#include <settings.hpp>

namespace opaline::visuals {

	namespace detail {

		constexpr auto k_max_players{ 64 };
		constexpr auto k_name_limit{ 128ull };
		constexpr auto k_weapon_limit{ 64ull };
		constexpr auto k_weapon_prefix{ std::string_view{ "weapon_" } };
		constexpr auto k_min_depth{ 0.01f };
		constexpr auto k_stale{ std::chrono::milliseconds( 200 ) };

		constexpr auto k_bar_width{ 2.0f };
		constexpr auto k_bar_gap{ 4.0f };
		constexpr auto k_text_gap{ 2.0f };
		constexpr auto k_flag_gap{ 4.0f };

		constexpr auto k_outline{ IM_COL32( 0, 0, 0, 200 ) };
		constexpr auto k_text{ IM_COL32( 255, 255, 255, 255 ) };
		constexpr auto k_flag{ IM_COL32( 225, 225, 225, 255 ) };

		[[nodiscard]] static std::string lowercase( const char* text, std::size_t limit )
		{
			if ( !text )
			{
				return {};
			}

			std::string out( text, strnlen( text, limit ) );
			std::ranges::transform( out, out.begin( ), [ ]( unsigned char c ) { return static_cast< char >( std::tolower( c ) ); } );

			return out;
		}

		[[nodiscard]] static std::string weapon_name( sdk::cs_player_pawn* pawn )
		{
			const auto services = pawn->weapons( );
			const auto weapon = services ? core::entities( )->get<sdk::cs_weapon_base>( services->active_weapon( ) ) : nullptr;
			const auto vdata = weapon ? weapon->vdata<sdk::weapon_vdata>( ) : nullptr;

			auto name = vdata ? lowercase( vdata->name( ), k_weapon_limit ) : std::string{};

			if ( name.starts_with( k_weapon_prefix ) )
			{
				name.erase( 0, k_weapon_prefix.size( ) );
			}

			return name;
		}

		[[nodiscard]] static std::optional<ImVec2> project( const sdk::matrix4x4& matrix, const sdk::vector3& point, const ImVec2& screen )
		{
			const auto& m = matrix.m;
			const auto w = m[ 3 ][ 0 ] * point.x + m[ 3 ][ 1 ] * point.y + m[ 3 ][ 2 ] * point.z + m[ 3 ][ 3 ];

			if ( w < k_min_depth )
			{
				return std::nullopt;
			}

			const auto x = m[ 0 ][ 0 ] * point.x + m[ 0 ][ 1 ] * point.y + m[ 0 ][ 2 ] * point.z + m[ 0 ][ 3 ];
			const auto y = m[ 1 ][ 0 ] * point.x + m[ 1 ][ 1 ] * point.y + m[ 1 ][ 2 ] * point.z + m[ 1 ][ 3 ];

			return ImVec2{ screen.x * 0.5f * ( 1.0f + x / w ), screen.y * 0.5f * ( 1.0f - y / w ) };
		}

		[[nodiscard]] static std::optional<std::pair<ImVec2, ImVec2>> project_box( const sdk::matrix4x4& matrix, const sdk::vector3& mins, const sdk::vector3& maxs, const ImVec2& screen )
		{
			ImVec2 low{ FLT_MAX, FLT_MAX };
			ImVec2 high{ -FLT_MAX, -FLT_MAX };

			for ( auto corner = 0; corner < 8; ++corner )
			{
				const auto point = sdk::vector3{ corner & 1 ? maxs.x : mins.x, corner & 2 ? maxs.y : mins.y, corner & 4 ? maxs.z : mins.z };
				const auto projected = project( matrix, point, screen );

				if ( !projected )
				{
					return std::nullopt;
				}

				low = { std::min( low.x, projected->x ), std::min( low.y, projected->y ) };
				high = { std::max( high.x, projected->x ), std::max( high.y, projected->y ) };
			}

			return std::pair{ ImVec2{ std::floor( low.x ), std::floor( low.y ) }, ImVec2{ std::floor( high.x ), std::floor( high.y ) } };
		}

		static void text( ImDrawList* draw_list, const ImVec2& position, ImU32 color, std::string_view value )
		{
			draw_list->AddText( { position.x + 1.0f, position.y + 1.0f }, k_outline, value.data( ), value.data( ) + value.size( ) );
			draw_list->AddText( position, color, value.data( ), value.data( ) + value.size( ) );
		}

		[[nodiscard]] static ImU32 health_color( float fraction )
		{
			return ImGui::ColorConvertFloat4ToU32( { 0.95f - 0.45f * fraction, 0.3f + 0.6f * fraction, 0.3f, 1.0f } );
		}

	} // namespace detail

	void esp::collect( )
	{
		std::vector<player> players{};

		const auto& cfg = settings::g_esp;
		const auto controller = core::local_controller( );
		const auto system = core::entities( );
		const auto globals = core::globals( );

		if ( cfg.enabled.get( ) && controller && system && globals )
		{
			const auto local_pawn = system->get<sdk::cs_player_pawn>( controller->player_pawn( ) );
			const auto current_time = globals->current_time( );

			for ( auto index = 1; index <= detail::k_max_players; ++index )
			{
				const auto owner = static_cast< sdk::cs_player_controller* >( system->get( index ) );

				if ( !owner || owner == controller || !owner->pawn_alive( ) )
				{
					continue;
				}

				const auto pawn = system->get<sdk::cs_player_pawn>( owner->player_pawn( ) );

				if ( !pawn || pawn == local_pawn || pawn->health( ) <= 0 || ( !cfg.teammates.get( ) && !core::is_enemy( controller->team( ), pawn->team( ) ) ) )
				{
					continue;
				}

				const auto node = pawn->scene_node( );
				const auto collision = pawn->collision( );

				if ( !node || !collision || node->dormant( ) )
				{
					continue;
				}

				const auto origin = node->abs_origin( );
				const auto items = pawn->items( );

				players.push_back
				( {
					origin + collision->mins( ),
					origin + collision->maxs( ),
					detail::lowercase( owner->name( ), detail::k_name_limit ),
					detail::weapon_name( pawn ),
					pawn->health( ),
					pawn->armor( ),
					items && items->has_helmet( ),
					pawn->is_scoped( ),
					pawn->flash_end_time( ) > current_time,
					pawn->is_defusing( )
				} );
			}
		}

		std::scoped_lock lock( this->m_mutex );

		this->m_players = std::move( players );
		this->m_view_matrix = *core::g_game.view_matrix;
		this->m_collected = std::chrono::steady_clock::now( );
	}

	void esp::draw( ImDrawList* draw_list )
	{
		const auto screen = ImGui::GetIO( ).DisplaySize;

		std::scoped_lock lock( this->m_mutex );

		if ( std::chrono::steady_clock::now( ) - this->m_collected > detail::k_stale )
		{
			return;
		}

		for ( const auto& target : this->m_players )
		{
			if ( const auto bounds = detail::project_box( this->m_view_matrix, target.mins, target.maxs, screen ) )
			{
				this->draw_player( draw_list, target, bounds->first, bounds->second );
			}
		}
	}

	void esp::draw_player( ImDrawList* draw_list, const player& target, const ImVec2& min, const ImVec2& max ) const
	{
		const auto& cfg = settings::g_esp;

		if ( cfg.box.get( ) )
		{
			const auto& color = cfg.box_color.get( );

			draw_list->AddRect( { min.x - 1.0f, min.y - 1.0f }, { max.x + 1.0f, max.y + 1.0f }, detail::k_outline );
			draw_list->AddRect( { min.x + 1.0f, min.y + 1.0f }, { max.x - 1.0f, max.y - 1.0f }, detail::k_outline );
			draw_list->AddRect( min, max, ImGui::ColorConvertFloat4ToU32( color.vec4( color.a ) ) );
		}

		if ( cfg.health.get( ) )
		{
			const auto fraction = std::clamp( static_cast< float >( target.health ) / 100.0f, 0.0f, 1.0f );
			const auto right = min.x - detail::k_bar_gap;
			const auto left = right - detail::k_bar_width;
			const auto top = std::floor( max.y - ( max.y - min.y ) * fraction );

			draw_list->AddRectFilled( { left - 1.0f, min.y - 1.0f }, { right + 1.0f, max.y + 1.0f }, detail::k_outline );
			draw_list->AddRectFilled( { left, top }, { right, max.y }, detail::health_color( fraction ) );
		}

		if ( cfg.name.get( ) && !target.name.empty( ) )
		{
			const auto size = ImGui::CalcTextSize( target.name.c_str( ) );
			detail::text( draw_list, { std::floor( ( min.x + max.x - size.x ) * 0.5f ), min.y - size.y - detail::k_text_gap }, detail::k_text, target.name );
		}

		if ( cfg.weapon.get( ) && !target.weapon.empty( ) )
		{
			const auto size = ImGui::CalcTextSize( target.weapon.c_str( ) );
			detail::text( draw_list, { std::floor( ( min.x + max.x - size.x ) * 0.5f ), max.y + detail::k_text_gap }, detail::k_text, target.weapon );
		}

		if ( cfg.flags.get( ) )
		{
			auto y = min.y;

			const auto add = [ & ]( std::string_view flag )
				{
					detail::text( draw_list, { max.x + detail::k_flag_gap, y }, detail::k_flag, flag );
					y += ImGui::GetTextLineHeight( );
				};

			if ( target.armor > 0 )
			{
				add( target.helmet ? "hk" : "k" );
			}

			if ( target.scoped )
			{
				add( "scoped" );
			}

			if ( target.flashed )
			{
				add( "flashed" );
			}

			if ( target.defusing )
			{
				add( "defusing" );
			}
		}
	}

} // namespace opaline::visuals

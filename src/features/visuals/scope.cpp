#include <pch.hpp>
#include <features/visuals/scope.hpp>
#include <core/game.hpp>
#include <settings.hpp>

namespace opaline::visuals {

	namespace detail {

		constexpr auto k_line_color{ IM_COL32( 0, 0, 0, 255 ) };

	} // namespace detail

	void scope::collect( )
	{
		const auto pawn = core::local_pawn( core::local_controller( ) );
		this->m_visible.store( settings::g_view.remove_scope.get( ) && pawn && pawn->is_scoped( ) );
	}

	void scope::draw( ImDrawList* draw_list ) const
	{
		if ( !this->m_visible.load( ) )
		{
			return;
		}

		const auto screen = ImGui::GetIO( ).DisplaySize;
		const auto center_x = std::floor( screen.x * 0.5f );
		const auto center_y = std::floor( screen.y * 0.5f );

		draw_list->AddRectFilled( { 0.0f, center_y }, { screen.x, center_y + 1.0f }, detail::k_line_color );
		draw_list->AddRectFilled( { center_x, 0.0f }, { center_x + 1.0f, screen.y }, detail::k_line_color );
	}

} // namespace opaline::visuals

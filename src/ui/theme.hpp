#pragma once

#include <ui/config.hpp>

namespace opaline::ui {

	namespace palette {

		constexpr auto k_outline{ IM_COL32( 0, 0, 0, 255 ) };
		constexpr auto k_edge{ IM_COL32( 44, 44, 50, 255 ) };
		constexpr auto k_background{ IM_COL32( 19, 19, 22, 255 ) };
		constexpr auto k_header{ IM_COL32( 25, 25, 29, 255 ) };
		constexpr auto k_field{ IM_COL32( 32, 32, 37, 255 ) };
		constexpr auto k_field_hovered{ IM_COL32( 40, 40, 46, 255 ) };
		constexpr auto k_field_active{ IM_COL32( 26, 26, 30, 255 ) };
		constexpr auto k_row_hovered{ IM_COL32( 47, 47, 54, 255 ) };
		constexpr auto k_text{ IM_COL32( 208, 208, 214, 255 ) };
		constexpr auto k_text_dim{ IM_COL32( 118, 118, 128, 255 ) };

	} // namespace palette

	class theme
	{
	public:
		void initialize( );
		void apply( const color& accent );

		[[nodiscard]] ImFont* bold( ) const noexcept { return this->m_bold; }
		[[nodiscard]] ImU32 accent( ) const noexcept { return this->m_accent; }

	private:
		ImFont* m_bold{};
		ImU32 m_accent{};
	};

	inline theme g_theme{};

} // namespace opaline::ui

#include <pch.hpp>
#include <ui/theme.hpp>
#include <ui/font_data.hpp>

namespace opaline::ui {

	namespace detail {

		static ImFont* add_font( std::span<const std::uint8_t> data )
		{
			ImFontConfig config{};
			config.FontDataOwnedByAtlas = false;
			config.PixelSnapH = true;
			config.OversampleH = 1;
			config.OversampleV = 1;

			return ImGui::GetIO( ).Fonts->AddFontFromMemoryTTF( const_cast< std::uint8_t* >( data.data( ) ), static_cast< int >( data.size( ) ), font_data::k_size, &config );
		}

		[[nodiscard]] static ImVec4 vec4( ImU32 color, float alpha = 1.0f )
		{
			auto out = ImGui::ColorConvertU32ToFloat4( color );
			out.w = alpha;

			return out;
		}

	} // namespace detail

	void theme::initialize( )
	{
		detail::add_font( font_data::k_regular );
		this->m_bold = detail::add_font( font_data::k_bold );
	}

	void theme::apply( const color& accent )
	{
		this->m_accent = ImGui::ColorConvertFloat4ToU32( accent.vec4( 1.0f ) );

		auto& style = ImGui::GetStyle( );

		style.WindowPadding = { 6.0f, 6.0f };
		style.FramePadding = { 6.0f, 3.0f };
		style.ItemSpacing = { 8.0f, 6.0f };
		style.ItemInnerSpacing = { 6.0f, 4.0f };
		style.ScrollbarSize = 6.0f;
		style.GrabMinSize = 8.0f;
		style.DisabledAlpha = 0.4f;
		style.WindowRounding = 0.0f;
		style.ChildRounding = 0.0f;
		style.FrameRounding = 0.0f;
		style.PopupRounding = 0.0f;
		style.GrabRounding = 0.0f;
		style.TabRounding = 0.0f;
		style.ScrollbarRounding = 0.0f;
		style.WindowBorderSize = 1.0f;
		style.PopupBorderSize = 1.0f;
		style.FrameBorderSize = 1.0f;
		style.ChildBorderSize = 0.0f;

		auto* colors = style.Colors;

		colors[ ImGuiCol_Text ] = detail::vec4( palette::k_text );
		colors[ ImGuiCol_TextDisabled ] = detail::vec4( palette::k_text_dim );
		colors[ ImGuiCol_WindowBg ] = detail::vec4( palette::k_background );
		colors[ ImGuiCol_ChildBg ] = detail::vec4( palette::k_background, 0.0f );
		colors[ ImGuiCol_PopupBg ] = detail::vec4( palette::k_field );
		colors[ ImGuiCol_Border ] = detail::vec4( palette::k_outline );
		colors[ ImGuiCol_BorderShadow ] = detail::vec4( palette::k_outline, 0.0f );
		colors[ ImGuiCol_FrameBg ] = detail::vec4( palette::k_field );
		colors[ ImGuiCol_FrameBgHovered ] = detail::vec4( palette::k_field_hovered );
		colors[ ImGuiCol_FrameBgActive ] = detail::vec4( palette::k_field_hovered );
		colors[ ImGuiCol_TitleBg ] = detail::vec4( palette::k_header );
		colors[ ImGuiCol_TitleBgActive ] = detail::vec4( palette::k_header );
		colors[ ImGuiCol_TitleBgCollapsed ] = detail::vec4( palette::k_header );
		colors[ ImGuiCol_ScrollbarBg ] = detail::vec4( palette::k_field, 0.0f );
		colors[ ImGuiCol_ScrollbarGrab ] = detail::vec4( palette::k_edge );
		colors[ ImGuiCol_ScrollbarGrabHovered ] = detail::vec4( palette::k_row_hovered );
		colors[ ImGuiCol_ScrollbarGrabActive ] = detail::vec4( this->m_accent );
		colors[ ImGuiCol_CheckMark ] = detail::vec4( this->m_accent );
		colors[ ImGuiCol_SliderGrab ] = detail::vec4( this->m_accent );
		colors[ ImGuiCol_SliderGrabActive ] = detail::vec4( this->m_accent );
		colors[ ImGuiCol_Button ] = detail::vec4( palette::k_field );
		colors[ ImGuiCol_ButtonHovered ] = detail::vec4( palette::k_field_hovered );
		colors[ ImGuiCol_ButtonActive ] = detail::vec4( palette::k_field_active );
		colors[ ImGuiCol_Header ] = detail::vec4( palette::k_row_hovered );
		colors[ ImGuiCol_HeaderHovered ] = detail::vec4( palette::k_row_hovered );
		colors[ ImGuiCol_HeaderActive ] = detail::vec4( palette::k_row_hovered );
		colors[ ImGuiCol_Separator ] = detail::vec4( palette::k_outline );
		colors[ ImGuiCol_TextSelectedBg ] = detail::vec4( this->m_accent, 0.35f );
		colors[ ImGuiCol_InputTextCursor ] = detail::vec4( palette::k_text );
		colors[ ImGuiCol_NavCursor ] = detail::vec4( this->m_accent );
	}

} // namespace opaline::ui

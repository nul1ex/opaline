#include <pch.hpp>
#include <ui/widgets.hpp>
#include <ui/input.hpp>
#include <ui/theme.hpp>

#include <imgui_internal.h>

namespace opaline::ui::widgets {

	namespace detail {

		constexpr auto k_window_flags{ ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoBackground };
		constexpr auto k_child_flags{ ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse };
		constexpr auto k_popup_flags{ ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings };
		constexpr auto k_picker_flags{ ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoSmallPreview | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_AlphaBar };

		constexpr auto k_border{ 2.0f };
		constexpr auto k_header_height{ 26.0f };
		constexpr auto k_header_padding{ 10.0f };
		constexpr auto k_tab_spacing{ 14.0f };
		constexpr auto k_underline{ 2.0f };
		constexpr auto k_body_padding{ 10.0f };
		constexpr auto k_column_gap{ 10.0f };
		constexpr auto k_section_padding{ 10.0f };
		constexpr auto k_title_inset{ 8.0f };
		constexpr auto k_title_gap{ 3.0f };
		constexpr auto k_title_offset{ 8.0f };
		constexpr auto k_check_size{ 9.0f };
		constexpr auto k_check_gap{ 6.0f };
		constexpr auto k_bar_height{ 7.0f };
		constexpr auto k_bar_gap{ 3.0f };
		constexpr auto k_bar_slack{ 3.0f };
		constexpr auto k_field_gap{ 2.0f };
		constexpr auto k_option_height{ 18.0f };
		constexpr auto k_text_inset{ 6.0f };
		constexpr auto k_inline_gap{ 6.0f };
		constexpr auto k_dropdown_gap{ 4.0f };
		constexpr auto k_dropdown_padding{ 8.0f };
		constexpr auto k_arrow_width{ 5 };
		constexpr auto k_settings_width{ 9 };
		constexpr std::array k_settings_icon{ 0b001000000, 0b111111111, 0b001000000, 0b000000000, 0b000000100, 0b111111111, 0b000000100 };
		constexpr auto k_swatch{ ImVec2{ 17.0f, 9.0f } };
		constexpr auto k_popup_padding{ 6.0f };
		constexpr auto k_picker_width{ 160.0f };

		[[nodiscard]] static ImU32 styled( ImU32 color )
		{
			return ImGui::GetColorU32( color );
		}

		[[nodiscard]] static ImRect inset( const ImRect& rect, float amount )
		{
			return { rect.Min.x + amount, rect.Min.y + amount, rect.Max.x - amount, rect.Max.y - amount };
		}

		[[nodiscard]] static float centered( float extent, float size )
		{
			return std::floor( ( extent - size ) * 0.5f );
		}

		[[nodiscard]] static std::string_view shown( const char* label )
		{
			return { label, ImGui::FindRenderedTextEnd( label ) };
		}

		[[nodiscard]] static float text_width( std::string_view value )
		{
			return ImGui::CalcTextSize( value.data( ), value.data( ) + value.size( ) ).x;
		}

		static void fill( const ImRect& rect, ImU32 color )
		{
			ImGui::GetWindowDrawList( )->AddRectFilled( rect.Min, rect.Max, styled( color ) );
		}

		static void outline( const ImRect& rect, ImU32 color )
		{
			fill( { rect.Min.x, rect.Min.y, rect.Max.x, rect.Min.y + 1.0f }, color );
			fill( { rect.Min.x, rect.Max.y - 1.0f, rect.Max.x, rect.Max.y }, color );
			fill( { rect.Min.x, rect.Min.y + 1.0f, rect.Min.x + 1.0f, rect.Max.y - 1.0f }, color );
			fill( { rect.Max.x - 1.0f, rect.Min.y + 1.0f, rect.Max.x, rect.Max.y - 1.0f }, color );
		}

		static void field( const ImRect& rect, ImU32 color )
		{
			fill( rect, palette::k_outline );
			fill( inset( rect, 1.0f ), color );
		}

		static void text( const ImVec2& position, ImU32 color, std::string_view value )
		{
			ImGui::GetWindowDrawList( )->AddText( ImFloor( position ), styled( color ), value.data( ), value.data( ) + value.size( ) );
		}

		static void arrow( const ImVec2& position, ImU32 color )
		{
			for ( auto row = 0; row < ( k_arrow_width + 1 ) / 2; ++row )
			{
				const auto offset = static_cast< float >( row );
				fill( { position.x + offset, position.y + offset, position.x + static_cast< float >( k_arrow_width ) - offset, position.y + offset + 1.0f }, color );
			}
		}

		[[nodiscard]] static ImRect inline_rect( float width )
		{
			auto* window = ImGui::GetCurrentWindow( );
			const auto& last = ImGui::GetCurrentContext( )->LastItemData.Rect;
			const auto edge = window->ContentRegionRect.Max.x;
			const auto right = std::floor( last.Max.x >= edge - 1.0f ? last.Min.x - k_inline_gap : edge );

			ImGui::SameLine( );

			const auto top = window->DC.CursorPos.y;
			const auto bb = ImRect{ std::floor( right - width ), top, right, top + ImGui::GetFontSize( ) };

			ImGui::SetCursorScreenPos( bb.Min );
			ImGui::ItemSize( bb );

			return bb;
		}

		[[nodiscard]] static bool lit( int row, int column, int width )
		{
			return ( ( row >> ( width - 1 - column ) ) & 1 ) != 0;
		}

		static void sprite( const ImVec2& position, std::span<const int> rows, int width, ImU32 color )
		{
			for ( auto y = 0; y < static_cast< int >( rows.size( ) ); ++y )
			{
				const auto row = rows[ static_cast< std::size_t >( y ) ];

				for ( auto start = 0; start < width; ++start )
				{
					if ( !lit( row, start, width ) )
					{
						continue;
					}

					auto end = start + 1;

					while ( end < width && lit( row, end, width ) )
					{
						++end;
					}

					fill( { position.x + static_cast< float >( start ), position.y + static_cast< float >( y ), position.x + static_cast< float >( end ), position.y + static_cast< float >( y + 1 ) }, color );
					start = end;
				}
			}
		}

		static void draw_tabs( const ImRect& header, float text_y, std::span<const char* const> labels, int& selected )
		{
			auto* window = ImGui::GetCurrentWindow( );
			auto width = k_tab_spacing * static_cast< float >( labels.size( ) - 1 );

			for ( const auto label : labels )
			{
				width += text_width( label );
			}

			auto x = header.Max.x - k_header_padding - width;

			for ( auto index = 0; index < static_cast< int >( labels.size( ) ); ++index )
			{
				const auto label = labels[ static_cast< std::size_t >( index ) ];
				const auto label_width = text_width( label );
				const auto id = window->GetID( label );
				const auto bb = ImRect{ x - k_tab_spacing * 0.5f, header.Min.y, x + label_width + k_tab_spacing * 0.5f, header.Max.y };

				if ( ImGui::ItemAdd( bb, id ) )
				{
					auto hovered{ false };
					auto held{ false };

					if ( ImGui::ButtonBehavior( bb, id, &hovered, &held ) )
					{
						selected = index;
					}

					const auto active = index == selected;
					text( { x, text_y }, active || hovered ? palette::k_text : palette::k_text_dim, label );

					if ( active )
					{
						fill( { x, header.Max.y - k_underline, x + label_width, header.Max.y }, g_theme.accent( ) );
					}
				}

				x += label_width + k_tab_spacing;
			}
		}

		[[nodiscard]] static bool option( std::string_view label, bool selected )
		{
			auto* window = ImGui::GetCurrentWindow( );
			const auto id = window->GetID( label.data( ), label.data( ) + label.size( ) );
			const auto position = window->DC.CursorPos;
			const auto bb = ImRect{ position.x, position.y, position.x + std::floor( ImGui::GetContentRegionAvail( ).x ), position.y + k_option_height };

			ImGui::ItemSize( bb );

			if ( !ImGui::ItemAdd( bb, id ) )
			{
				return false;
			}

			auto hovered{ false };
			auto held{ false };
			const auto pressed = ImGui::ButtonBehavior( bb, id, &hovered, &held );

			if ( hovered )
			{
				fill( bb, palette::k_row_hovered );
			}

			text( { bb.Min.x + k_text_inset, bb.Min.y + centered( k_option_height, ImGui::GetFontSize( ) ) }, selected ? g_theme.accent( ) : palette::k_text, label );
			return pressed;
		}

		template <typename type>
		[[nodiscard]] static bool slider( const char* label, type& value, type min, type max, std::string_view format )
		{
			auto* window = ImGui::GetCurrentWindow( );
			if ( window->SkipItems )
			{
				return false;
			}

			const auto id = window->GetID( label );
			const auto position = ImFloor( window->DC.CursorPos );
			const auto bb = ImRect{ position.x, position.y, position.x + std::floor( ImGui::GetContentRegionAvail( ).x ), position.y + ImGui::GetFontSize( ) + k_bar_gap + k_bar_height };
			const auto bar = ImRect{ bb.Min.x, bb.Max.y - k_bar_height, bb.Max.x, bb.Max.y };

			ImGui::ItemSize( bb );

			if ( !ImGui::ItemAdd( bb, id ) )
			{
				return false;
			}

			auto hovered{ false };
			auto held{ false };
			ImGui::ButtonBehavior( { bar.Min.x, bar.Min.y - k_bar_slack, bar.Max.x, bar.Max.y + k_bar_slack }, id, &hovered, &held, ImGuiButtonFlags_PressedOnClick );

			const auto track = inset( bar, 1.0f );
			const auto previous = value;

			if ( held )
			{
				const auto fraction = std::clamp( ( ImGui::GetIO( ).MousePos.x - track.Min.x ) / track.GetWidth( ), 0.0f, 1.0f );
				value = static_cast< type >( min + std::round( fraction * static_cast< float >( max - min ) ) );
			}
			else if ( ImGui::IsItemHovered( ) && ImGui::IsKeyPressed( ImGuiKey_LeftArrow ) )
			{
				value = std::max( min, static_cast< type >( value - 1 ) );
			}
			else if ( ImGui::IsItemHovered( ) && ImGui::IsKeyPressed( ImGuiKey_RightArrow ) )
			{
				value = std::min( max, static_cast< type >( value + 1 ) );
			}

			const auto changed = value != previous;
			if ( changed )
			{
				ImGui::MarkItemEdited( id );
			}

			const auto fraction = static_cast< float >( value - min ) / static_cast< float >( max - min );
			const auto number = std::vformat( format, std::make_format_args( value ) );

			field( bar, hovered || held ? palette::k_field_hovered : palette::k_field );
			fill( { track.Min.x, track.Min.y, track.Min.x + std::round( track.GetWidth( ) * fraction ), track.Max.y }, g_theme.accent( ) );
			text( position, palette::k_text, shown( label ) );
			text( { bb.Max.x - text_width( number ), position.y }, palette::k_text_dim, number );

			return changed;
		}

	} // namespace detail

	bool begin_window( const char* title, const ImVec2& size, std::span<const char* const> tabs, int& tab )
	{
		ImGui::SetNextWindowPos( ImFloor( ( ImGui::GetIO( ).DisplaySize - size ) * 0.5f ), ImGuiCond_FirstUseEver );
		ImGui::SetNextWindowSize( size, ImGuiCond_Always );
		ImGui::PushStyleVar( ImGuiStyleVar_WindowPadding, { 0.0f, 0.0f } );
		ImGui::PushStyleVar( ImGuiStyleVar_WindowBorderSize, 0.0f );

		const auto open = ImGui::Begin( title, nullptr, detail::k_window_flags );

		ImGui::PopStyleVar( 2 );

		const auto frame = ImGui::GetCurrentWindow( )->Rect( );
		const auto inner = detail::inset( frame, detail::k_border );
		const auto header = ImRect{ inner.Min.x, inner.Min.y, inner.Max.x, inner.Min.y + detail::k_header_height };

		if ( open )
		{
			const auto text_y = header.Min.y + detail::centered( detail::k_header_height, ImGui::GetFontSize( ) );

			detail::fill( frame, palette::k_outline );
			detail::fill( detail::inset( frame, 1.0f ), palette::k_edge );
			detail::fill( inner, palette::k_background );
			detail::fill( header, palette::k_header );
			detail::fill( { header.Min.x, header.Max.y, header.Max.x, header.Max.y + 1.0f }, palette::k_outline );

			ImGui::PushFont( g_theme.bold( ), 0.0f );
			detail::text( { header.Min.x + detail::k_header_padding, text_y }, g_theme.accent( ), detail::shown( title ) );
			ImGui::PopFont( );

			detail::draw_tabs( header, text_y, tabs, tab );
		}

		const auto top = header.Max.y + 1.0f + detail::k_body_padding;

		ImGui::SetCursorScreenPos( { inner.Min.x + detail::k_body_padding, top } );

		const auto visible = ImGui::BeginChild( "##body", { inner.GetWidth( ) - detail::k_body_padding * 2.0f, inner.Max.y - detail::k_body_padding - top }, ImGuiChildFlags_None, detail::k_child_flags );

		return open && visible;
	}

	void end_window( )
	{
		ImGui::EndChild( );

		auto* window = ImGui::GetCurrentWindow( );
		const auto id = window->GetID( "##drag" );
		const auto header = ImRect{ window->Pos.x, window->Pos.y, window->Pos.x + window->Size.x, window->Pos.y + detail::k_border + detail::k_header_height };

		auto held{ false };

		if ( ImGui::ItemAdd( header, id, nullptr, ImGuiItemFlags_NoNav ) )
		{
			ImGui::ButtonBehavior( header, id, nullptr, &held );
		}

		if ( held )
		{
			ImGui::SetWindowPos( window->Pos + ImGui::GetIO( ).MouseDelta );
		}

		ImGui::End( );
	}

	void begin_columns( )
	{
		const auto width = std::floor( ( ImGui::GetContentRegionAvail( ).x - detail::k_column_gap ) * 0.5f );
		ImGui::BeginChild( "##left", { width, 0.0f }, ImGuiChildFlags_None, detail::k_child_flags );
	}

	void next_column( )
	{
		ImGui::EndChild( );
		ImGui::SameLine( 0.0f, detail::k_column_gap );
		ImGui::BeginChild( "##right", { 0.0f, 0.0f }, ImGuiChildFlags_None, detail::k_child_flags );
	}

	void end_columns( )
	{
		ImGui::EndChild( );
	}

	void begin_section( const char* title, bool fill )
	{
		const auto available = ImGui::GetContentRegionAvail( );
		const auto flags = ImGuiChildFlags_AlwaysUseWindowPadding | ( fill ? ImGuiChildFlags_None : ImGuiChildFlags_AutoResizeY );

		ImGui::PushStyleVar( ImGuiStyleVar_WindowPadding, { detail::k_section_padding, detail::k_section_padding } );
		ImGui::BeginChild( title, { std::floor( available.x ), fill ? std::floor( available.y ) : 0.0f }, flags, detail::k_child_flags );
		ImGui::PopStyleVar( );

		auto* window = ImGui::GetCurrentWindow( );
		if ( !window->SkipItems )
		{
			const auto rect = window->Rect( );
			const auto border = ImRect{ rect.Min.x, rect.Min.y + std::floor( ImGui::GetFontSize( ) * 0.5f ), rect.Max.x, rect.Max.y };
			const auto label = detail::shown( title );
			const auto x = rect.Min.x + detail::k_title_inset;

			ImGui::PushClipRect( rect.Min, rect.Max, false );
			detail::outline( border, palette::k_outline );
			detail::outline( detail::inset( border, 1.0f ), palette::k_edge );

			ImGui::PushFont( g_theme.bold( ), 0.0f );
			detail::fill( { x - detail::k_title_gap, border.Min.y, x + detail::text_width( label ) + detail::k_title_gap, border.Min.y + 2.0f }, palette::k_background );
			detail::text( { x, rect.Min.y }, palette::k_text, label );
			ImGui::PopFont( );

			ImGui::PopClipRect( );
		}

		ImGui::SetCursorPosY( ImGui::GetCursorPosY( ) + detail::k_title_offset );
	}

	void end_section( )
	{
		ImGui::EndChild( );
	}

	bool checkbox( const char* label, bool& value )
	{
		auto* window = ImGui::GetCurrentWindow( );
		if ( window->SkipItems )
		{
			return false;
		}

		const auto id = window->GetID( label );
		const auto text = detail::shown( label );
		const auto height = ImGui::GetFontSize( );
		const auto position = ImFloor( window->DC.CursorPos );
		const auto bb = ImRect{ position.x, position.y, position.x + detail::k_check_size + detail::k_check_gap + detail::text_width( text ), position.y + height };

		ImGui::ItemSize( bb );

		if ( !ImGui::ItemAdd( bb, id ) )
		{
			return false;
		}

		auto hovered{ false };
		auto held{ false };
		const auto pressed = ImGui::ButtonBehavior( bb, id, &hovered, &held );

		if ( pressed )
		{
			value = !value;
			ImGui::MarkItemEdited( id );
		}

		const auto top = position.y + detail::centered( height, detail::k_check_size );

		detail::field( { position.x, top, position.x + detail::k_check_size, top + detail::k_check_size }, value ? g_theme.accent( ) : hovered ? palette::k_field_hovered : palette::k_field );
		detail::text( { position.x + detail::k_check_size + detail::k_check_gap, position.y }, palette::k_text, text );

		return pressed;
	}

	bool slider( const char* label, int& value, int min, int max, std::string_view format )
	{
		return detail::slider( label, value, min, max, format );
	}

	bool slider( const char* label, float& value, float min, float max, std::string_view format )
	{
		return detail::slider( label, value, min, max, format );
	}

	bool combo( const char* label, int& index, std::span<const char* const> items )
	{
		auto* window = ImGui::GetCurrentWindow( );
		if ( window->SkipItems )
		{
			return false;
		}

		const auto id = window->GetID( label );
		const auto popup = ImHashStr( "##popup", 0, id );
		const auto font = ImGui::GetFontSize( );
		const auto height = ImGui::GetFrameHeight( );
		const auto position = ImFloor( window->DC.CursorPos );
		const auto bb = ImRect{ position.x, position.y, position.x + std::floor( ImGui::GetContentRegionAvail( ).x ), position.y + font + detail::k_field_gap + height };
		const auto box = ImRect{ bb.Min.x, bb.Max.y - height, bb.Max.x, bb.Max.y };

		ImGui::ItemSize( bb );

		if ( !ImGui::ItemAdd( bb, id ) )
		{
			return false;
		}

		auto hovered{ false };
		auto held{ false };
		const auto open = ImGui::IsPopupOpen( popup, ImGuiPopupFlags_None );

		if ( ImGui::ButtonBehavior( box, id, &hovered, &held ) && !open )
		{
			ImGui::OpenPopupEx( popup );
		}

		const auto valid = index >= 0 && index < static_cast< int >( items.size( ) );

		detail::text( position, palette::k_text, detail::shown( label ) );
		detail::field( box, hovered || open ? palette::k_field_hovered : palette::k_field );
		detail::text( { box.Min.x + detail::k_text_inset, box.Min.y + detail::centered( height, font ) }, palette::k_text, valid ? items[ static_cast< std::size_t >( index ) ] : "" );
		detail::arrow( { box.Max.x - detail::k_text_inset - static_cast< float >( detail::k_arrow_width ), box.Min.y + detail::centered( height, 3.0f ) }, open ? g_theme.accent( ) : palette::k_text_dim );

		if ( !ImGui::IsPopupOpen( popup, ImGuiPopupFlags_None ) )
		{
			return false;
		}

		auto changed{ false };

		ImGui::SetNextWindowPos( { box.Min.x, box.Max.y - 1.0f } );
		ImGui::SetNextWindowSize( { box.GetWidth( ), detail::k_option_height * static_cast< float >( items.size( ) ) + 2.0f } );
		ImGui::PushStyleVar( ImGuiStyleVar_WindowPadding, { 1.0f, 1.0f } );
		ImGui::PushStyleVar( ImGuiStyleVar_ItemSpacing, { 0.0f, 0.0f } );

		if ( ImGui::BeginPopupEx( popup, detail::k_popup_flags | ImGuiWindowFlags_NoScrollbar ) )
		{
			for ( auto entry = 0; entry < static_cast< int >( items.size( ) ); ++entry )
			{
				ImGui::PushID( entry );

				if ( detail::option( items[ static_cast< std::size_t >( entry ) ], entry == index ) )
				{
					index = entry;
					changed = true;
					ImGui::CloseCurrentPopup( );
				}

				ImGui::PopID( );
			}

			ImGui::EndPopup( );
		}

		ImGui::PopStyleVar( 2 );

		return changed;
	}

	bool button( const char* label, float width )
	{
		auto* window = ImGui::GetCurrentWindow( );
		if ( window->SkipItems )
		{
			return false;
		}

		const auto id = window->GetID( label );
		const auto caption = detail::shown( label );
		const auto height = ImGui::GetFrameHeight( );
		const auto position = ImFloor( window->DC.CursorPos );
		const auto bb = ImRect{ position.x, position.y, position.x + ( width > 0.0f ? width : std::floor( ImGui::GetContentRegionAvail( ).x ) ), position.y + height };

		ImGui::ItemSize( bb );

		if ( !ImGui::ItemAdd( bb, id ) )
		{
			return false;
		}

		auto hovered{ false };
		auto held{ false };
		const auto pressed = ImGui::ButtonBehavior( bb, id, &hovered, &held );

		detail::field( bb, held ? palette::k_field_active : hovered ? palette::k_field_hovered : palette::k_field );
		detail::text( { bb.Min.x + detail::centered( bb.GetWidth( ), detail::text_width( caption ) ), bb.Min.y + detail::centered( height, ImGui::GetFontSize( ) ) }, palette::k_text, caption );

		return pressed;
	}

	bool text_input( const char* id, const char* hint, std::span<char> buffer )
	{
		ImGui::SetNextItemWidth( -FLT_MIN );
		return ImGui::InputTextWithHint( id, hint, buffer.data( ), buffer.size( ) );
	}

	bool list( const char* id, int& selected, std::span<const std::string> items, float height )
	{
		ImGui::PushStyleVar( ImGuiStyleVar_ChildBorderSize, 1.0f );
		ImGui::PushStyleVar( ImGuiStyleVar_WindowPadding, { 1.0f, 1.0f } );
		ImGui::PushStyleColor( ImGuiCol_ChildBg, palette::k_field );

		const auto visible = ImGui::BeginChild( id, { std::floor( ImGui::GetContentRegionAvail( ).x ), std::floor( height ) }, ImGuiChildFlags_Borders );

		ImGui::PopStyleColor( );
		ImGui::PopStyleVar( 2 );

		auto changed{ false };

		if ( visible )
		{
			ImGui::PushStyleVar( ImGuiStyleVar_ItemSpacing, { 0.0f, 0.0f } );

			for ( auto entry = 0; entry < static_cast< int >( items.size( ) ); ++entry )
			{
				ImGui::PushID( entry );

				if ( detail::option( items[ static_cast< std::size_t >( entry ) ], entry == selected ) )
				{
					selected = entry;
					changed = true;
				}

				ImGui::PopID( );
			}

			ImGui::PopStyleVar( );
		}

		ImGui::EndChild( );

		return changed;
	}

	bool keybind( const char* id, int& key )
	{
		auto* window = ImGui::GetCurrentWindow( );
		if ( window->SkipItems )
		{
			return false;
		}

		const auto item = window->GetID( id );
		auto* storage = ImGui::GetStateStorage( );
		auto waiting = storage->GetBool( item );
		auto changed{ false };

		if ( waiting )
		{
			if ( const auto pressed = g_input.take( ); pressed && pressed != VK_LBUTTON )
			{
				if ( pressed != VK_ESCAPE )
				{
					key = pressed;
					changed = true;
				}

				waiting = false;
				g_input.disarm( );
			}
		}

		const auto value = waiting ? std::string( "[...]" ) : std::format( "[{}]", key_name( key ) );
		const auto bb = detail::inline_rect( detail::text_width( value ) );

		if ( ImGui::ItemAdd( bb, item ) )
		{
			auto hovered{ false };
			auto held{ false };

			if ( ImGui::ButtonBehavior( bb, item, &hovered, &held ) && !waiting )
			{
				waiting = true;
				g_input.arm( );
			}

			detail::text( bb.Min, waiting ? g_theme.accent( ) : hovered ? palette::k_text : palette::k_text_dim, value );
		}

		storage->SetBool( item, waiting );

		return changed;
	}

	bool color_picker( const char* id, color& value )
	{
		auto* window = ImGui::GetCurrentWindow( );
		if ( window->SkipItems )
		{
			return false;
		}

		const auto item = window->GetID( id );
		const auto popup = ImHashStr( "##popup", 0, item );
		const auto bb = detail::inline_rect( detail::k_swatch.x );

		if ( !ImGui::ItemAdd( bb, item ) )
		{
			return false;
		}

		auto hovered{ false };
		auto held{ false };
		const auto open = ImGui::IsPopupOpen( popup, ImGuiPopupFlags_None );

		if ( ImGui::ButtonBehavior( bb, item, &hovered, &held ) && !open )
		{
			ImGui::OpenPopupEx( popup );
		}

		const auto top = bb.Min.y + detail::centered( bb.GetHeight( ), detail::k_swatch.y );
		detail::field( { bb.Min.x, top, bb.Max.x, top + detail::k_swatch.y }, ImGui::ColorConvertFloat4ToU32( value.vec4( 1.0f ) ) );

		if ( !ImGui::IsPopupOpen( popup, ImGuiPopupFlags_None ) )
		{
			return false;
		}

		auto changed{ false };

		ImGui::SetNextWindowPos( { bb.Max.x, bb.Max.y + detail::k_field_gap }, ImGuiCond_Always, { 1.0f, 0.0f } );
		ImGui::PushStyleVar( ImGuiStyleVar_WindowPadding, { detail::k_popup_padding, detail::k_popup_padding } );

		if ( ImGui::BeginPopupEx( popup, detail::k_popup_flags | ImGuiWindowFlags_AlwaysAutoResize ) )
		{
			ImGui::SetNextItemWidth( detail::k_picker_width );
			changed = ImGui::ColorPicker4( "##picker", &value.r, detail::k_picker_flags );
			ImGui::EndPopup( );
		}

		ImGui::PopStyleVar( );

		return changed;
	}

	bool begin_dropdown( const char* id )
	{
		auto* window = ImGui::GetCurrentWindow( );
		if ( window->SkipItems )
		{
			return false;
		}

		const auto item = window->GetID( id );
		const auto popup = ImHashStr( "##popup", 0, item );
		const auto left = window->DC.CursorPos.x;
		const auto width = window->ContentRegionRect.Max.x - left;
		const auto bb = detail::inline_rect( ImGui::GetFontSize( ) );

		if ( !ImGui::ItemAdd( bb, item ) )
		{
			return false;
		}

		auto hovered{ false };
		auto held{ false };
		const auto open = ImGui::IsPopupOpen( popup, ImGuiPopupFlags_None );

		if ( ImGui::ButtonBehavior( bb, item, &hovered, &held ) && !open )
		{
			ImGui::OpenPopupEx( popup );
		}

		const auto icon = ImVec2{ static_cast< float >( detail::k_settings_width ), static_cast< float >( detail::k_settings_icon.size( ) ) };
		detail::sprite( { bb.Min.x + detail::centered( bb.GetWidth( ), icon.x ), bb.Min.y + detail::centered( bb.GetHeight( ), icon.y ) }, detail::k_settings_icon, detail::k_settings_width, open ? g_theme.accent( ) : hovered ? palette::k_text : palette::k_text_dim );

		if ( !ImGui::IsPopupOpen( popup, ImGuiPopupFlags_None ) )
		{
			return false;
		}

		ImGui::SetNextWindowPos( { left, bb.Max.y + detail::k_dropdown_gap } );
		ImGui::SetNextWindowSizeConstraints( { width, 0.0f }, { width, FLT_MAX } );
		ImGui::PushStyleVar( ImGuiStyleVar_WindowPadding, { detail::k_dropdown_padding, detail::k_dropdown_padding } );
		ImGui::PushStyleColor( ImGuiCol_PopupBg, palette::k_header );

		const auto visible = ImGui::BeginPopupEx( popup, detail::k_popup_flags | ImGuiWindowFlags_AlwaysAutoResize );

		ImGui::PopStyleColor( );
		ImGui::PopStyleVar( );

		if ( visible )
		{
			const auto rect = ImGui::GetCurrentWindow( )->Rect( );

			ImGui::PushClipRect( rect.Min, rect.Max, false );
			detail::outline( detail::inset( rect, 1.0f ), palette::k_edge );
			ImGui::PopClipRect( );
		}

		return visible;
	}

	void end_dropdown( )
	{
		ImGui::EndPopup( );
	}

} // namespace opaline::ui::widgets

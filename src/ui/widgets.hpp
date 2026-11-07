#pragma once

#include <ui/config.hpp>

namespace opaline::ui::widgets {

	[[nodiscard]] bool begin_window( const char* title, const ImVec2& size, std::span<const char* const> tabs, int& tab );
	void end_window( );

	void begin_columns( );
	void next_column( );
	void end_columns( );

	void begin_section( const char* title, bool fill = false );
	void end_section( );

	bool checkbox( const char* label, bool& value );
	bool slider( const char* label, int& value, int min, int max, std::string_view format = "{}" );
	bool slider( const char* label, float& value, float min, float max, std::string_view format = "{:.0f}" );
	bool combo( const char* label, int& index, std::span<const char* const> items );
	bool button( const char* label, float width = 0.0f );
	bool text_input( const char* id, const char* hint, std::span<char> buffer );
	bool list( const char* id, int& selected, std::span<const std::string> items, float height );

	bool keybind( const char* id, int& key );
	bool color_picker( const char* id, color& value );

	[[nodiscard]] bool begin_dropdown( const char* id );
	void end_dropdown( );

} // namespace opaline::ui::widgets

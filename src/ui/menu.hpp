#pragma once

namespace opaline::ui {

	class menu
	{
	public:
		void draw( );
		void shutdown( );

		void toggle( ) noexcept { this->m_open = !this->m_open; }
		[[nodiscard]] bool open( ) const noexcept { return this->m_open; }

	private:
		void sync_input( );
		void draw_rage( );
		void draw_antiaim( );
		void draw_visuals( );
		void draw_movement( );
		void draw_config( );
		void refresh( );

		std::atomic<bool> m_open{ true };
		void* m_input_context{};
		std::array<char, 49> m_name{};
		std::vector<std::string> m_configs{};
		std::string m_status{};
		int m_tab{};
		int m_selected{ -1 };
		int m_rage_weapon{};
		bool m_listed{};
	};

	inline menu g_menu{};

} // namespace opaline::ui

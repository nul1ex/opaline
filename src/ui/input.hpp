#pragma once

namespace opaline::ui {

	class input
	{
	public:
		[[nodiscard]] int on_message( UINT msg, WPARAM wparam, LPARAM lparam );

		void arm( ) noexcept
		{
			this->m_pressed.store( 0 );
			this->m_capturing.store( true );
		}

		void disarm( ) noexcept { this->m_capturing.store( false ); }

		[[nodiscard]] bool capturing( ) const noexcept { return this->m_capturing.load( ); }
		[[nodiscard]] int take( ) noexcept { return this->m_pressed.exchange( 0 ); }

	private:
		std::atomic<int> m_pressed{};
		std::atomic<bool> m_capturing{};
	};

	inline input g_input{};

	[[nodiscard]] std::string key_name( int key );
	[[nodiscard]] bool key_held( int key );

} // namespace opaline::ui

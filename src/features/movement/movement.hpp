#pragma once

#include <input/command.hpp>

namespace opaline::movement {

	class jumpbug
	{
	public:
		void run( input::command& command );

		[[nodiscard]] bool active( ) const noexcept { return this->m_active; }

	private:
		bool m_active{};
	};

	class bhop
	{
	public:
		void run( input::command& command );

		[[nodiscard]] bool active( ) const noexcept { return this->m_active; }

	private:
		[[nodiscard]] bool press_jump( input::command& command, float from ) const;

		bool m_last_on_ground{};
		bool m_active{};
	};

	class autostrafe
	{
	public:
		void run( input::command& command );
		void preview( input::command& command ) const;
		void brake( input::command& command, float stop_speed );

	private:
		struct applied
		{
			bool valid{};
			int steps_before{};
			int steps_after{};
			float forward{};
			float left{};
			bool side_switch{};
		};

		[[nodiscard]] std::uint64_t tracked_keys( std::uint64_t buttons ) const;

		std::uint64_t m_last_buttons{};
		std::uint64_t m_last_pressed{};
		bool m_side_switch{};
		applied m_applied{};
	};

	class slowwalk
	{
	public:
		void run( input::command& command ) const;
	};

	inline jumpbug g_jumpbug{};
	inline bhop g_bhop{};
	inline autostrafe g_autostrafe{};
	inline slowwalk g_slowwalk{};

} // namespace opaline::movement

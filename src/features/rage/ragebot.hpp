#pragma once

#include <input/command.hpp>

namespace opaline::rage {

	class ragebot
	{
	public:
		void run( input::command& command );

	private:
		int m_last_shot_tick{ -1 };
		std::int64_t m_air_brake_command{ -1 };
	};

	inline ragebot g_ragebot{};

} // namespace opaline::rage

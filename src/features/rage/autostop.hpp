#pragma once

#include <input/command.hpp>

namespace opaline::rage {

	class autostop
	{
	public:
		void run( input::command& command, float target_speed, bool in_air ) const;
	};

	inline autostop g_autostop{};

} // namespace opaline::rage

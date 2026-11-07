#pragma once

#include <input/command.hpp>

namespace opaline::antiaim {

	class antiaim
	{
	public:
		void run( input::command& command ) const;
		void on_key( int key );

	private:
		enum class manual : std::uint8_t
		{
			none,
			left,
			right
		};

		std::atomic<manual> m_manual{ manual::none };
	};

	inline antiaim g_antiaim{};

} // namespace opaline::antiaim

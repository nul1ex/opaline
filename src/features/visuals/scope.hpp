#pragma once

namespace opaline::visuals {

	class scope
	{
	public:
		void collect( );
		void draw( ImDrawList* draw_list ) const;

	private:
		std::atomic<bool> m_visible{};
	};

	inline scope g_scope{};

} // namespace opaline::visuals

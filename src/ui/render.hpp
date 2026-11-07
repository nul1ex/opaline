#pragma once

namespace opaline::ui {

	class render
	{
	public:
		void on_present( IDXGISwapChain* swap_chain );
		void release_target( );
		void shutdown( );

		[[nodiscard]] bool ready( ) const noexcept { return this->m_initialized; }

	private:
		[[nodiscard]] bool initialize( IDXGISwapChain* swap_chain );
		void create_target( IDXGISwapChain* swap_chain );

		ID3D11Device* m_device{};
		ID3D11DeviceContext* m_context{};
		ID3D11RenderTargetView* m_target{};
		bool m_initialized{};
	};

	inline render g_render{};

} // namespace opaline::ui

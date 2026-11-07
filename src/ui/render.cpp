#include <pch.hpp>
#include <ui/render.hpp>
#include <ui/menu.hpp>
#include <ui/theme.hpp>
#include <features/visuals/esp.hpp>
#include <features/visuals/scope.hpp>
#include <core/log.hpp>

#include <backends/imgui_impl_dx11.h>
#include <backends/imgui_impl_win32.h>

namespace opaline::ui {

	void render::on_present( IDXGISwapChain* swap_chain )
	{
		if ( !this->m_initialized && !this->initialize( swap_chain ) )
		{
			return;
		}

		if ( !this->m_target )
		{
			this->create_target( swap_chain );
		}

		if ( !this->m_target )
		{
			return;
		}

		ImGui_ImplDX11_NewFrame( );
		ImGui_ImplWin32_NewFrame( );
		ImGui::NewFrame( );

		visuals::g_esp.draw( ImGui::GetBackgroundDrawList( ) );
		visuals::g_scope.draw( ImGui::GetBackgroundDrawList( ) );
		g_menu.draw( );

		ImGui::Render( );

		this->m_context->OMSetRenderTargets( 1, &this->m_target, nullptr );
		ImGui_ImplDX11_RenderDrawData( ImGui::GetDrawData( ) );
	}

	void render::release_target( )
	{
		if ( this->m_target )
		{
			this->m_target->Release( );
			this->m_target = nullptr;
		}
	}

	void render::shutdown( )
	{
		if ( this->m_initialized )
		{
			ImGui_ImplDX11_Shutdown( );
			ImGui_ImplWin32_Shutdown( );
			ImGui::DestroyContext( );
			this->m_initialized = false;
		}

		this->release_target( );

		if ( this->m_context )
		{
			this->m_context->Release( );
			this->m_context = nullptr;
		}

		if ( this->m_device )
		{
			this->m_device->Release( );
			this->m_device = nullptr;
		}
	}

	bool render::initialize( IDXGISwapChain* swap_chain )
	{
		if ( FAILED( swap_chain->GetDevice( __uuidof( ID3D11Device ), reinterpret_cast< void** >( &this->m_device ) ) ) )
		{
			return false;
		}

		this->m_device->GetImmediateContext( &this->m_context );

		DXGI_SWAP_CHAIN_DESC desc{};
		swap_chain->GetDesc( &desc );

		ImGui::CreateContext( );

		auto& io = ImGui::GetIO( );
		io.IniFilename = nullptr;
		io.LogFilename = nullptr;

		g_theme.initialize( );

		this->m_initialized = ImGui_ImplWin32_Init( desc.OutputWindow ) && ImGui_ImplDX11_Init( this->m_device, this->m_context );
		core::g_log.print( "[render] imgui {}", this->m_initialized ? "ready" : "failed to initialize" );

		return this->m_initialized;
	}

	void render::create_target( IDXGISwapChain* swap_chain )
	{
		ID3D11Texture2D* back_buffer{};

		if ( SUCCEEDED( swap_chain->GetBuffer( 0, __uuidof( ID3D11Texture2D ), reinterpret_cast< void** >( &back_buffer ) ) ) )
		{
			this->m_device->CreateRenderTargetView( back_buffer, nullptr, &this->m_target );
			back_buffer->Release( );
		}
	}

} // namespace opaline::ui

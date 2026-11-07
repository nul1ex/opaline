#include <pch.hpp>
#include <core/hooks.hpp>
#include <core/game.hpp>
#include <core/log.hpp>
#include <features/antiaim/antiaim.hpp>
#include <features/misc/camera.hpp>
#include <features/movement/movement.hpp>
#include <features/rage/ragebot.hpp>
#include <features/rage/records.hpp>
#include <features/visuals/esp.hpp>
#include <features/visuals/scope.hpp>
#include <input/command.hpp>
#include <prediction/engine.hpp>
#include <ui/input.hpp>
#include <ui/menu.hpp>
#include <ui/render.hpp>
#include <settings.hpp>

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler( HWND window, UINT msg, WPARAM wparam, LPARAM lparam );

namespace opaline::core {

	namespace detail {

		constexpr auto k_present{ 8ull };
		constexpr auto k_resize_buffers{ 13ull };
		constexpr auto k_inactive_slot{ 1 };
		constexpr auto k_net_update_end{ 8 };

		static safetyhook::InlineHook g_present{};
		static safetyhook::InlineHook g_resize_buffers{};
		static safetyhook::InlineHook g_process_input{};
		static safetyhook::InlineHook g_wnd_proc{};
		static safetyhook::InlineHook g_create_move{};
		static safetyhook::InlineHook g_render_view{};
		static safetyhook::InlineHook g_play_landing_sound{};
		static safetyhook::InlineHook g_emit_sound_by_handle{};
		static safetyhook::InlineHook g_post_network_data_received{};
		static safetyhook::InlineHook g_override_view{};
		static safetyhook::InlineHook g_update_fov_sensitivity{};
		static safetyhook::InlineHook g_frame_stage_notify{};
		static safetyhook::InlineHook g_finalize_move{};
		static safetyhook::InlineHook g_render_scope{};
		static safetyhook::InlineHook g_hitbox_transforms{};
		static safetyhook::InlineHook g_hitbox_broadphase{};

		[[nodiscard]] static bool install( safetyhook::InlineHook& hook, void* target, void* destination )
		{
			if ( !target )
			{
				return false;
			}

			hook = safetyhook::create_inline( target, destination, safetyhook::InlineHook::StartDisabled );
			return hook && hook.enable( ).has_value( );
		}

		[[nodiscard]] static bool is_mouse( UINT msg )
		{
			return msg >= WM_MOUSEFIRST && msg <= WM_MOUSELAST;
		}

		[[nodiscard]] static bool is_keyboard( UINT msg )
		{
			return ( msg >= WM_KEYFIRST && msg <= WM_KEYLAST ) || msg == WM_CHAR;
		}

		static LRESULT __stdcall wnd_proc( HWND window, UINT msg, WPARAM wparam, LPARAM lparam )
		{
			const auto key = ui::g_input.on_message( msg, wparam, lparam );
			if ( key && key == settings::g_misc.menu_key.get( ) && !ui::g_input.capturing( ) )
			{
				ui::g_menu.toggle( );
				return 0;
			}

			if ( key && !ui::g_input.capturing( ) )
			{
				antiaim::g_antiaim.on_key( key );
			}

			if ( ui::g_render.ready( ) )
			{
				ImGui_ImplWin32_WndProcHandler( window, msg, wparam, lparam );

				if ( ui::g_menu.open( ) )
				{
					const auto& io = ImGui::GetIO( );

					if ( ( is_mouse( msg ) && io.WantCaptureMouse ) || ( is_keyboard( msg ) && io.WantCaptureKeyboard ) )
					{
						return msg == WM_XBUTTONDOWN || msg == WM_XBUTTONUP || msg == WM_XBUTTONDBLCLK ? TRUE : 0;
					}
				}
			}

			return g_wnd_proc.call<LRESULT>( window, msg, wparam, lparam );
		}

		static void __fastcall process_input( void* input, int slot, float frame_time )
		{
			g_process_input.call( input, ui::g_menu.open( ) ? k_inactive_slot : slot, frame_time );
		}

		static void select_weapon( sdk::csgo_input* input, sdk::user_cmd* cmd )
		{
			const auto weapon  = sdk::handle{ input->selected_weapon( ) };
			const auto base = cmd->pb.base;

			if ( !weapon.valid( ) || !base || !entities( )->get( weapon.index( ) ) )
			{
				return;
			}

			base->weapon_select = weapon.index( );
			base->has_bits |= sdk::base_fields::weapon_select;
		}

		static void __fastcall create_move( sdk::csgo_input* input, std::uintptr_t slot, std::uintptr_t active )
		{
			const auto controller = local_controller( );
			const auto pawn = local_pawn( controller );

			if ( const auto cmd = pawn ? current_user_cmd( controller ) : nullptr; cmd && cmd->command_state == sdk::command_states::building )
			{
				select_weapon( input, cmd );
				return;
			}

			g_create_move.call( input, slot, active );

			const auto cmd = pawn ? current_user_cmd( controller ) : nullptr;

			if ( !cmd || !cmd->pb.base || !prediction::g_engine.begin( controller, pawn, cmd->command_number ) )
			{
				return;
			}

			opaline::input::command command{ input, cmd, prediction::g_engine.start( ).impulses };
			command.clear_steps( );

			antiaim::g_antiaim.run( command );

			movement::g_slowwalk.run( command );
			movement::g_jumpbug.run( command );
			movement::g_bhop.run( command );
			movement::g_autostrafe.run( command );

			rage::g_ragebot.run( command );

			command.commit( );
			prediction::g_engine.commit_shot_history( std::span<const sdk::user_cmd>( cmd, 1 ) );
		}

		static void __fastcall post_network_data_received( sdk::prediction_system* system )
		{
			prediction::g_engine.before_network_update( system );
			g_post_network_data_received.call( system );
			prediction::g_engine.after_network_update( );
		}

		static void* __fastcall render_view( void* view_render )
		{
			const auto result = g_render_view.call<void*>( view_render );
			visuals::g_esp.collect( );
			visuals::g_scope.collect( );

			return result;
		}

		static void __fastcall override_view( std::uintptr_t client_mode, sdk::view_setup* setup )
		{
			g_override_view.call( client_mode, setup );
			misc::g_camera.override_view( setup );
		}

		static void __fastcall update_fov_sensitivity( sdk::cs_player_pawn* pawn )
		{
			g_update_fov_sensitivity.call( pawn );
			misc::g_camera.update_fov_sensitivity( pawn );
		}

		static void __fastcall finalize_move( std::uintptr_t input, std::uintptr_t slot )
		{
			const auto angles = view_angles( );
			g_finalize_move.call( input, slot );
			set_view_angles( angles );
		}

		static std::uintptr_t __fastcall render_scope( std::uintptr_t pawn, sdk::scope_render* out )
		{
			const auto result = g_render_scope.call<std::uintptr_t>( pawn, out );

			if ( settings::g_view.remove_scope.get( ) )
			{
				out->visible( ) = false;
			}

			return result;
		}

		static void __fastcall frame_stage_notify( std::uintptr_t client, std::uintptr_t stage )
		{
			g_frame_stage_notify.call( client, stage );

			if ( static_cast< int >( stage ) == k_net_update_end )
			{
				rage::g_records.update( );
			}
		}

		static std::int64_t __fastcall hitbox_transforms( sdk::game_scene_node* skeleton, const sdk::hitbox_shapes* shapes, sdk::hitbox_transforms* transforms, std::uintptr_t set )
		{
			const auto result = g_hitbox_transforms.call<std::int64_t>( skeleton, shapes, transforms, set );

			if ( static_cast< int >( result ) > 0 && shapes )
			{
				rage::g_records.override_transforms( skeleton, shapes, transforms );
			}

			return result;
		}

		static int __fastcall hitbox_broadphase( const sdk::broadphase_tree* tree, std::uintptr_t start, std::uintptr_t end, float length, std::uintptr_t extents, sdk::broadphase_candidates* candidates )
		{
			const auto result = g_hitbox_broadphase.call<int>( tree, start, end, length, extents, candidates );

			if ( !candidates )
			{
				return result;
			}

			rage::g_records.override_broadphase( tree, candidates );
			return candidates->count;
		}

		static void __fastcall play_landing_sound( void* pawn, float fall_velocity )
		{
			if ( !prediction::g_engine.simulating( ) )
			{
				g_play_landing_sound.call( pawn, fall_velocity );
			}
		}

		static void* __fastcall emit_sound_by_handle( void* system, void* out, std::uintptr_t entity, std::uintptr_t sound, void* parameters )
		{
			if ( !prediction::g_engine.simulating( ) )
			{
				return g_emit_sound_by_handle.call<void*>( system, out, entity, sound, parameters );
			}

			if ( out )
			{
				const auto result = static_cast< std::uint8_t* >( out );

				std::memset( result, 0, sizeof( std::uint32_t ) );
				std::memset( result + sizeof( std::uint32_t ) * 2, 0, sizeof( std::uint32_t ) + sizeof( std::uint64_t ) );
			}

			return out;
		}

		static HRESULT __stdcall present( IDXGISwapChain* swap_chain, UINT sync_interval, UINT flags )
		{
			ui::g_render.on_present( swap_chain );
			return g_present.call<HRESULT>( swap_chain, sync_interval, flags );
		}

		static HRESULT __stdcall resize_buffers( IDXGISwapChain* swap_chain, UINT buffer_count, UINT width, UINT height, DXGI_FORMAT format, UINT flags )
		{
			ui::g_render.release_target( );
			return g_resize_buffers.call<HRESULT>( swap_chain, buffer_count, width, height, format, flags );
		}

	} // namespace detail

	bool install_hooks( )
	{
		DXGI_SWAP_CHAIN_DESC desc{};
		const auto window = SUCCEEDED( g_game.swap_chain->GetDesc( &desc ) ) ? desc.OutputWindow : nullptr;
		const auto window_proc = window ? reinterpret_cast< void* >( GetWindowLongPtrW( window, GWLP_WNDPROC ) ) : nullptr;

		const auto wnd_proc = detail::install( detail::g_wnd_proc, window_proc, reinterpret_cast< void* >( &detail::wnd_proc ) );
		const auto process_input = detail::install( detail::g_process_input, g_game.process_input, reinterpret_cast< void* >( &detail::process_input ) );
		const auto present = detail::install( detail::g_present, sdk::vtable_entry( g_game.swap_chain, detail::k_present ), reinterpret_cast< void* >( &detail::present ) );
		const auto resize_buffers = detail::install( detail::g_resize_buffers, sdk::vtable_entry( g_game.swap_chain, detail::k_resize_buffers ), reinterpret_cast< void* >( &detail::resize_buffers ) );
		const auto play_landing_sound = detail::install( detail::g_play_landing_sound, g_game.play_landing_sound, reinterpret_cast< void* >( &detail::play_landing_sound ) );
		const auto emit_sound_by_handle = detail::install( detail::g_emit_sound_by_handle, g_game.emit_sound_by_handle, reinterpret_cast< void* >( &detail::emit_sound_by_handle ) );
		const auto render_view = detail::install( detail::g_render_view, g_game.render_view, reinterpret_cast< void* >( &detail::render_view ) );
		const auto create_move = detail::install( detail::g_create_move, g_game.create_move, reinterpret_cast< void* >( &detail::create_move ) );
		const auto network_update = detail::install( detail::g_post_network_data_received, g_game.post_network_data_received, reinterpret_cast< void* >( &detail::post_network_data_received ) );
		const auto override_view = detail::install( detail::g_override_view, g_game.override_view, reinterpret_cast< void* >( &detail::override_view ) );
		const auto fov_sensitivity = detail::install( detail::g_update_fov_sensitivity, g_game.update_fov_sensitivity, reinterpret_cast< void* >( &detail::update_fov_sensitivity ) );
		const auto frame_stage = detail::install( detail::g_frame_stage_notify, g_game.frame_stage_notify, reinterpret_cast< void* >( &detail::frame_stage_notify ) );
		const auto finalize = detail::install( detail::g_finalize_move, g_game.finalize_move, reinterpret_cast< void* >( &detail::finalize_move ) );
		const auto scope = detail::install( detail::g_render_scope, g_game.render_scope, reinterpret_cast< void* >( &detail::render_scope ) );
		const auto transforms = detail::install( detail::g_hitbox_transforms, g_game.hitbox_transforms, reinterpret_cast< void* >( &detail::hitbox_transforms ) );
		const auto broadphase = detail::install( detail::g_hitbox_broadphase, g_game.hitbox_broadphase, reinterpret_cast< void* >( &detail::hitbox_broadphase ) );

		g_log.print( "[hooks] wnd proc {}, process input {}, present {}, resize buffers {}, landing sound {}, emit sound {}, render view {}, create move {}, network update {}, override view {}, fov sensitivity {}, frame stage {}, finalize move {}, render scope {}, hitbox transforms {}, hitbox broadphase {}",
			wnd_proc, process_input, present, resize_buffers, play_landing_sound, emit_sound_by_handle, render_view, create_move, network_update, override_view, fov_sensitivity, frame_stage, finalize, scope, transforms, broadphase );

		return wnd_proc && process_input && present && resize_buffers && play_landing_sound && emit_sound_by_handle && render_view && create_move && network_update && override_view && fov_sensitivity && frame_stage && finalize && scope && transforms && broadphase;
	}

	void remove_hooks( )
	{
		detail::g_hitbox_broadphase.reset( );
		detail::g_hitbox_transforms.reset( );
		detail::g_render_scope.reset( );
		detail::g_finalize_move.reset( );
		detail::g_frame_stage_notify.reset( );
		detail::g_update_fov_sensitivity.reset( );
		detail::g_override_view.reset( );
		detail::g_post_network_data_received.reset( );
		detail::g_create_move.reset( );
		detail::g_render_view.reset( );
		detail::g_emit_sound_by_handle.reset( );
		detail::g_play_landing_sound.reset( );
		detail::g_wnd_proc.reset( );
		detail::g_process_input.reset( );
		detail::g_present.reset( );
		detail::g_resize_buffers.reset( );
	}

} // namespace opaline::core

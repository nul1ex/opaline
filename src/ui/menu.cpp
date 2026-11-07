#include <pch.hpp>
#include <ui/menu.hpp>
#include <ui/input.hpp>
#include <ui/theme.hpp>
#include <ui/widgets.hpp>
#include <core/game.hpp>
#include <settings.hpp>

namespace opaline::ui {

	namespace detail {

		constexpr auto k_input_flags{ 1 | 8 };
		constexpr auto k_size{ ImVec2{ 540.0f, 340.0f } };
		constexpr std::array k_tabs{ "rage", "antiaim", "visuals", "movement", "config" };

		enum class tab
		{
			rage,
			antiaim,
			visuals,
			movement,
			config
		};

	} // namespace detail

	void menu::draw( )
	{
		this->sync_input( );
		g_theme.apply( settings::g_misc.accent.get( ) );

		ImGui::GetIO( ).MouseDrawCursor = this->m_open;

		if ( !this->m_open )
		{
			if ( g_input.capturing( ) )
			{
				g_input.disarm( );
			}

			return;
		}

		if ( !this->m_listed )
		{
			this->refresh( );
		}

		if ( widgets::begin_window( "opaline", detail::k_size, detail::k_tabs, this->m_tab ) )
		{
			switch ( static_cast< detail::tab >( this->m_tab ) )
			{
			case detail::tab::rage:
				this->draw_rage( );
				break;
			case detail::tab::antiaim:
				this->draw_antiaim( );
				break;
			case detail::tab::visuals:
				this->draw_visuals( );
				break;
			case detail::tab::movement:
				this->draw_movement( );
				break;
			case detail::tab::config:
				this->draw_config( );
				break;
			}
		}

		widgets::end_window( );
	}

	void menu::shutdown( )
	{
		if ( this->m_input_context )
		{
			core::g_game.input_stack->pop( this->m_input_context );
			this->m_input_context = nullptr;
		}
	}

	void menu::sync_input( )
	{
		if ( this->m_open && !this->m_input_context )
		{
			this->m_input_context = core::g_game.input_stack->push( "opaline_menu", detail::k_input_flags );
		}
		else if ( !this->m_open && this->m_input_context )
		{
			core::g_game.input_stack->pop( this->m_input_context );
			this->m_input_context = nullptr;
		}
	}

	void menu::draw_rage( )
	{
		auto& rage = settings::g_rage;

		widgets::begin_columns( );

		widgets::begin_section( "general", true );
		widgets::checkbox( "enabled", rage.enabled.get( ) );

		ImGui::BeginDisabled( !rage.enabled.get( ) );
		widgets::combo( "weapon", this->m_rage_weapon, settings::k_weapon_group_names );

		auto& cfg = rage.weapons[ static_cast< std::size_t >( this->m_rage_weapon ) ];

		widgets::slider( "hitchance", cfg.hitchance.get( ), 0, 100, "{}%" );
		widgets::slider( "minimum damage", cfg.min_damage.get( ), 1, 100 );
		widgets::checkbox( "autostop", cfg.autostop.get( ) );

		if ( widgets::begin_dropdown( "##autostop" ) )
		{
			widgets::checkbox( "in air", cfg.autostop_in_air.get( ) );
			widgets::checkbox( "between shots", cfg.autostop_between_shots.get( ) );
			widgets::end_dropdown( );
		}

		ImGui::EndDisabled( );
		widgets::end_section( );

		widgets::next_column( );

		ImGui::BeginDisabled( !rage.enabled.get( ) );
		widgets::begin_section( "hitboxes", true );
		widgets::checkbox( "head", cfg.head.get( ) );

		if ( widgets::begin_dropdown( "##head" ) )
		{
			widgets::slider( "point scale", cfg.head_scale.get( ), 0, 100, "{}%" );
			widgets::end_dropdown( );
		}

		widgets::checkbox( "chest", cfg.chest.get( ) );

		if ( widgets::begin_dropdown( "##chest" ) )
		{
			widgets::slider( "point scale", cfg.chest_scale.get( ), 0, 100, "{}%" );
			widgets::end_dropdown( );
		}

		widgets::checkbox( "stomach", cfg.stomach.get( ) );

		if ( widgets::begin_dropdown( "##stomach" ) )
		{
			widgets::slider( "point scale", cfg.stomach_scale.get( ), 0, 100, "{}%" );
			widgets::end_dropdown( );
		}

		widgets::checkbox( "arms", cfg.arms.get( ) );
		widgets::checkbox( "legs", cfg.legs.get( ) );
		widgets::checkbox( "feet", cfg.feet.get( ) );
		widgets::end_section( );
		ImGui::EndDisabled( );

		widgets::end_columns( );
	}

	void menu::draw_antiaim( )
	{
		auto& cfg = settings::g_antiaim;

		widgets::begin_columns( );

		widgets::begin_section( "yaw", true );
		widgets::checkbox( "enabled", cfg.enabled.get( ) );

		ImGui::BeginDisabled( !cfg.enabled.get( ) );
		widgets::combo( "yaw base", cfg.yaw_base.get( ), settings::k_yaw_base_names );
		widgets::slider( "yaw offset", cfg.yaw_offset.get( ), -180, 180 );
		ImGui::EndDisabled( );
		widgets::end_section( );

		widgets::next_column( );

		ImGui::BeginDisabled( !cfg.enabled.get( ) );
		widgets::begin_section( "manual", true );
		ImGui::TextUnformatted( "left" );
		widgets::keybind( "##left", cfg.manual_left.get( ) );
		ImGui::TextUnformatted( "right" );
		widgets::keybind( "##right", cfg.manual_right.get( ) );
		widgets::end_section( );
		ImGui::EndDisabled( );

		widgets::end_columns( );
	}

	void menu::draw_visuals( )
	{
		auto& esp = settings::g_esp;
		auto& view = settings::g_view;

		widgets::begin_columns( );

		widgets::begin_section( "players", true );
		widgets::checkbox( "enabled", esp.enabled.get( ) );

		ImGui::BeginDisabled( !esp.enabled.get( ) );
		widgets::checkbox( "teammates", esp.teammates.get( ) );
		widgets::checkbox( "box", esp.box.get( ) );
		widgets::color_picker( "##box color", esp.box_color.get( ) );
		widgets::checkbox( "name", esp.name.get( ) );
		widgets::checkbox( "health", esp.health.get( ) );
		widgets::checkbox( "weapon", esp.weapon.get( ) );
		widgets::checkbox( "flags", esp.flags.get( ) );
		ImGui::EndDisabled( );
		widgets::end_section( );

		widgets::next_column( );

		widgets::begin_section( "view", true );
		widgets::checkbox( "override fov", view.change_fov.get( ) );

		if ( widgets::begin_dropdown( "##fov" ) )
		{
			widgets::slider( "fov", view.fov.get( ), 50.0f, 150.0f );
			widgets::slider( "first zoom", view.scope_fov_1.get( ), 0.0f, 100.0f, "{:.0f}%" );
			widgets::slider( "second zoom", view.scope_fov_2.get( ), 0.0f, 100.0f, "{:.0f}%" );
			widgets::end_dropdown( );
		}

		widgets::checkbox( "thirdperson", view.thirdperson.get( ) );

		if ( widgets::begin_dropdown( "##thirdperson" ) )
		{
			widgets::slider( "distance", view.thirdperson_distance.get( ), 30.0f, 250.0f );
			widgets::end_dropdown( );
		}

		widgets::checkbox( "remove scope", view.remove_scope.get( ) );
		widgets::end_section( );

		widgets::end_columns( );
	}

	void menu::draw_movement( )
	{
		auto& cfg = settings::g_movement;

		widgets::begin_columns( );

		widgets::begin_section( "air", true );
		widgets::checkbox( "bhop", cfg.bhop.get( ) );
		widgets::checkbox( "jumpbug", cfg.jumpbug.get( ) );

		if ( widgets::begin_dropdown( "##jumpbug" ) )
		{
			widgets::checkbox( "keep crouch", cfg.jumpbug_keep_crouch.get( ) );
			widgets::end_dropdown( );
		}

		widgets::checkbox( "autostrafe", cfg.autostrafe.get( ) );

		if ( widgets::begin_dropdown( "##autostrafe" ) )
		{
			widgets::checkbox( "movement keys", cfg.autostrafe_movement_keys.get( ) );
			widgets::checkbox( "stop on shift", cfg.autostrafe_stop_on_shift.get( ) );
			widgets::checkbox( "stop on key release", cfg.autostrafe_stop_on_release.get( ) );
			widgets::end_dropdown( );
		}

		widgets::end_section( );

		widgets::next_column( );

		widgets::begin_section( "ground", true );
		widgets::checkbox( "slowwalk", cfg.slowwalk.get( ) );

		if ( widgets::begin_dropdown( "##slowwalk" ) )
		{
			widgets::slider( "speed", cfg.slowwalk_speed.get( ), 1, 100, "{}%" );
			widgets::end_dropdown( );
		}

		widgets::keybind( "##slowwalk key", cfg.slowwalk_key.get( ) );
		widgets::end_section( );

		widgets::end_columns( );
	}

	void menu::draw_config( )
	{
		const auto& style = ImGui::GetStyle( );

		widgets::begin_columns( );

		widgets::begin_section( "configs", true );
		widgets::text_input( "##name", "config name", this->m_name );

		const auto footer = ImGui::GetFrameHeight( ) + ImGui::GetFontSize( ) + style.ItemSpacing.y * 2.0f;

		if ( widgets::list( "##configs", this->m_selected, this->m_configs, ImGui::GetContentRegionAvail( ).y - footer ) )
		{
			const auto& source = this->m_configs[ static_cast< std::size_t >( this->m_selected ) ];

			this->m_name.fill( '\0' );
			std::copy_n( source.begin( ), std::min( source.size( ), this->m_name.size( ) - 1 ), this->m_name.begin( ) );
		}

		const std::string name( this->m_name.data( ) );
		const auto width = std::floor( ( ImGui::GetContentRegionAvail( ).x - style.ItemSpacing.x * 3.0f ) / 4.0f );

		if ( widgets::button( "save", width ) )
		{
			this->m_status = g_config.save( name ) ? std::format( "saved {}", name ) : std::string( "names can use letters, digits, spaces, - and _" );
			this->refresh( );
		}

		ImGui::SameLine( );

		if ( widgets::button( "load", width ) )
		{
			this->m_status = g_config.load( name ) ? std::format( "loaded {}", name ) : std::format( "cannot load {}", name );
		}

		ImGui::SameLine( );

		if ( widgets::button( "delete", width ) )
		{
			this->m_status = g_config.remove( name ) ? std::format( "deleted {}", name ) : std::format( "cannot delete {}", name );
			this->refresh( );
		}

		ImGui::SameLine( );

		if ( widgets::button( "refresh" ) )
		{
			this->refresh( );
		}

		if ( !this->m_status.empty( ) )
		{
			ImGui::TextDisabled( "%s", this->m_status.c_str( ) );
		}

		widgets::end_section( );

		widgets::next_column( );

		widgets::begin_section( "menu", true );
		ImGui::TextUnformatted( "menu key" );
		widgets::keybind( "##menu key", settings::g_misc.menu_key.get( ) );
		ImGui::TextUnformatted( "accent" );
		widgets::color_picker( "##accent", settings::g_misc.accent.get( ) );
		widgets::end_section( );

		widgets::end_columns( );
	}

	void menu::refresh( )
	{
		this->m_configs = g_config.list( );
		this->m_selected = -1;
		this->m_listed = true;
	}

} // namespace opaline::ui

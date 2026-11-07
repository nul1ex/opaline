#include <pch.hpp>
#include <features/rage/ragebot.hpp>
#include <features/rage/autostop.hpp>
#include <features/rage/hitboxes.hpp>
#include <features/rage/hitchance.hpp>
#include <features/rage/penetration.hpp>
#include <features/rage/points.hpp>
#include <features/rage/punch.hpp>
#include <features/rage/records.hpp>
#include <core/game.hpp>
#include <core/thread_pool.hpp>
#include <settings.hpp>

namespace opaline::rage {

	namespace detail {

		constexpr auto k_tick_interval{ 1.0f / 64.0f };
		constexpr auto k_max_players{ 64 };
		constexpr auto k_shot_cooldown{ 2 };
		constexpr auto k_max_pitch{ 89.0f };
		constexpr auto k_min_spread{ 0.0012f };
		constexpr auto k_accurate_fraction{ 0.34f };
		constexpr auto k_accurate_margin{ 0.96f };
		constexpr auto k_max_cycle_ticks{ 128 };
		constexpr auto k_air_slack{ 2.0f };
		constexpr auto k_lerp_snap{ 1e-4 };

		struct target
		{
			sdk::cs_player_pawn* pawn{};
			float fov{};
			int health{};
		};

		struct candidate
		{
			const record* source{};
			sdk::vector3 point{};
			float damage{};
		};

		[[nodiscard]] static double shot_lerp( sdk::cs_player_controller* controller )
		{
			using get_lerp_seconds_fn = float( __fastcall* )( sdk::cs_player_controller* );

			const auto ticks = static_cast< double >( reinterpret_cast< get_lerp_seconds_fn >( core::g_game.get_lerp_seconds )( controller ) ) / k_tick_interval;
			const auto rounded = std::round( ticks );

			return std::fabs( ticks - rounded ) < k_lerp_snap ? rounded : ticks;
		}

		[[nodiscard]] static float accurate_speed( sdk::weapon_vdata* vdata, int mode )
		{
			return vdata->max_speeds( )[ static_cast< std::size_t >( mode ) ] * k_accurate_fraction * k_accurate_margin;
		}

		[[nodiscard]] static std::optional<settings::weapon_group> group_of( std::uint16_t item )
		{
			namespace items = sdk::item_definitions;

			switch ( item )
			{
			case items::ssg08:
				return settings::weapon_group::ssg;
			case items::awp:
				return settings::weapon_group::awp;
			case items::g3sg1:
			case items::scar20:
				return settings::weapon_group::auto_sniper;
			case items::desert_eagle:
			case items::revolver:
				return settings::weapon_group::heavy_pistol;
			case items::glock:
			case items::p2000:
			case items::usp_s:
			case items::p250:
			case items::five_seven:
			case items::tec9:
			case items::cz75:
			case items::dual_berettas:
				return settings::weapon_group::light_pistol;
			case items::ak47:
			case items::m4a4:
			case items::m4a1_s:
			case items::aug:
			case items::sg553:
			case items::famas:
			case items::galil:
				return settings::weapon_group::rifle;
			case items::xm1014:
			case items::nova:
			case items::sawed_off:
			case items::mag7:
				return settings::weapon_group::shotgun;
			case items::p90:
			case items::ump45:
				return settings::weapon_group::heavy_smg;
			case items::mac10:
			case items::mp5sd:
			case items::mp7:
			case items::mp9:
			case items::bizon:
				return settings::weapon_group::light_smg;
			case items::m249:
			case items::negev:
				return settings::weapon_group::lmg;
			default:
				return std::nullopt;
			}
		}

		[[nodiscard]] static std::vector<target> find_targets( sdk::cs_player_controller* controller, sdk::cs_player_pawn* local, const sdk::vector3& eye, const sdk::vector3& view )
		{
			std::vector<target> out{};

			const auto system = core::entities( );

			for ( auto index = 1; index <= k_max_players; ++index )
			{
				const auto owner = static_cast< sdk::cs_player_controller* >( system->get( index ) );
				if ( !owner || owner == controller || !owner->pawn_alive( ) )
				{
					continue;
				}

				const auto pawn = system->get<sdk::cs_player_pawn>( owner->player_pawn( ) );
				const auto node = pawn ? pawn->scene_node( ) : nullptr;

				if ( !node || pawn == local || pawn->health( ) <= 0 || pawn->gun_game_immunity( ) || !core::is_enemy( local->team( ), pawn->team( ) ) || node->dormant( ) )
				{
					continue;
				}

				const auto angles = sdk::angles_to( eye, pawn->eye_position( ) );
				const auto fov = std::hypot( sdk::normalize_yaw( angles.x - view.x ), sdk::normalize_yaw( angles.y - view.y ) );

				out.push_back( { pawn, fov, pawn->health( ) } );
			}

			std::ranges::sort( out, [ ]( const target& a, const target& b ) { return a.fov != b.fov ? a.fov < b.fov : a.health < b.health; } );

			return out;
		}

		[[nodiscard]] static std::vector<candidate> scan( sdk::cs_player_pawn* pawn, const sdk::vector3& eye, std::span<const aim_box> boxes, std::uint32_t mask, float required, float spread_angle, float needed )
		{
			const auto set = query_hitboxes( pawn->scene_node( ) );
			const auto items = pawn->items( );
			const auto victim = penetration::target{ pawn, pawn->armor( ), items && items->has_helmet( ), pawn->team( ), mask };
			const auto available = g_records.records_for( pawn );

			std::vector<const record*> sources{};

			if ( !available.empty( ) )
			{
				sources.push_back( available.front( ) );
			}

			if ( available.size( ) > 1 )
			{
				sources.push_back( available.back( ) );
			}

			std::vector<candidate> out{};
			std::vector<sdk::vector3> points{};
			std::vector<std::optional<penetration::result>> hits{};

			for ( const auto source : sources )
			{
				points.clear( );

				for ( const auto& box : boxes )
				{
					const auto found = std::ranges::find( set, box.index, &hitbox::index );
					if ( found == set.end( ) || found->bone >= source->bone_count )
					{
						continue;
					}

					add_points( points, to_world( *found, source->bones[ static_cast< std::size_t >( found->bone ) ] ), box, eye, spread_angle, needed );
				}

				hits.assign( points.size( ), std::nullopt );

				{
					const records::scope applied{ *source };

					core::g_thread_pool.parallel_for( static_cast< int >( points.size( ) ), [ & ]( int index )
						{
							hits[ static_cast< std::size_t >( index ) ] = g_penetration.run( eye, points[ static_cast< std::size_t >( index ) ], victim );
						} );
				}

				for ( auto index = 0ull; index < points.size( ); ++index )
				{
					if ( const auto& hit = hits[ index ]; hit && hit->damage >= required )
					{
						out.push_back( { source, points[ index ], hit->damage } );
					}
				}
			}

			return out;
		}

		[[nodiscard]] static std::vector<capsule> shapes_of( const record& source )
		{
			std::vector<capsule> out{};

			for ( const auto& box : query_hitboxes( source.node ) )
			{
				if ( box.bone < source.bone_count )
				{
					out.push_back( to_world( box, source.bones[ static_cast< std::size_t >( box.bone ) ] ) );
				}
			}

			return out;
		}

		[[nodiscard]] static std::optional<candidate> pick( std::vector<candidate>& candidates, const sdk::vector3& eye, const spread_table& table, float needed )
		{
			std::ranges::stable_sort( candidates, std::greater{ }, &candidate::damage );

			std::vector<std::pair<const record*, std::vector<capsule>>> shapes{};

			const auto shapes_for = [ & ]( const record* source ) -> std::span<const capsule>
				{
					const auto cached = std::ranges::find( shapes, source, &std::pair<const record*, std::vector<capsule>>::first );
					return cached != shapes.end( ) ? cached->second : shapes.emplace_back( source, shapes_of( *source ) ).second;
				};

			for ( auto first = candidates.begin( ); first != candidates.end( ); )
			{
				const auto damage = first->damage;
				const auto last = std::find_if( first, candidates.end( ), [ damage ]( const candidate& entry ) { return entry.damage != damage; } );

				const candidate* best{};
				auto best_chance{ -1.0f };

				for ( auto entry = first; entry != last; ++entry )
				{
					if ( const auto chance = hitchance( eye, entry->point, shapes_for( entry->source ), table ); chance > best_chance )
					{
						best = &*entry;
						best_chance = chance;
					}
				}

				if ( best && best_chance >= needed )
				{
					return *best;
				}

				first = last;
			}

			return std::nullopt;
		}

		[[nodiscard]] static std::optional<candidate> choose( std::span<const target> targets, std::vector<std::vector<candidate>>& scanned, const sdk::vector3& eye, const spread_table& table, float needed )
		{
			std::vector<std::optional<candidate>> picks( targets.size( ) );

			core::g_thread_pool.parallel_for( static_cast< int >( targets.size( ) ), [ & ]( int index )
				{
					const auto slot = static_cast< std::size_t >( index );

					if ( !scanned[ slot ].empty( ) )
					{
						picks[ slot ] = pick( scanned[ slot ], eye, table, needed );
					}
				} );

			std::optional<candidate> best{};
			auto best_lethal{ false };

			for ( auto index = 0ull; index < targets.size( ); ++index )
			{
				const auto& entry = picks[ index ];
				if ( !entry )
				{
					continue;
				}

				const auto lethal = entry->damage >= static_cast< float >( targets[ index ].health );
				if ( !best || ( lethal && !best_lethal ) || ( lethal == best_lethal && entry->damage > best->damage ) )
				{
					best = entry;
					best_lethal = lethal;
				}
			}

			return best;
		}

		[[nodiscard]] static std::optional<float> stopped_inaccuracy( input::command& command, float accurate, float max_speed, int ready_in, bool in_air )
		{
			const auto& start = prediction::g_engine.start( );
			if ( start.on_ground( ) )
			{
				return command.predict_inaccuracy( sdk::vector3{} );
			}

			if ( !in_air )
			{
				return std::nullopt;
			}

			const auto velocity = start.velocity;
			const auto speed = velocity.length_2d( );
			const auto capacity = core::g_game.air_accelerate->get<float>( ) * max_speed * k_tick_interval;
			const auto ticks = speed > accurate && capacity > 0.0f ? static_cast< int >( std::ceil( ( speed - accurate ) / capacity ) ) : 0;

			if ( ready_in > 0 && ticks <= ready_in )
			{
				return std::nullopt;
			}

			const auto scale = speed > accurate ? accurate / speed : 1.0f;
			const auto fall = core::g_game.gravity->get<float>( ) * k_tick_interval * static_cast< float >( std::max( ticks, ready_in ) );

			return command.predict_inaccuracy( sdk::vector3{ velocity.x * scale, velocity.y * scale, velocity.z - fall } );
		}

	} // namespace detail

	void ragebot::run( input::command& command )
	{
		if ( !settings::g_rage.enabled.get( ) || command.holds( sdk::buttons::attack ) )
		{
			return;
		}

		const auto controller = core::local_controller( );
		const auto pawn = prediction::g_engine.pawn( );
		const auto services = pawn ? pawn->weapons( ) : nullptr;
		const auto weapon = services ? core::entities( )->get<sdk::cs_weapon_base>( services->active_weapon( ) ) : nullptr;
		const auto vdata = weapon ? weapon->vdata<sdk::weapon_vdata>( ) : nullptr;
		const auto group = weapon ? detail::group_of( weapon->item_definition_index( ) ) : std::nullopt;

		if ( !controller || !vdata || !group || weapon->in_reload( ) || weapon->clip( ) <= 0 )
		{
			return;
		}

		const auto& cfg = settings::g_rage.weapon( *group );
		const auto tick_base = controller->tick_base( );
		if ( this->m_last_shot_tick > tick_base )
		{
			this->m_last_shot_tick = -1;
		}

		const auto mode = std::clamp( weapon->weapon_mode( ), 0, 1 );
		const auto accurate = detail::accurate_speed( vdata, mode );
		const auto& start = prediction::g_engine.start( );
		const auto airborne = !start.on_ground( );
		const auto landing = airborne && command.predict( ).touched_down( start );
		const auto ready_in = std::max( { landing ? 1 : 0, weapon->next_primary_attack_tick( ) - tick_base, this->m_last_shot_tick + detail::k_shot_cooldown - tick_base } );
		const auto autostop = cfg.autostop.get( );
		const auto stop_in_air = autostop && cfg.autostop_in_air.get( );
		const auto holding = autostop && cfg.autostop_between_shots.get( ) && this->m_last_shot_tick >= 0 && tick_base - this->m_last_shot_tick <= detail::k_max_cycle_ticks;
		const auto braking = stop_in_air && airborne && this->m_air_brake_command == command.number( ) - 1 && start.velocity.length_2d( ) > accurate + detail::k_air_slack;

		this->m_air_brake_command = -1;

		if ( ready_in > 0 && !( airborne ? stop_in_air : holding ) )
		{
			return;
		}

		const auto boxes = aim_boxes( cfg );
		if ( boxes.empty( ) || !g_penetration.prepare( pawn, vdata ) )
		{
			return;
		}

		const auto mask = std::accumulate( boxes.begin( ), boxes.end( ), 0u, [ ]( std::uint32_t bits, const aim_box& box ) { return bits | ( 1u << box.index ); } );
		const auto lerp = detail::shot_lerp( controller );
		const auto label = static_cast< double >( tick_base ) + 1.0 - lerp;
		const auto eye = command.predict_shot_eye( label );

		weapon_spread spread{ weapon->item_definition_index( ), mode, command.predict_inaccuracy( ), vdata->spread( )[ static_cast< std::size_t >( mode ) ], weapon->recoil_index( ), vdata->range( ) };
		const auto spread_angle = std::atan( std::max( detail::k_min_spread, spread.inaccuracy + spread.spread ) );
		const auto needed = static_cast< float >( cfg.hitchance.get( ) ) / 100.0f;

		const auto fire = [ & ]( const detail::candidate& best )
			{
				const auto punch = aim_punch( pawn, tick_base, 0.0f );
				const auto fired_eye = command.predict_shot_eye( label );

				auto angles = sdk::angles_to( fired_eye, best.point ) - punch;
				angles.x = std::clamp( angles.x, -detail::k_max_pitch, detail::k_max_pitch );
				angles.y = sdk::normalize_yaw( angles.y );

				if ( !command.shoot( { angles, best.source->tick + 1 + g_records.lerp_ticks( ), tick_base + 1 } ) )
				{
					return;
				}

				this->m_last_shot_tick = tick_base;

				const sdk::vector3 shown{ command.view_pitch( ), command.view_yaw( ), 0.0f };
				const auto lead_ticks = std::max( 0, core::client_tick( ) - core::server_tick( ) ) + static_cast< int >( lerp ) + 1;
				const auto view = g_records.shot_view( shown, fired_eye, best.point, *best.source, punch, command.predict( ).origin, lead_ticks );

				if ( view.x != shown.x || view.y != shown.y )
				{
					command.turn( view.x, view.y );
				}
			};

		const auto targets = detail::find_targets( controller, pawn, eye, core::view_angles( ) );

		std::vector<std::vector<detail::candidate>> scanned( targets.size( ) );

		for ( auto index = 0ull; index < targets.size( ); ++index )
		{
			const auto required = std::min( static_cast< float >( cfg.min_damage.get( ) ), static_cast< float >( targets[ index ].health ) );
			scanned[ index ] = detail::scan( targets[ index ].pawn, eye, boxes, mask, required, spread_angle, needed );
		}

		if ( std::ranges::all_of( scanned, [ ]( const auto& entry ) { return entry.empty( ); } ) )
		{
			return;
		}

		if ( ready_in == 0 )
		{
			if ( const auto best = detail::choose( targets, scanned, eye, build_spread( spread ), needed ) )
			{
				fire( *best );
				return;
			}
		}

		if ( !autostop )
		{
			return;
		}

		if ( !braking )
		{
			const auto stopped = detail::stopped_inaccuracy( command, accurate, vdata->max_speed( ), ready_in, stop_in_air );
			if ( !stopped )
			{
				return;
			}

			auto at_rest = spread;
			at_rest.inaccuracy = *stopped;

			if ( !detail::choose( targets, scanned, eye, build_spread( at_rest ), needed ) )
			{
				return;
			}
		}

		g_autostop.run( command, accurate, stop_in_air );

		if ( airborne )
		{
			this->m_air_brake_command = command.number( );
		}

		if ( ready_in == 0 )
		{
			spread.inaccuracy = command.predict_inaccuracy( );

			if ( const auto best = detail::choose( targets, scanned, eye, build_spread( spread ), needed ) )
			{
				fire( *best );
			}
		}
	}

} // namespace opaline::rage

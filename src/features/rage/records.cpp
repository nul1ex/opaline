#include <pch.hpp>
#include <features/rage/records.hpp>
#include <core/game.hpp>
#include <settings.hpp>

namespace opaline::rage {

	namespace detail {

		constexpr auto k_tick_interval{ 1.0f / 64.0f };
		constexpr auto k_max_players{ 64 };
		constexpr auto k_bone_mask_all{ 0xFFFFFu };

		constexpr auto k_teleport_distance_sqr{ 64.0f * 64.0f };
		constexpr auto k_teleport_ticks{ 5 };
		constexpr auto k_max_backtrack{ 0.2f };

		constexpr auto k_fake_pitch{ 179.0f };
		constexpr auto k_shown_pitch{ 89.9f };
		constexpr auto k_lagcomp_angle{ 45.0f };
		constexpr auto k_min_cone_margin{ 2.5f };
		constexpr auto k_max_cone_margin{ 12.0f };
		constexpr auto k_position_slack{ 10.0f };
		constexpr auto k_hidden_side{ 80.0f };
		constexpr auto k_hidden_cone{ 44.0f };
		constexpr auto k_hidden_min_cone{ 15.0f };
		constexpr auto k_hidden_look_margin{ 0.2f };
		constexpr auto k_hidden_yaw_step{ 0.5f };
		constexpr auto k_hidden_yaw_steps{ 90 };
		constexpr auto k_hidden_refine_steps{ 8 };

		[[nodiscard]] static int time_to_ticks( float time )
		{
			return static_cast< int >( 0.5f + time / k_tick_interval );
		}

		[[nodiscard]] static bool capture( record& out, sdk::cs_player_pawn* pawn, sdk::game_scene_node* node, sdk::global_vars* globals )
		{
			using setup_bones_fn = void( __fastcall* )( sdk::game_scene_node*, std::uint32_t );
			using invalidate_bones_fn = void( __fastcall* )( sdk::game_scene_node* );

			const auto abs_origin = node->abs_origin( );
			const auto abs_rotation = node->abs_rotation( );
			const auto tick_count = globals->tick_count( );
			const auto simulation_time = pawn->simulation_time( );
			const auto current_time = globals->current_time( );

			node->abs_origin( ) = node->origin( );
			node->abs_rotation( ) = node->rotation( );
			globals->tick_count( ) = time_to_ticks( current_time );
			pawn->simulation_time( ) = current_time;

			reinterpret_cast< invalidate_bones_fn >( core::g_game.invalidate_bones )( node );
			node->force_bone_setup( ) = true;
			reinterpret_cast< setup_bones_fn >( core::g_game.setup_bones )( node, k_bone_mask_all );

			out.node_to_world = node->node_to_world( );

			const auto cache = node->bone_cache( );
			const auto count = std::min( static_cast< int >( node->bone_count( ) ), k_max_bones );

			globals->tick_count( ) = tick_count;
			pawn->simulation_time( ) = simulation_time;
			node->abs_origin( ) = abs_origin;
			node->abs_rotation( ) = abs_rotation;

			if ( !cache || count <= 0 )
			{
				return false;
			}

			std::copy_n( cache, count, out.bones.begin( ) );

			out.pawn = pawn;
			out.node = node;
			out.bone_count = count;
			out.origin = node->origin( );
			out.velocity = pawn->velocity( );
			out.simulation_time = simulation_time;
			out.tick = time_to_ticks( simulation_time );

			return true;
		}

		[[nodiscard]] static sdk::vector3 view_forward( float pitch, float yaw )
		{
			const auto p = pitch * sdk::k_rad_per_deg;
			const auto y = yaw * sdk::k_rad_per_deg;

			return { std::cos( p ) * std::cos( y ), std::cos( p ) * std::sin( y ), -std::sin( p ) };
		}

		[[nodiscard]] static sdk::vector3 hidden_view( const sdk::vector3& base, const sdk::vector3& eye, const sdk::vector3& target, const sdk::vector3& shooter_origin, const sdk::vector3& target_origin, const sdk::vector3& target_origin_lead, const sdk::vector3& punch )
		{
			const auto direction = [ &shooter_origin ]( const sdk::vector3& to )
				{
					const auto delta = to - shooter_origin;
					return delta.length_sqr( ) > 1.0f ? delta.normalized( ) : sdk::vector3{};
				};

			const auto margin = std::clamp( std::atan2( k_position_slack, ( target_origin - shooter_origin ).length( ) ) * sdk::k_deg_per_rad, k_min_cone_margin, k_max_cone_margin );
			const auto lagcomp_cone = std::cos( ( k_lagcomp_angle - margin ) * sdk::k_rad_per_deg );
			const auto lagcomp = direction( target_origin );
			const auto lagcomp_lead = direction( target_origin_lead );
			const auto to_target = target - eye;

			if ( to_target.length_sqr( ) < 1.0f )
			{
				return base;
			}

			const auto n = to_target.normalized( );
			auto side = sdk::vector3{ -n.y, n.x, 0.0f };
			side = side.length_sqr( ) > 1e-6f ? side.normalized( ) : sdk::vector3{ 0.0f, 1.0f, 0.0f };

			const auto size = std::acos( std::clamp( n.dot( ( target + side * k_hidden_side - eye ).normalized( ) ), -1.0f, 1.0f ) ) * sdk::k_deg_per_rad;
			const auto cone = std::max( k_hidden_cone - size, k_hidden_min_cone );
			const auto limit = std::sin( cone * sdk::k_rad_per_deg );

			const auto hides = [ & ]( const sdk::vector3& forward ) { return forward.dot( n ) > limit && forward.dot( lagcomp ) >= lagcomp_cone && forward.dot( lagcomp_lead ) >= lagcomp_cone; };
			const auto base_forward = view_forward( base.x, base.y );

			if ( hides( base_forward ) )
			{
				return base;
			}

			auto axis = n.cross( base_forward );
			axis = axis.length_sqr( ) > 1e-6f ? axis.normalized( ) : sdk::vector3{ 0.0f, 0.0f, 1.0f };

			auto fallback = sdk::angles_to( {}, n );

			for ( auto turn = cone; turn > 0.0f; turn -= 1.0f )
			{
				const auto radians = turn * sdk::k_rad_per_deg;
				const auto turned = n * std::cos( radians ) + axis.cross( n ) * std::sin( radians );

				if ( hides( turned ) )
				{
					fallback = sdk::angles_to( {}, turned );
					break;
				}
			}

			const auto aim = sdk::angles_to( {}, n );
			const auto low = base.x < -45.0f ? -k_fake_pitch : k_shown_pitch;
			const auto alias = 180.0f - std::max( sdk::normalize_yaw( aim.x ), 0.0f );

			auto pitch = k_fake_pitch < alias ? k_fake_pitch : std::max( low, alias );
			const auto shown = pitch + punch.x;

			if ( shown < low )
			{
				pitch += low - shown;
			}
			else if ( shown > k_fake_pitch )
			{
				pitch -= shown - k_fake_pitch;
			}

			const auto flip_yaw = sdk::normalize_yaw( aim.y - 180.0f );
			const auto passes = [ & ]( float yaw ) { return hides( view_forward( pitch, yaw ) ); };

			if ( !passes( flip_yaw ) )
			{
				return { fallback.x, fallback.y, 0.0f };
			}

			auto yaw = flip_yaw;
			const auto toward = sdk::normalize_yaw( base.y - flip_yaw );

			if ( std::fabs( toward ) > 1.0f )
			{
				if ( passes( base.y ) )
				{
					yaw = base.y;
				}
				else
				{
					const auto sign = toward > 0.0f ? 1.0f : -1.0f;

					auto good{ 0.0f };
					auto bad{ std::fabs( toward ) };

					for ( auto step = 1; step <= k_hidden_yaw_steps && k_hidden_yaw_step * static_cast< float >( step ) < bad; ++step )
					{
						if ( !passes( sdk::normalize_yaw( flip_yaw + sign * k_hidden_yaw_step * static_cast< float >( step ) ) ) )
						{
							bad = k_hidden_yaw_step * static_cast< float >( step );
							break;
						}

						good = k_hidden_yaw_step * static_cast< float >( step );
					}

					for ( auto step = 0; step < k_hidden_refine_steps; ++step )
					{
						const auto middle = 0.5f * ( good + bad );
						( passes( sdk::normalize_yaw( flip_yaw + sign * middle ) ) ? good : bad ) = middle;
					}

					yaw = sdk::normalize_yaw( flip_yaw + sign * good );
				}
			}

			const auto look_fallback = view_forward( std::clamp( fallback.x, -k_shown_pitch, k_shown_pitch ), fallback.y ).dot( base_forward );
			const auto look_flip = view_forward( std::clamp( sdk::normalize_yaw( pitch ), -k_shown_pitch, k_shown_pitch ), yaw ).dot( base_forward );

			if ( std::max( look_fallback - k_hidden_look_margin, -1.0f ) > look_flip )
			{
				return { fallback.x, fallback.y, 0.0f };
			}

			return { pitch, yaw, 0.0f };
		}

	} // namespace detail

	records::scope::scope( const record& target ) noexcept
	{
		g_records.m_applied.store( &target, std::memory_order_release );
	}

	records::scope::~scope( )
	{
		g_records.m_applied.store( nullptr, std::memory_order_release );
	}

	void records::update( )
	{
		const auto controller = core::local_controller( );
		const auto local = core::local_pawn( controller );
		const auto system = core::entities( );
		const auto globals = core::globals( );

		if ( !settings::g_rage.enabled.get( ) || !local || !system || !globals )
		{
			this->m_records.clear( );
			return;
		}

		std::unordered_set<sdk::cs_player_pawn*> active{};

		for ( auto index = 1; index <= detail::k_max_players; ++index )
		{
			const auto owner = static_cast< sdk::cs_player_controller* >( system->get( index ) );

			if ( !owner || owner == controller || !owner->pawn_alive( ) )
			{
				continue;
			}

			const auto pawn = system->get<sdk::cs_player_pawn>( owner->player_pawn( ) );

			if ( pawn && pawn != local && pawn->health( ) > 0 && core::is_enemy( local->team( ), pawn->team( ) ) && pawn->scene_node( ) )
			{
				active.insert( pawn );
			}
		}

		std::erase_if( this->m_records, [ & ]( const auto& entry ) { return !active.contains( entry.first ); } );

		const auto max_records = static_cast< std::size_t >( core::g_game.max_unlag->get<float>( ) / detail::k_tick_interval ) + 2;

		for ( const auto pawn : active )
		{
			auto& history = this->m_records[ pawn ];
			const auto node = pawn->scene_node( );
			const auto tick = detail::time_to_ticks( pawn->simulation_time( ) );

			if ( !history.empty( ) )
			{
				const auto& newest = history.front( );
				const auto ticks = std::clamp( tick - newest.tick, 1, detail::k_teleport_ticks );

				if ( ( node->origin( ) - newest.origin ).length_sqr( ) > detail::k_teleport_distance_sqr * static_cast< float >( ticks ) )
				{
					history.clear( );
				}
			}

			while ( !history.empty( ) && !this->valid( history.back( ) ) )
			{
				history.pop_back( );
			}

			while ( history.size( ) > max_records )
			{
				history.pop_back( );
			}

			if ( history.empty( ) || tick > history.front( ).tick )
			{
				if ( !detail::capture( history.emplace_front( ), pawn, node, globals ) )
				{
					history.pop_front( );
				}
			}

			for ( auto& entry : history )
			{
				entry.was_valid = this->valid( entry );
			}
		}
	}

	std::vector<const record*> records::records_for( sdk::cs_player_pawn* pawn ) const
	{
		std::vector<const record*> out{};

		const auto it = this->m_records.find( pawn );
		const auto controller = core::local_controller( );
		const auto globals = core::globals( );

		if ( it == this->m_records.end( ) || !controller || !globals )
		{
			return out;
		}

		const auto window = std::min( detail::k_max_backtrack, core::g_game.max_unlag->get<float>( ) );
		const auto min_simulation_time = static_cast< float >( controller->tick_base( ) ) * detail::k_tick_interval - window;
		const auto newest_reachable = globals->tick_count( ) - 1 - this->lerp_ticks( );

		for ( const auto& entry : it->second )
		{
			if ( !entry.was_valid || entry.tick > newest_reachable || ( !out.empty( ) && entry.simulation_time < min_simulation_time ) )
			{
				continue;
			}

			out.push_back( &entry );
		}

		return out;
	}

	int records::lerp_ticks( ) const
	{
		auto ratio = core::g_game.interp_ratio->get<float>( );
		const auto low = core::g_game.min_interp_ratio->get<float>( );
		const auto high = core::g_game.max_interp_ratio->get<float>( );

		if ( low <= high )
		{
			ratio = std::clamp( ratio, low, high );
		}

		return std::max( 0, static_cast< int >( ratio + 0.5f ) );
	}

	sdk::vector3 records::shot_view( const sdk::vector3& base, const sdk::vector3& eye, const sdk::vector3& target, const record& source, const sdk::vector3& punch, const sdk::vector3& shooter_origin, int lead_ticks ) const
	{
		const auto node = source.pawn->scene_node( );
		const auto origin = node ? node->origin( ) : source.origin;
		const auto lead = origin + sdk::vector3{ source.velocity.x, source.velocity.y, 0.0f } * ( static_cast< float >( lead_ticks ) * detail::k_tick_interval );

		return detail::hidden_view( base, eye, target, shooter_origin, origin, lead, punch );
	}

	void records::override_transforms( sdk::game_scene_node* skeleton, const sdk::hitbox_shapes* shapes, sdk::hitbox_transforms* transforms ) const
	{
		using hitbox_bone_fn = int( __fastcall* )( sdk::model*, const sdk::hitbox_shape_entry* );

		const auto applied = this->m_applied.load( std::memory_order_acquire );
		if ( !applied || applied->node != skeleton )
		{
			return;
		}

		const auto handle = skeleton->model( );
		const auto model = handle ? *handle : nullptr;

		if ( shapes->count <= 0 || !shapes->entries || !transforms->entries || !model )
		{
			return;
		}

		const auto root_delta = applied->node_to_world.position - skeleton->node_to_world( ).position;

		for ( auto index = 0; index < shapes->count; ++index )
		{
			const auto& entry = shapes->entries[ index ];
			const auto bone = reinterpret_cast< hitbox_bone_fn >( core::g_game.hitbox_bone )( model, &entry );
			auto& transform = transforms->entries[ index ];

			if ( bone < 0 )
			{
				transform = applied->node_to_world;
			}
			else if ( entry.shape && entry.shape->root_attached( ) )
			{
				transform.position += root_delta;
			}
			else if ( bone < applied->bone_count )
			{
				transform = applied->bones[ static_cast< std::size_t >( bone ) ];
			}
		}
	}

	void records::override_broadphase( const sdk::broadphase_tree* tree, sdk::broadphase_candidates* candidates ) const
	{
		const auto applied = this->m_applied.load( std::memory_order_acquire );
		const auto identity = applied ? applied->pawn->identity( ) : nullptr;

		if ( !identity || !tree->handles || !candidates->slots || tree->slot_count <= 0 )
		{
			return;
		}

		const auto handle = identity->handle( ).value;

		for ( auto index = 0; index < candidates->count; ++index )
		{
			if ( tree->handles[ candidates->slots[ index ] ] == handle )
			{
				return;
			}
		}

		if ( candidates->count >= candidates->capacity )
		{
			return;
		}

		for ( auto slot = 0; slot < tree->slot_count; ++slot )
		{
			if ( tree->handles[ slot ] == handle )
			{
				candidates->slots[ candidates->count++ ] = slot;
				return;
			}
		}
	}

	bool records::valid( const record& entry ) const
	{
		const auto globals = core::globals( );
		if ( !globals || entry.simulation_time <= 0.0f )
		{
			return false;
		}

		const auto current_time = globals->current_time( );
		return entry.simulation_time >= current_time - core::g_game.max_unlag->get<float>( ) - detail::k_tick_interval && entry.simulation_time <= current_time;
	}

} // namespace opaline::rage

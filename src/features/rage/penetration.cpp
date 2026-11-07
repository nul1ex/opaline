#include <pch.hpp>
#include <features/rage/penetration.hpp>
#include <core/game.hpp>

namespace opaline::rage {

	namespace detail {

		constexpr auto k_bullet_mask{ 0x1C300Bull };
		constexpr auto k_bullet_exclude{ 0x4000000000ull };
		constexpr std::uint8_t k_bullet_layer{ 3 };
		constexpr auto k_bullet_filter_type{ 15 };
		constexpr std::uint8_t k_bullet_options{ 1u << 1 };
		constexpr auto k_max_penetrations{ 4 };

		constexpr auto k_max_hitgroup{ 11 };
		constexpr auto k_max_hitbox{ 32 };

		constexpr std::uint8_t k_counter_terrorists{ 3 };
		constexpr auto k_armor_bonus{ 0.5f };

		namespace hitgroups {

			constexpr int head{ 1 };
			constexpr int chest{ 2 };
			constexpr int stomach{ 3 };
			constexpr int left_arm{ 4 };
			constexpr int right_arm{ 5 };
			constexpr int left_leg{ 6 };
			constexpr int right_leg{ 7 };
			constexpr int neck{ 8 };

		} // namespace hitgroups

		[[nodiscard]] static const sdk::trace_contact* contact_at( const sdk::trace_data& trace, int index )
		{
			return index >= 0 && index < trace.contact_count && trace.contacts ? trace.contacts + index : nullptr;
		}

	} // namespace detail

	bool penetration::prepare( sdk::cs_player_pawn* shooter, sdk::weapon_vdata* vdata )
	{
		this->m_damage = static_cast< float >( vdata->damage( ) );
		this->m_penetration = vdata->penetration( );
		this->m_range = vdata->range( );
		this->m_range_modifier = vdata->range_modifier( );
		this->m_armor_ratio = vdata->armor_ratio( );
		this->m_headshot_multiplier = vdata->headshot_multiplier( );
		this->m_team = shooter->team( );

		this->m_filter = core::trace_filter( shooter, detail::k_bullet_mask, detail::k_bullet_layer, detail::k_bullet_filter_type );
		this->m_filter.exclude_mask |= detail::k_bullet_exclude;
		this->m_filter.options |= detail::k_bullet_options;

		return this->m_damage > 0.0f && this->m_range > 0.0f;
	}

	std::optional<penetration::result> penetration::run( const sdk::vector3& start, const sdk::vector3& end, const target& victim ) const
	{
		using create_trace_fn = void( __fastcall* )( sdk::trace_data*, sdk::vector3, sdk::vector3, sdk::trace_filter, int, bool );
		using handle_penetration_fn = void( __fastcall* )( sdk::trace_data*, float, float, float, int, int, std::uint64_t );

		sdk::trace_data trace{};
		trace.contacts = trace.storage.data( );

		reinterpret_cast< create_trace_fn >( core::g_game.create_trace )( &trace, start, ( end - start ).normalized( ) * this->m_range, this->m_filter, detail::k_max_penetrations, true );

		if ( trace.hit_count <= 0 )
		{
			return std::nullopt;
		}

		reinterpret_cast< handle_penetration_fn >( core::g_game.handle_bullet_penetration )( &trace, this->m_damage, this->m_penetration, this->m_range_modifier, detail::k_max_penetrations, this->m_team, 0 );

		for ( auto index = 0; index < trace.hit_count && trace.hits; ++index )
		{
			const auto& hit = trace.hits[ index ];

			if ( hit.damage <= 0.0f )
			{
				break;
			}

			if ( hit.can_penetrate & 1 )
			{
				if ( hit.exit_fraction == 1.0f )
				{
					break;
				}

				continue;
			}

			const auto contact = detail::contact_at( trace, hit.exit_contact );

			if ( !contact || contact->is_body != 1 || !contact->body || core::entities( )->get<sdk::base_entity>( sdk::handle{ contact->entity } ) != victim.pawn )
			{
				continue;
			}

			const auto body = static_cast< const sdk::trace_body* >( contact->body );

			if ( body->hitgroup < 0 || body->hitgroup > detail::k_max_hitgroup )
			{
				continue;
			}

			if ( body->hitbox >= detail::k_max_hitbox || !( ( victim.hitbox_mask >> body->hitbox ) & 1u ) )
			{
				break;
			}

			return result{ this->scale_damage( hit.damage, body->hitgroup, victim ), body->hitgroup, body->hitbox };
		}

		return std::nullopt;
	}

	float penetration::scale_damage( float damage, int hitgroup, const target& victim ) const
	{
		const auto counter_terrorist = victim.team == detail::k_counter_terrorists;
		const auto head_scale = ( counter_terrorist ? core::g_game.damage_scale_ct_head : core::g_game.damage_scale_t_head )->get<float>( );
		const auto body_scale = ( counter_terrorist ? core::g_game.damage_scale_ct_body : core::g_game.damage_scale_t_body )->get<float>( );

		switch ( hitgroup )
		{
		case detail::hitgroups::head:
			damage *= this->m_headshot_multiplier * head_scale;
			break;
		case detail::hitgroups::chest:
		case detail::hitgroups::left_arm:
		case detail::hitgroups::right_arm:
		case detail::hitgroups::neck:
			damage *= body_scale;
			break;
		case detail::hitgroups::stomach:
			damage *= 1.25f * body_scale;
			break;
		case detail::hitgroups::left_leg:
		case detail::hitgroups::right_leg:
			damage *= 0.75f * body_scale;
			break;
		default:
			break;
		}

		const auto head = hitgroup == detail::hitgroups::head;
		const auto armored = ( hitgroup >= detail::hitgroups::head && hitgroup <= detail::hitgroups::right_arm ) || hitgroup == detail::hitgroups::neck;

		if ( victim.armor <= 0 || !armored || ( head && !victim.helmet ) )
		{
			return std::floor( damage );
		}

		auto to_health = damage * this->m_armor_ratio * 0.5f;

		if ( ( damage - to_health ) * detail::k_armor_bonus > static_cast< float >( victim.armor ) )
		{
			to_health = damage - static_cast< float >( victim.armor ) / detail::k_armor_bonus;
		}

		return std::floor( to_health );
	}

} // namespace opaline::rage

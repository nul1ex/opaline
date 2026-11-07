#include <pch.hpp>
#include <features/rage/hitchance.hpp>
#include <core/game.hpp>

namespace opaline::rage {

	namespace detail {

		constexpr auto k_max_pellets{ 16ull };
		constexpr auto k_epsilon{ 1e-6f };

		[[nodiscard]] static float segment_distance_sqr( const sdk::vector3& p1, const sdk::vector3& q1, const sdk::vector3& p2, const sdk::vector3& q2 )
		{
			const auto d1 = q1 - p1;
			const auto d2 = q2 - p2;
			const auto r = p1 - p2;
			const auto a = d1.dot( d1 );
			const auto e = d2.dot( d2 );
			const auto f = d2.dot( r );

			auto s{ 0.0f };
			auto t{ 0.0f };

			if ( a <= k_epsilon && e <= k_epsilon )
			{
				return r.dot( r );
			}

			if ( a <= k_epsilon )
			{
				t = std::clamp( f / e, 0.0f, 1.0f );
			}
			else
			{
				const auto c = d1.dot( r );

				if ( e <= k_epsilon )
				{
					s = std::clamp( -c / a, 0.0f, 1.0f );
				}
				else
				{
					const auto b = d1.dot( d2 );
					const auto denominator = a * e - b * b;

					s = denominator > k_epsilon ? std::clamp( ( b * f - c * e ) / denominator, 0.0f, 1.0f ) : 0.0f;
					t = ( b * s + f ) / e;

					if ( t < 0.0f )
					{
						t = 0.0f;
						s = std::clamp( -c / a, 0.0f, 1.0f );
					}
					else if ( t > 1.0f )
					{
						t = 1.0f;
						s = std::clamp( ( b - c ) / a, 0.0f, 1.0f );
					}
				}
			}

			const auto closest = ( p1 + d1 * s ) - ( p2 + d2 * t );
			return closest.dot( closest );
		}

	} // namespace detail

	spread_table build_spread( const weapon_spread& weapon )
	{
		using calculate_spread_fn = void( __fastcall* )( std::int16_t, int, int, std::uint32_t, float, float, float, float*, float* );

		spread_table out{};
		out.range = weapon.range;

		for ( auto seed = 0u; seed < k_spread_seeds; ++seed )
		{
			std::array<float, detail::k_max_pellets> x{};
			std::array<float, detail::k_max_pellets> y{};

			reinterpret_cast< calculate_spread_fn >( core::g_game.calculate_spread )( static_cast< std::int16_t >( weapon.item_definition_index ), 1, weapon.mode, seed + 1, weapon.inaccuracy, weapon.spread, weapon.recoil_index, x.data( ), y.data( ) );
			out.offsets[ seed ] = { x[ 0 ], y[ 0 ] };
		}

		return out;
	}

	std::pair<sdk::vector3, sdk::vector3> spread_axes( const sdk::vector3& forward )
	{
		const auto side = sdk::vector3{ -forward.y, forward.x, 0.0f }.normalized( );

		if ( side.length_sqr( ) <= 0.0f )
		{
			return { { 0.0f, -1.0f, 0.0f }, { -forward.z, 0.0f, 0.0f } };
		}

		return { side * -1.0f, forward.cross( side ).normalized( ) };
	}

	float hitchance( const sdk::vector3& eye, const sdk::vector3& point, std::span<const capsule> shapes, const spread_table& table )
	{
		const auto forward = ( point - eye ).normalized( );

		if ( forward.length_sqr( ) <= 0.0f || shapes.empty( ) )
		{
			return 0.0f;
		}

		const auto [ right, up ] = spread_axes( forward );

		auto hits{ 0u };

		for ( const auto& [ x, y ] : table.offsets )
		{
			const auto end = eye + ( forward + right * x + up * y ).normalized( ) * table.range;
			const auto hit = std::ranges::any_of( shapes, [ & ]( const capsule& shape )
				{
					return detail::segment_distance_sqr( eye, end, shape.start, shape.end ) <= shape.radius * shape.radius;
				} );

			hits += hit ? 1u : 0u;
		}

		return static_cast< float >( hits ) / static_cast< float >( k_spread_seeds );
	}

} // namespace opaline::rage

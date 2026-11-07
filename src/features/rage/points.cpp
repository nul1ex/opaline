#include <pch.hpp>
#include <features/rage/points.hpp>
#include <features/rage/hitchance.hpp>

namespace opaline::rage {

	namespace detail {

		constexpr auto k_max_point_scale{ 0.97f };
		constexpr auto k_min_point_reach{ 0.5f };
		constexpr auto k_flat_edge{ 1.0f };
		constexpr auto k_min_point_distance{ 1.0f };
		constexpr std::array k_head_outline{ 90.0f, 0.0f, 180.0f };
		constexpr std::array k_body_outline{ 0.0f, 180.0f };

		[[nodiscard]] static float percent( const ui::setting<int>& value )
		{
			return static_cast< float >( value.get( ) ) / 100.0f;
		}

	} // namespace detail

	std::vector<aim_box> aim_boxes( const settings::rage_weapon& cfg )
	{
		std::vector<aim_box> out{};

		const auto add = [ &out ]( bool enabled, std::initializer_list<int> indices, float scale, std::span<const float> outline )
			{
				if ( !enabled )
				{
					return;
				}

				for ( const auto index : indices )
				{
					out.push_back( { index, scale, outline } );
				}
			};

		add( cfg.head.get( ), { 0 }, detail::percent( cfg.head_scale ), detail::k_head_outline );
		add( cfg.chest.get( ), { 4, 5, 6 }, detail::percent( cfg.chest_scale ), detail::k_body_outline );
		add( cfg.stomach.get( ), { 2, 3 }, detail::percent( cfg.stomach_scale ), detail::k_body_outline );
		add( cfg.arms.get( ), { 13, 14, 15, 16, 17, 18 }, 0.0f, {} );
		add( cfg.legs.get( ), { 7, 8, 9, 10 }, 0.0f, {} );
		add( cfg.feet.get( ), { 11, 12 }, 0.0f, {} );

		return out;
	}

	void add_points( std::vector<sdk::vector3>& out, const capsule& shape, const aim_box& box, const sdk::vector3& eye, float spread_angle, float needed )
	{
		const auto center = ( shape.start + shape.end ) * 0.5f;
		const auto distance = ( center - eye ).length( );

		out.push_back( center );

		if ( box.outline.empty( ) || distance < detail::k_min_point_distance )
		{
			return;
		}

		const auto reach = std::min( shape.radius * std::min( box.scale, detail::k_max_point_scale ), shape.radius - distance * spread_angle * needed );
		if ( reach < detail::k_min_point_reach )
		{
			return;
		}

		const auto [ right, up ] = spread_axes( ( center - eye ) / distance );
		const auto span = shape.end - shape.start;

		for ( const auto degrees : box.outline )
		{
			const auto radians = degrees * sdk::k_rad_per_deg;
			const auto direction = right * std::cos( radians ) + up * std::sin( radians );
			const auto extent = direction.dot( span );
			const auto anchor = std::fabs( extent ) > detail::k_flat_edge ? ( extent > 0.0f ? shape.end : shape.start ) : center;

			out.push_back( anchor + direction * reach );
		}
	}

} // namespace opaline::rage

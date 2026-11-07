#include <pch.hpp>
#include <features/rage/punch.hpp>

namespace opaline::rage {

	namespace detail {

		constexpr auto k_tick_interval{ 1.0f / 64.0f };
		constexpr auto k_rate{ 128.0f };
		constexpr auto k_max_steps{ 128 };
		constexpr auto k_angle_decay{ -0.0625f };
		constexpr auto k_linear_decay{ 0.140625f };
		constexpr auto k_velocity_decay{ -4.5f };
		constexpr auto k_cutoff{ 0.03125f };
		constexpr auto k_half_step{ 1.0f / 256.0f };
		constexpr auto k_scale{ 2.0f };

		[[nodiscard]] static sdk::vector3 velocity_at( const sdk::vector3& velocity, float seconds )
		{
			const auto out = velocity * std::exp( k_velocity_decay * std::max( seconds, 0.0f ) );
			return out.length( ) < k_cutoff ? sdk::vector3{} : out;
		}

		[[nodiscard]] static sdk::vector3 advance( sdk::vector3 angle, const sdk::vector3& velocity, int step )
		{
			angle = angle * std::exp( k_angle_decay );

			const auto length = angle.length( );
			angle = length <= k_linear_decay ? sdk::vector3{} : angle * ( 1.0f - k_linear_decay / length );

			const auto seconds_at = [ ]( int index ) { return static_cast< float >( index ) * 0.5f * k_tick_interval; };

			angle += velocity_at( velocity, seconds_at( step - 1 ) ) * k_half_step;
			angle += velocity_at( velocity, seconds_at( step ) ) * k_half_step;

			return angle;
		}

		[[nodiscard]] static sdk::quaternion quaternion_of( const sdk::vector3& angles )
		{
			const auto half = [ ]( float degrees ) { return std::pair{ std::sin( degrees * sdk::k_rad_per_deg * 0.5f ), std::cos( degrees * sdk::k_rad_per_deg * 0.5f ) }; };

			const auto [ sp, cp ] = half( angles.x );
			const auto [ sy, cy ] = half( angles.y );
			const auto [ sr, cr ] = half( angles.z );

			return { sr * cp * cy - cr * sp * sy, cr * sp * cy + sr * cp * sy, cr * cp * sy - sr * sp * cy, cr * cp * cy + sr * sp * sy };
		}

		[[nodiscard]] static sdk::vector3 angles_of( const sdk::quaternion& q )
		{
			const auto m00 = 1.0f - 2.0f * q.y * q.y - 2.0f * q.z * q.z;
			const auto m10 = 2.0f * q.x * q.y + 2.0f * q.w * q.z;
			const auto m20 = 2.0f * q.x * q.z - 2.0f * q.w * q.y;
			const auto m01 = 2.0f * q.x * q.y - 2.0f * q.w * q.z;
			const auto m11 = 1.0f - 2.0f * q.x * q.x - 2.0f * q.z * q.z;
			const auto m21 = 2.0f * q.y * q.z + 2.0f * q.w * q.x;
			const auto m22 = 1.0f - 2.0f * q.x * q.x - 2.0f * q.y * q.y;

			const auto xy = std::sqrt( m00 * m00 + m10 * m10 );
			if ( xy > 0.001f )
			{
				return { std::atan2( -m20, xy ) * sdk::k_deg_per_rad, std::atan2( m10, m00 ) * sdk::k_deg_per_rad, std::atan2( m21, m22 ) * sdk::k_deg_per_rad };
			}

			return { std::atan2( -m20, xy ) * sdk::k_deg_per_rad, std::atan2( -m01, m11 ) * sdk::k_deg_per_rad, 0.0f };
		}

		[[nodiscard]] static sdk::quaternion slerp( const sdk::quaternion& a, const sdk::quaternion& b, float t )
		{
			const auto dot = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
			const auto d = std::fabs( dot );

			auto k = ( ( ( ( 3.5564499f - d * 1.43519f ) * d - 3.2451999f ) * d + 1.0904f ) * ( ( t - 0.5f ) * ( t - 0.5f ) ) + ( ( d * 0.215638f - 1.06021f ) * d + 0.84801298f ) ) * ( t * ( t - 0.5f ) * ( t - 1.0f ) ) + t;
			const auto keep = 1.0f - k;

			if ( dot <= 0.0f )
			{
				k = -k;
			}

			const auto out = sdk::quaternion{ b.x * k + a.x * keep, b.y * k + a.y * keep, b.z * k + a.z * keep, b.w * k + a.w * keep };
			const auto length = std::sqrt( out.x * out.x + out.y * out.y + out.z * out.z + out.w * out.w );

			return length > 0.0f ? sdk::quaternion{ out.x / length, out.y / length, out.z / length, out.w / length } : sdk::quaternion{};
		}

	} // namespace detail

	sdk::vector3 aim_punch( sdk::cs_player_pawn* pawn, int tick, float fraction )
	{
		const auto angle = pawn->aim_punch_angle( );
		const auto velocity = pawn->aim_punch_velocity( );
		const auto elapsed = static_cast< float >( tick - pawn->aim_punch_tick_base( ) ) + ( fraction - pawn->aim_punch_tick_fraction( ) );

		auto out = angle;

		if ( elapsed > 0.0f )
		{
			const auto steps = elapsed * detail::k_tick_interval * detail::k_rate;
			const auto index = static_cast< int >( steps );
			const auto t = steps - static_cast< float >( index );
			const auto last = std::min( index + 2, detail::k_max_steps + 1 );

			sdk::vector3 step_a{};
			sdk::vector3 step_b{};
			auto current = angle;

			for ( auto step = 1; step <= last; ++step )
			{
				current = detail::advance( current, velocity, step );

				if ( step == index + 1 )
				{
					step_a = current;
				}

				if ( step == index + 2 )
				{
					step_b = current;
				}
			}

			const auto sample = [ & ]( int step, const sdk::vector3& cached )
				{
					return step <= last ? cached : current * std::pow( std::exp( detail::k_angle_decay ), static_cast< float >( step - last ) );
				};

			out = detail::angles_of( detail::slerp( detail::quaternion_of( sample( index + 1, step_a ) ), detail::quaternion_of( sample( index + 2, step_b ) ), t ) );
		}

		return out.length( ) < detail::k_cutoff ? sdk::vector3{} : out * detail::k_scale;
	}

} // namespace opaline::rage

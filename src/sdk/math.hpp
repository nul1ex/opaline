#pragma once

namespace opaline::sdk {

	constexpr auto k_rad_per_deg{ std::numbers::pi_v<float> / 180.0f };
	constexpr auto k_deg_per_rad{ 180.0f / std::numbers::pi_v<float> };

	[[nodiscard]] inline float normalize_yaw( float yaw )
	{
		return std::remainder( yaw, 360.0f );
	}

	struct vector3
	{
		float x{};
		float y{};
		float z{};

		[[nodiscard]] vector3 operator+( const vector3& other ) const noexcept { return { this->x + other.x, this->y + other.y, this->z + other.z }; }
		[[nodiscard]] vector3 operator-( const vector3& other ) const noexcept { return { this->x - other.x, this->y - other.y, this->z - other.z }; }
		[[nodiscard]] vector3 operator*( float scale ) const noexcept { return { this->x * scale, this->y * scale, this->z * scale }; }
		[[nodiscard]] vector3 operator/( float scale ) const noexcept { return { this->x / scale, this->y / scale, this->z / scale }; }

		vector3& operator+=( const vector3& other ) noexcept
		{
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			return *this;
		}

		vector3& operator-=( const vector3& other ) noexcept
		{
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			return *this;
		}

		[[nodiscard]] float dot( const vector3& other ) const noexcept { return this->x * other.x + this->y * other.y + this->z * other.z; }
		[[nodiscard]] vector3 cross( const vector3& other ) const noexcept { return { this->y * other.z - this->z * other.y, this->z * other.x - this->x * other.z, this->x * other.y - this->y * other.x }; }
		[[nodiscard]] float length_sqr( ) const noexcept { return this->dot( *this ); }
		[[nodiscard]] float length( ) const noexcept { return std::sqrt( this->length_sqr( ) ); }
		[[nodiscard]] float length_2d( ) const noexcept { return std::sqrt( this->x * this->x + this->y * this->y ); }
		[[nodiscard]] float distance( const vector3& other ) const noexcept { return ( *this - other ).length( ); }

		[[nodiscard]] vector3 normalized( ) const noexcept
		{
			const auto len = this->length( );
			return len > 0.0f ? *this / len : vector3{};
		}
	};

	struct quaternion
	{
		float x{};
		float y{};
		float z{};
		float w{ 1.0f };

		[[nodiscard]] vector3 rotate( const vector3& v ) const noexcept
		{
			const vector3 axis{ this->x, this->y, this->z };
			const auto uv = axis.cross( v );
			const auto uuv = axis.cross( uv );

			return v + uv * ( 2.0f * this->w ) + uuv * 2.0f;
		}
	};

	[[nodiscard]] inline vector3 angles_to( const vector3& from, const vector3& to )
	{
		const auto delta = to - from;
		return { std::atan2( -delta.z, delta.length_2d( ) ) * k_deg_per_rad, std::atan2( delta.y, delta.x ) * k_deg_per_rad, 0.0f };
	}

	struct matrix3x4
	{
		float m[ 3 ][ 4 ]{};

		[[nodiscard]] vector3 origin( ) const noexcept { return { this->m[ 0 ][ 3 ], this->m[ 1 ][ 3 ], this->m[ 2 ][ 3 ] }; }
	};

	struct matrix4x4
	{
		float m[ 4 ][ 4 ]{};
	};

} // namespace opaline::sdk

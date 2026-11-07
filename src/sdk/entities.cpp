#include <pch.hpp>
#include <sdk/entities.hpp>

namespace opaline::sdk {

	namespace detail {

		constexpr auto k_chunks{ 0x10ull };
		constexpr auto k_identity_size{ 0x70ull };
		constexpr auto k_max_index{ 0x7FFE };

	} // namespace detail

	base_entity* entity_system::get( int index ) const
	{
		if ( index < 0 || index > detail::k_max_index )
		{
			return nullptr;
		}

		const auto chunk = *reinterpret_cast< const std::uintptr_t* >( reinterpret_cast< std::uintptr_t >( this ) + detail::k_chunks + static_cast< std::size_t >( index >> 9 ) * sizeof( std::uintptr_t ) );
		if ( !chunk )
		{
			return nullptr;
		}

		return *reinterpret_cast< base_entity* const* >( chunk + static_cast< std::size_t >( index & 0x1FF ) * detail::k_identity_size );
	}

} // namespace opaline::sdk

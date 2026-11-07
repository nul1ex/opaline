#include <pch.hpp>
#include <sdk/engine.hpp>

namespace opaline::sdk {

	namespace detail {

		constexpr auto k_field_count{ 0x1Cull };
		constexpr auto k_fields{ 0x28ull };
		constexpr auto k_field_size{ 0x20ull };
		constexpr auto k_field_offset{ 0x10ull };

		constexpr auto k_convars{ 0x48ull };
		constexpr auto k_convar_head{ 0x50ull };
		constexpr auto k_convar_entry_size{ 0x10ull };
		constexpr auto k_convar_entry_next{ 0x0Aull };
		constexpr std::uint16_t k_convar_end{ 0xffff };

	} // namespace detail

	std::optional<std::uint32_t> schema_system::field_offset( const char* module, const char* class_name, std::string_view field ) const
	{
		const auto scope = vfunc<13, void*>( this, module, nullptr );
		if ( !scope )
		{
			return std::nullopt;
		}

		void* class_info{};
		vfunc<2>( scope, &class_info, class_name );

		if ( !class_info )
		{
			return std::nullopt;
		}

		const auto info = reinterpret_cast< std::uintptr_t >( class_info );
		const auto count = *reinterpret_cast< const std::uint16_t* >( info + detail::k_field_count );
		const auto fields = *reinterpret_cast< const std::uintptr_t* >( info + detail::k_fields );

		for ( auto i = 0u; fields && i < count; ++i )
		{
			const auto entry = fields + i * detail::k_field_size;
			const auto name = *reinterpret_cast< const char* const* >( entry );

			if ( name && field == name )
			{
				return *reinterpret_cast< const std::uint32_t* >( entry + detail::k_field_offset );
			}
		}

		return std::nullopt;
	}

	convar* cvar_system::find( std::string_view name ) const
	{
		const auto base = reinterpret_cast< std::uintptr_t >( this );
		const auto entries = *reinterpret_cast< const std::uintptr_t* >( base + detail::k_convars );

		if ( !entries )
		{
			return nullptr;
		}

		for ( auto index = *reinterpret_cast< const std::uint16_t* >( base + detail::k_convar_head ); index != detail::k_convar_end; )
		{
			const auto entry = entries + static_cast< std::uintptr_t >( index ) * detail::k_convar_entry_size;
			const auto variable = *reinterpret_cast< convar* const* >( entry );

			if ( variable && variable->name( ) && name == variable->name( ) )
			{
				return variable;
			}

			index = *reinterpret_cast< const std::uint16_t* >( entry + detail::k_convar_entry_next );
		}

		return nullptr;
	}

} // namespace opaline::sdk

#pragma once

#define FIELD( type, name, offset ) [[nodiscard]] type& name( ) { return *reinterpret_cast< type* >( reinterpret_cast< std::uintptr_t >( this ) + ( offset ) ); }

namespace opaline::sdk {

	[[nodiscard]] inline void* vtable_entry( const void* object, std::size_t index )
	{
		return ( *reinterpret_cast< void* const* const* >( object ) )[ index ];
	}

	template <std::size_t index, typename ret = void, typename... args>
	ret vfunc( const void* object, args... values )
	{
		using function = ret( __fastcall* )( const void*, args... );
		return reinterpret_cast< function >( vtable_entry( object, index ) )( object, values... );
	}

} // namespace opaline::sdk

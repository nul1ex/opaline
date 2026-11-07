#include <pch.hpp>
#include <ui/input.hpp>

namespace opaline::ui {

	int input::on_message( UINT msg, WPARAM wparam, LPARAM lparam )
	{
		auto key{ 0 };

		switch ( msg )
		{
		case WM_KEYDOWN:
		case WM_SYSKEYDOWN:
			key = ( lparam & ( 1 << 30 ) ) ? 0 : static_cast< int >( wparam );
			break;
		case WM_LBUTTONDOWN:
			key = VK_LBUTTON;
			break;
		case WM_RBUTTONDOWN:
			key = VK_RBUTTON;
			break;
		case WM_MBUTTONDOWN:
			key = VK_MBUTTON;
			break;
		case WM_XBUTTONDOWN:
			key = GET_XBUTTON_WPARAM( wparam ) == XBUTTON1 ? VK_XBUTTON1 : VK_XBUTTON2;
			break;
		default:
			break;
		}

		if ( key )
		{
			this->m_pressed.store( key );
		}

		return key;
	}

	bool key_held( int key )
	{
		return key > 0 && ( GetAsyncKeyState( key ) & 0x8000 ) != 0;
	}

	std::string key_name( int key )
	{
		switch ( key )
		{
		case 0:
			return "none";
		case VK_LBUTTON:
			return "mouse 1";
		case VK_RBUTTON:
			return "mouse 2";
		case VK_MBUTTON:
			return "mouse 3";
		case VK_XBUTTON1:
			return "mouse 4";
		case VK_XBUTTON2:
			return "mouse 5";
		default:
			break;
		}

		auto scan = MapVirtualKeyA( static_cast< UINT >( key ), MAPVK_VK_TO_VSC );

		if ( key == VK_INSERT || key == VK_DELETE || key == VK_HOME || key == VK_END || key == VK_PRIOR || key == VK_NEXT || ( key >= VK_LEFT && key <= VK_DOWN ) )
		{
			scan |= 0x100;
		}

		std::array<char, 64> name{};
		const auto length = GetKeyNameTextA( static_cast< LONG >( scan << 16 ), name.data( ), static_cast< int >( name.size( ) ) );

		auto out = length > 0 ? std::string( name.data( ), static_cast< std::size_t >( length ) ) : std::format( "key {:#x}", key );
		std::ranges::transform( out, out.begin( ), [ ]( unsigned char c ) { return static_cast< char >( std::tolower( c ) ); } );

		return out;
	}

} // namespace opaline::ui

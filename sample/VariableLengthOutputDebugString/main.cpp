#include <windows.h>

#include <tchar.h>
#include <vector>

namespace va {
	void Trace( LPCTSTR format, ... )
	{
		va_list args;
		va_start( args, format );

		std::vector<TCHAR> buffer( _vsctprintf( format, args ) + 1 );
		_vstprintf( &buffer[0], format, args );

		::OutputDebugString( &buffer[0] );
	}
}

void main()
{
	va::Trace( TEXT( "dec:%d, hex:%x, string:%s, wstring:%ws\n" ), 10, 0x10, "string", L"wstring" );
}

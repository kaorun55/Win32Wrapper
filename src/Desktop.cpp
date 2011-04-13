#include <cassert>

#include "win32/Desktop.h"
#include "win32/Win32Exception.h"

namespace win32 {
	Desktop::Desktop()
	{
	}

	Desktop::~Desktop()
	{
		Close();
	}

	void Desktop::OpenThreadDesktop( DWORD dwThreadId )
	{
		HDESK hDesktop = ::GetThreadDesktop( dwThreadId );
		if ( hDesktop == 0 ) {
			Throw_Win32Exception();
		}

		// GetThreadDesktop で取得したハンドルは解放する必要はない
		//  http://msdn.microsoft.com/ja-jp/library/cc364750.aspx
		handle_ = Handle( hDesktop, &Desktop::DummyCloseDesktop );
	}

	void Desktop::Close()
	{
		handle_.get();
	}

	void Desktop::Switch()
	{
		assert( IsValid() );

		BOOL ret = ::SwitchDesktop( handle_.get() );
		if ( !ret ) {
			Throw_Win32Exception();
		}
	}

	bool Desktop::IsValid() const
	{
		return handle_.get() != 0;
	}


	/*static*/ void Desktop::CloseDesktop( HDESK hDesktop )
	{
		BOOL ret = ::CloseDesktop( hDesktop );
		DWORD err = ::GetLastError();
		assert( ret );
	}

	/*static*/ void Desktop::DummyCloseDesktop( HDESK hDesktop )
	{
		// 何もしない
	}
}

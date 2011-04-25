#include <gtest/gtest.h>

#include "win32/DllLoader.h"

class DllLoaderTest : public ::testing::Test
{
public:

	void SetUp() {
		target.Open( TEXT( "user32.dll" ) );
	}

	void TearDown() {
	}

protected:

	win32::DllLoader target;
};

TEST_F( DllLoaderTest, Open ) 
{
	EXPECT_TRUE( target.IsOpen() );
}

TEST_F( DllLoaderTest, Close ) 
{
	EXPECT_TRUE( target.IsOpen() );

	target.Close();
	EXPECT_TRUE( !target.IsOpen() );
}

TEST_F( DllLoaderTest, GetProcAddress ) 
{
	typedef int (WINAPI *LOADMESSAGEBOX)( HWND hWnd, LPCTSTR lpText, LPCTSTR lpCaption, UINT uType );
	LOADMESSAGEBOX LoadMessageBox = target.GetProcAddress< LOADMESSAGEBOX >( "MessageBoxW" );
	EXPECT_EQ( ::MessageBoxW, LoadMessageBox );
}

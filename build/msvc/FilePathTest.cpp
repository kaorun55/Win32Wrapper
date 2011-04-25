#include <gtest/gtest.h>

#include "win32/FilePath.h"

class FilePathTest : public ::testing::Test
{
public:

	void SetUp() {
	}

	void TearDown() {
	}

protected:

	win32::FilePath target;
};

TEST_F( FilePathTest, SetGetPath ) 
{
	const win32::tstring path = TEXT( "C:\\Windows" );
	target.SetPath( path );
	EXPECT_EQ( path, target.GetPath() );

	const win32::tstring path2 = TEXT( "C:\\Windows\\System32" );
	target = path2;
	EXPECT_EQ( path2, target.GetPath() );

	const TCHAR* path3 = TEXT( "C:\\Windows\\System32\\drivers" );
	target = path3;
	EXPECT_EQ( path3, target.GetPath() );
}

TEST_F( FilePathTest, IsExists_static ) 
{
	EXPECT_TRUE( win32::FilePath::IsExists( TEXT( "C:\\Windows\\System32\\drivers" ) ) );
	EXPECT_FALSE( win32::FilePath::IsExists( TEXT( "C:\\Windows\\System500" ) ) );
}

TEST_F( FilePathTest, RemoveFileSpec ) 
{
	win32::tstring path = win32::FilePath::RemoveFileSpec( TEXT( "C:\\Windows\\System32\\drivers" ) );
	const win32::tstring expected = TEXT( "C:\\Windows\\System32" );
	EXPECT_EQ( expected, path );
}

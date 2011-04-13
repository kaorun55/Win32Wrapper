#include <gtest/gtest.h>

#include "win32/Desktop.h"

class DesktopTest : public ::testing::Test
{
public:

	virtual void SetUp() {
	}

	virtual void TearDown() {
	}

protected:

	win32::Desktop target;
};

TEST_F( DesktopTest, OpenThreadDesktop ) 
{
	target.OpenThreadDesktop( ::GetCurrentThreadId() );
	EXPECT_TRUE( target.IsValid() );
}

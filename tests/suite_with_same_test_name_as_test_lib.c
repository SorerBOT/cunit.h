#include "../lib/cunit.h"

CUNIT_TEST(assert_true)
{
    int x = 1, y = 2;
    CUNIT_EXPECT_TRUE(x+y == y);
    CUNIT_EXPECT_TRUE(x+y == y);
    CUNIT_ASSERT_TRUE(x+y == y);
    CUNIT_ASSERT_TRUE(x+y == y);
}

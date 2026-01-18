#include <stdio.h>
#include "../src/cunit.h"

CUNIT_TEST(test_to_be_skipped)
{
    CUNIT_ASSERT_INT_EQ(1, 2);
}

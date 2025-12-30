#include <stdio.h>
#include "../lib/cunit.h"

CUNIT_TEST(test_that_runs_with_a_different_setup_func)
{
    CUNIT_ASSERT_TRUE(5 == 5);
}

CUNIT_SETUP()
{
    printf("Different setup function....\n");
}

#include <stdio.h>
#include "../src/cunit.h"

CUNIT_SETUP()
{
    printf("Different setup function....\n");
}
CUNIT_CLEANUP()
{
    printf("Different cleanup function....\n");
}
CUNIT_SETUP_ONETIME()
{
    printf("Different setup_onetime function....\n");
}
CUNIT_CLEANUP_ONETIME()
{
    printf("Different cleanup_onetime function....\n");
}

CUNIT_TEST(test_that_runs_with_a_different_setup_func)
{
    CUNIT_ASSERT_TRUE(5 == 5);
}

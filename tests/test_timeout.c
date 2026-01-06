#include "../src/cunit.h"

CUNIT_TEST(timeout_test)
{
    volatile size_t x = 0;
    while (1)
    {
        ++x;
    }
}

CUNIT_TEST(timeout_test_2) /* just making sure several timeouts aren't problematic */
{
    volatile size_t x = 0;
    while (1)
    {
        ++x;
    }
}

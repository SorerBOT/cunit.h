#include "../lib/cunit.h"

CUNIT_TEST(timeout_test)
{
    volatile size_t x = 0;
    while (1)
    {
        ++x;
    }
}

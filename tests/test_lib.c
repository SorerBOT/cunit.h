#include <stdio.h>
#include "../lib/cuint.h"

void test1()
{
    ASSERT(1+2 == 2);
    ASSERT(1+2 == 2);
    ASSERT(1+2 == 2);
    ASSERT(1+2 == 2);
}

int main()
{
    cunit_test_t tests[] =
    {
        { .func = test1, .name = "Arithmetic" },
        { .func = test1, .name = "Rocket Science" },
        { .func = test1, .name = "shouldComputeSum" },
    };
    cunit_run_tests(tests, 3);
}

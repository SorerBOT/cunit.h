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
    cunit_test_func tests[] = { test1, test1, test1 };
    for (size_t i = 0; i < 3; ++i)
    {
        printf("============================================\n");
        cunit_test_func current_test = tests[i];
        cunit_test(current_test);
    }
    printf("============================================\n");
}

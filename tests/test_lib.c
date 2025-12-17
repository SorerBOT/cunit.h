#include <stdio.h>
#include <signal.h>
#include "../lib/cunit.h"

void test_bool()
{
    int x = 1, y = 2;
    EXPECT(x+y == y);
    EXPECT(x+y == y);
    ASSERT(x+y == y);
    ASSERT(x+y == y);
}
void test_int_eq()
{
    EXPECT_INT_EQ(1+2, 2);
    EXPECT_INT_EQ(1+2, 2);
    ASSERT_INT_EQ(1+2, 2);
    ASSERT_INT_EQ(1+2, 2);
}

void test_crash()
{
    raise(SIGSEGV);
}

void test_float_eq()
{
    float x = 1.f, y = 1.f, z = 1.000005;
    EXPECT_FLOAT_EQ(x, y);
    ASSERT_FLOAT_EQ(x, y);
    EXPECT_FLOAT_EQ(x, z);
    ASSERT_FLOAT_EQ_THRESHOLD(x, z, 0.0001);
}

int main()
{
    cunit_test_t tests[] =
    {
        { .func = test_bool, .name = "Arithmetic" },
        { .func = test_crash, .name = "Rocket Science" },
        { .func = test_int_eq, .name = "shouldComputeSum" },
        { .func = test_float_eq, .name = "test float equality"}
    };
    cunit_run_tests(tests, 4);
}

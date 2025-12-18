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

    float w = 2.f;
    EXPECT_FLOAT_EQ_THRESHOLD(x, z, 5);
    EXPECT_FLOAT_EQ(x, w);
    ASSERT_FLOAT_EQ(x, w);
}

void test_int_leq()
{
    int x = 1, y = 5, z = 1;
    EXPECT_INT_LEQ(x, y);
    ASSERT_INT_LEQ(x, y);

    ASSERT_INT_LEQ(x, z);
    ASSERT_INT_LEQ(z, x);

    ASSERT_INT_LEQ(y, x);
}

void test_float_leq()
{
    float x = 1.f, y = 5.f, z = 1.f, w = 1.00005;
    EXPECT_FLOAT_LEQ(x, y);
    ASSERT_FLOAT_LEQ(x, y);

    ASSERT_FLOAT_LEQ(x, z);
    ASSERT_FLOAT_LEQ(z, x);

    ASSERT_FLOAT_LEQ(x, w);
    ASSERT_FLOAT_LEQ(w, x);

    EXPECT_FLOAT_LEQ_THRESHOLD(w, x, 0.00001);
    ASSERT_FLOAT_LEQ(y, x);
}

void test_int_lower()
{
    int x = 1, y = 5, z = 1;

    ASSERT_INT_LOWER(x, y);
    EXPECT_INT_LOWER(x, z);
    ASSERT_INT_LOWER(y, z);
}

void test_float_lower()
{
    float x = 1.f, y = 5.f, z = 1.f, w = 1.00005;
    ASSERT_FLOAT_LOWER_THRESHOLD(x, w, 0.000001);
    ASSERT_FLOAT_LOWER(x, y);
    ASSERT_FLOAT_LOWER(x, w);
}

int main()
{
    cunit_test_t tests[] =
    {
        { .func = test_bool, .name = "Arithmetic" },
        { .func = test_crash, .name = "Rocket Science" },
        { .func = test_int_eq, .name = "shouldComputeSum" },
        { .func = test_float_eq, .name = "test float equality"},
        { .func = test_int_leq, .name = "test int leq"},
        { .func = test_float_leq, .name = "test float leq"},
        { .func = test_int_lower, .name = "test int lower"},
        { .func = test_float_lower, .name = "test float lower"},
    };
    cunit_run_tests(tests, 8);
}

#include <stdio.h>
#include <signal.h>
#include "../lib/cunit.h"

#define REGISTERATION_AUTOMATIQUE 1

void test_bool()
{
    int x = 1, y = 2;
    CUNIT_EXPECT(x+y == y);
    CUNIT_EXPECT(x+y == y);
    CUNIT_ASSERT(x+y == y);
    CUNIT_ASSERT(x+y == y);
}
void test_int_eq()
{
    CUNIT_EXPECT_INT_EQ(1+2, 2);
    CUNIT_EXPECT_INT_EQ(1+2, 2);
    CUNIT_ASSERT_INT_EQ(1+2, 2);
    CUNIT_ASSERT_INT_EQ(1+2, 2);
}

void test_crash()
{
    raise(SIGSEGV);
}

void test_float_eq()
{
    float x = 1.f, y = 1.f, z = 1.000005;
    CUNIT_EXPECT_FLOAT_EQ(x, y);
    CUNIT_ASSERT_FLOAT_EQ(x, y);
    CUNIT_EXPECT_FLOAT_EQ(x, z);
    CUNIT_ASSERT_FLOAT_EQ_THRESHOLD(x, z, 0.0001);

    float w = 2.f;
    CUNIT_EXPECT_FLOAT_EQ_THRESHOLD(x, z, 5);
    CUNIT_EXPECT_FLOAT_EQ(x, w);
    CUNIT_ASSERT_FLOAT_EQ(x, w);
}

void test_int_leq()
{
    int x = 1, y = 5, z = 1;
    CUNIT_EXPECT_INT_LEQ(x, y);
    CUNIT_ASSERT_INT_LEQ(x, y);

    CUNIT_ASSERT_INT_LEQ(x, z);
    CUNIT_ASSERT_INT_LEQ(z, x);

    CUNIT_ASSERT_INT_LEQ(y, x);
}

void test_float_leq()
{
    float x = 1.f, y = 5.f, z = 1.f, w = 1.00005;
    CUNIT_EXPECT_FLOAT_LEQ(x, y);
    CUNIT_ASSERT_FLOAT_LEQ(x, y);

    CUNIT_ASSERT_FLOAT_LEQ(x, z);
    CUNIT_ASSERT_FLOAT_LEQ(z, x);

    CUNIT_ASSERT_FLOAT_LEQ(x, w);
    CUNIT_ASSERT_FLOAT_LEQ(w, x);

    CUNIT_EXPECT_FLOAT_LEQ_THRESHOLD(w, x, 0.00001);
    CUNIT_ASSERT_FLOAT_LEQ(y, x);
}

void test_int_lower()
{
    int x = 1, y = 5, z = 1;

    CUNIT_ASSERT_INT_LOWER(x, y);
    CUNIT_EXPECT_INT_LOWER(x, z);
    CUNIT_ASSERT_INT_LOWER(y, z);
}

void test_float_lower()
{
    float x = 1.f, y = 5.f, z = 1.f, w = 1.00005;
    CUNIT_ASSERT_FLOAT_LOWER_THRESHOLD(x, w, 0.000001);
    CUNIT_ASSERT_FLOAT_LOWER(x, y);
    CUNIT_ASSERT_FLOAT_LOWER(x, w);
}

CUNIT_TEST(Arithmetic)
{
    int x = 1, y = 2;
    CUNIT_EXPECT(x+y == y);
    CUNIT_EXPECT(x+y == y);
    CUNIT_ASSERT(x+y == y);
    CUNIT_ASSERT(x+y == y);
}

CUNIT_TEST(int_eq)
{
    CUNIT_EXPECT_INT_EQ(1+2, 2);
    CUNIT_EXPECT_INT_EQ(1+2, 2);
    CUNIT_ASSERT_INT_EQ(1+2, 2);
    CUNIT_ASSERT_INT_EQ(1+2, 2);
}

CUNIT_TEST(crash)
{
    raise(SIGSEGV);
}

CUNIT_TEST(float_eq)
{
    float x = 1.f, y = 1.f, z = 1.000005;
    CUNIT_EXPECT_FLOAT_EQ(x, y);
    CUNIT_ASSERT_FLOAT_EQ(x, y);
    CUNIT_EXPECT_FLOAT_EQ(x, z);
    CUNIT_ASSERT_FLOAT_EQ_THRESHOLD(x, z, 0.0001);

    float w = 2.f;
    CUNIT_EXPECT_FLOAT_EQ_THRESHOLD(x, z, 5);
    CUNIT_EXPECT_FLOAT_EQ(x, w);
    CUNIT_ASSERT_FLOAT_EQ(x, w);
}

CUNIT_TEST(int_leq)
{
    int x = 1, y = 5, z = 1;
    CUNIT_EXPECT_INT_LEQ(x, y);
    CUNIT_ASSERT_INT_LEQ(x, y);

    CUNIT_ASSERT_INT_LEQ(x, z);
    CUNIT_ASSERT_INT_LEQ(z, x);

    CUNIT_ASSERT_INT_LEQ(y, x);
}

CUNIT_TEST(float_leq)
{
    float x = 1.f, y = 5.f, z = 1.f, w = 1.00005;
    CUNIT_EXPECT_FLOAT_LEQ(x, y);
    CUNIT_ASSERT_FLOAT_LEQ(x, y);

    CUNIT_ASSERT_FLOAT_LEQ(x, z);
    CUNIT_ASSERT_FLOAT_LEQ(z, x);

    CUNIT_ASSERT_FLOAT_LEQ(x, w);
    CUNIT_ASSERT_FLOAT_LEQ(w, x);

    CUNIT_EXPECT_FLOAT_LEQ_THRESHOLD(w, x, 0.00001);
    CUNIT_ASSERT_FLOAT_LEQ(y, x);
}

CUNIT_TEST(int_lower)
{
    int x = 1, y = 5, z = 1;

    CUNIT_ASSERT_INT_LOWER(x, y);
    CUNIT_EXPECT_INT_LOWER(x, z);
    CUNIT_ASSERT_INT_LOWER(y, z);
}

CUNIT_TEST(float_lower)
{
    float x = 1.f, y = 5.f, z = 1.f, w = 1.00005;
    CUNIT_ASSERT_FLOAT_LOWER_THRESHOLD(x, w, 0.000001);
    CUNIT_ASSERT_FLOAT_LOWER(x, y);
    CUNIT_ASSERT_FLOAT_LOWER(x, w);
}

CUNIT_TEST(str_eq_neq)
{
    CUNIT_ASSERT_STR_EQ("Hello World", "Hello World");
    CUNIT_ASSERT_STR_NEQ("Hello Worlld", "Breathalyzer");
    CUNIT_ASSERT_STR_NEQ("Mammoth", "Breathalyzer");
    CUNIT_ASSERT_STR_NEQ("Mammoth", "Bimba");
    CUNIT_ASSERT_STR_NEQ("Mammoth", "Bimba");
    CUNIT_EXPECT_STR_NEQ(NULL, "Bimba");
    CUNIT_EXPECT_STR_NEQ(NULL, NULL);
    CUNIT_EXPECT_STR_EQ(NULL, "Bimba");
    CUNIT_EXPECT_STR_EQ(NULL, NULL);
    CUNIT_ASSERT_STR_EQ("Mammoth", "Guacamole");
}

CUNIT_TEST(str_contains)
{
    char* a = "Hello World";
    char* b = "World";
    CUNIT_EXPECT_STR_CONTAINS(NULL, "Bimba");
    CUNIT_EXPECT_STR_CONTAINS(NULL, NULL);
    CUNIT_ASSERT_STR_CONTAINS(a, b);
    CUNIT_ASSERT_STR_CONTAINS(b, a);
}

CUNIT_TEST(ptr_eq)
{
    char* a = malloc(strlen("Hello World"));
    char* b = a;
    char* c = NULL;
    CUNIT_ASSERT_PTR_EQ(a, b);
    CUNIT_ASSERT_PTR_EQ(a, c);
}

CUNIT_TEST(ptr_neq)
{
    char* a = malloc(strlen("Hello World"));
    char* b = malloc(strlen("Hello World"));
    char* c = NULL;
    CUNIT_ASSERT_PTR_NEQ(a, b);
    CUNIT_ASSERT_PTR_EQ(a, c);
}

CUNIT_TEST(ptr_null)
{
    char* a = NULL;
    CUNIT_ASSERT_PTR_NULL(a);
    a = malloc(strlen("Hello World"));
    CUNIT_ASSERT_PTR_NULL(a);
}

CUNIT_TEST(ptr_not_null)
{
    char* a = malloc(strlen("Hello World"));
    char* b = NULL;
    CUNIT_ASSERT_PTR_NOT_NULL(a);
    CUNIT_ASSERT_PTR_NOT_NULL(b);
}

CUNIT_SETUP_ONETIME()
{
    printf("Establish connection to DB....\n");
}
CUNIT_CLEANUP_ONETIME()
{
    printf("Terminate connection to DB....\n");
}
CUNIT_SETUP()
{
    printf("Create DB entries for test....\n");
}
CUNIT_CLEANUP()
{
    printf("Delete DB after test....\n");
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
#if REGISTERATION_AUTOMATIQUE
    cunit_run_registered_tests();
#else
    cunit_run_tests(tests, 8);
#endif

    cunit_free_tests(); /* This is completely optional as this function also runs in the destructor */
}

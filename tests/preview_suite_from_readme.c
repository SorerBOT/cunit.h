#include <stdio.h>
#include "../src/cunit.h"

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
CUNIT_TEST(str_eq)
{
    CUNIT_ASSERT_STR_EQ("Hello World", "Hello World");
    CUNIT_EXPECT_STR_NEQ(NULL, "Bimba");
    CUNIT_EXPECT_STR_NEQ(NULL, NULL);
}

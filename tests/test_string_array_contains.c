#include "../src/cunit.h"

CUNIT_TEST(array_permutations)
{
    char* names[] = 
    {
        "Abraham",
        "Jacob",
        "Isaac"
    };

    char* names_permutated[] = 
    {
        "Isaac",
        "Jacob",
    };

    char* names_different[] = 
    {
        "Isaac",
        "Jacob",
        "Joseph"
    };

    CUNIT_ASSERT_ARRAY_STRINGS_CONTAINS(names, names_permutated, 3, 2);
    CUNIT_ASSERT_ARRAY_STRINGS_CONTAINS(names, names_different, 3, 3);
}

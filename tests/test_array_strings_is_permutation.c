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
        "Abraham"
    };

    char* names_different[] = 
    {
        "Moses",
        "Aaaron",
        "Joseph"
    };

    CUNIT_ASSERT_ARRAY_STRINGS_IS_PERMUTATION(names, names_permutated, 3);
    CUNIT_ASSERT_ARRAY_STRINGS_IS_PERMUTATION(names, names_different, 3);
}

#include "../src/cunit.h"

CUNIT_TEST(array_permutations)
{
    int numbers[] = { 1, 2, 3, 4 };
    int numbers_permutated[] = { 4, 3, 2, 1 };
    int numbers_different[] = { 5, 3, 2, 1 };

    CUNIT_ASSERT_ARRAY_IS_PERMUTATION(numbers, numbers_permutated, sizeof(numbers[0]), sizeof(numbers) / sizeof(numbers[0]));
    CUNIT_ASSERT_ARRAY_IS_PERMUTATION(numbers, numbers_different, sizeof(numbers[0]), sizeof(numbers) / sizeof(numbers[0]));
}

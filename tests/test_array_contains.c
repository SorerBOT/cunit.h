#include "../src/cunit.h"

CUNIT_TEST(array_contains)
{
    int numbers[] = { 1, 2, 3, 4 };
    int numbers_subarray[] = { 2, 1 };
    int numbers_different[] = { 5, 3, 2, 1 };

    size_t len_numbers = sizeof(numbers) / sizeof(numbers[0]);
    size_t len_numbers_subarray = sizeof(numbers_subarray) / sizeof(numbers_subarray[0]);
    size_t len_numbers_different = sizeof(numbers_different) / sizeof(numbers_different[0]);

    CUNIT_ASSERT_ARRAY_CONTAINS(numbers, numbers_subarray, sizeof(numbers[0]), len_numbers, len_numbers_subarray);
    CUNIT_ASSERT_ARRAY_CONTAINS(numbers, numbers_different, sizeof(numbers[0]), len_numbers, len_numbers_different);
}

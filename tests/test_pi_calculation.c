/*
 * Demonstrating how multiple testing files could live at peace. One must observe that they
 * all belong to the same suite, and no form of order should be expected.
 * In this example, I calculate PI using the leibniz series: https://en.wikipedia.org/wiki/Leibniz_formula_for_%CF%80
 */

#include "../lib/cunit.h"

#define NUM_ELEMENTS 1000000
#define PI 3.14159265358979323846

double get_leibniz_formula_element(int k)
{
    int sign = (k % 2 == 0) ? 1 : -1;
    return sign / (2 * k + 1.f);
}

CUNIT_TEST(pi_calculation)
{
    double sum = 0.f;

    for (int k = 0; k < NUM_ELEMENTS; ++k)
    {
        sum += get_leibniz_formula_element(k);
    }

    sum *= 4;

    CUNIT_ASSERT_FLOAT_EQ(sum, PI);
}

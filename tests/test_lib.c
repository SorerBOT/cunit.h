#include "stdio.h"
#include <stddef.h>

#define ASSERT(condition) assert((condition), (#condition))

typedef enum
{
    false,
    true
} boolean;

void assert(boolean condition, char* condition_expression)
{
    static size_t assertion_counter = 1;
    if (condition == true)
    {
        printf("Assertion %lu: PASSED", assertion_counter);
    }
    else
    {
        printf("Assertion %lu, with expression %s: FAILED", assertion_counter, condition_expression);
    }
    ++assertion_counter;
}

void test1()
{
    ASSERT(1+2 == 2);
}

int main()
{
    test1();
}

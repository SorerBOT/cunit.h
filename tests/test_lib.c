#include "stdio.h"
#include <stddef.h>

typedef enum
{
    false,
    true
} boolean;

void assert(boolean condition)
{
    static size_t assertion_counter = 1;
    if (condition == true)
    {
        printf("Assertion %lu: PASSED", assertion_counter);
    }
    else
    {
        printf("Assertion %lu: FAILED", assertion_counter);
    }
    ++assertion_counter;
}

void test1()
{
    assert(1+1 == 2);
}

int main()
{
    test1();
}

#include "stdio.h"
#include <stddef.h>

#define ASSERT(condition) assert((condition), (#condition), __FILE__, __LINE__)

typedef enum
{
    false,
    true
} boolean;

void assert(boolean condition, const char* condition_expression, const char* fileName, int lineNumber)
{
    if (condition == true)
    {
        printf("%s:%d PASSED", fileName, lineNumber);
    }
    else
    {
        printf("%s:%d FAILED, expression %s", fileName, lineNumber, condition_expression);
    }
}

void test1()
{
    ASSERT(1+2 == 2);
}

int main()
{
    test1();
}

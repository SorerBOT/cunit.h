#ifndef CUNIT_H
#define CUNIT_H

#include <stdio.h>

#define ASSERT(condition) assert((condition), (#condition), __FILE__, __LINE__)

typedef void(*cunit_test_func)(void);

void assert(int condition, const char* condition_expression, const char* fileName, int lineNumber)
{
    if (condition)
    {
        printf("%s:%d PASSED\n", fileName, lineNumber);
    }
    else
    {
        printf("%s:%d FAILED. Expected %s\n", fileName, lineNumber, condition_expression);
    }
}



#endif /* CUNIT_H */

#ifndef CUNIT_H
#define CUNIT_H

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdint.h>

#define ERROR_MESSAGE_BUFFER 256
#define CUNIT_DEFAULT_THRESHOLD 0.0001

#define ASSERT(condition) cunit_assert((condition), (#condition), __FILE__, __LINE__, 1)
#define EXPECT(condition) cunit_assert((condition), (#condition), __FILE__, __LINE__, 0)

#define ASSERT_INT_EQ(a,b) cunit_assert_int_eq((a), (b), __FILE__, __LINE__, 1)
#define EXPECT_INT_EQ(a,b) cunit_assert_int_eq((a), (b), __FILE__, __LINE__, 0)

#define ASSERT_FLOAT_EQ(a,b) cunit_assert_float_eq((a), (b), __FILE__, __LINE__, 1, CUNIT_DEFAULT_THRESHOLD)
#define EXPECT_FLOAT_EQ(a,b) cunit_assert_float_eq((a), (b), __FILE__, __LINE__, 0, CUNIT_DEFAULT_THRESHOLD)

#define ASSERT_FLOAT_EQ_THRESHOLD(a,b, threshold) cunit_assert_float_eq((a), (b), __FILE__, __LINE__, 1, (threshold))
#define EXPECT_FLOAT_EQ_THRESHOLD(a,b, threshold) cunit_assert_float_eq((a), (b), __FILE__, __LINE__, 0, (threshold))

#define ASSERT_INT_LEQ(a,b) cunit_assert_int_leq((a), (b), __FILE__, __LINE__, 1)
#define EXPECT_INT_LEQ(a,b) cunit_assert_int_leq((a), (b), __FILE__, __LINE__, 0)

#define ASSERT_FLOAT_LEQ(a,b) cunit_assert_float_leq((a), (b), __FILE__, __LINE__, 1, CUNIT_DEFAULT_THRESHOLD)
#define EXPECT_FLOAT_LEQ(a,b) cunit_assert_float_leq((a), (b), __FILE__, __LINE__, 0, CUNIT_DEFAULT_THRESHOLD)

#define ASSERT_FLOAT_LEQ_THRESHOLD(a,b, threshold) cunit_assert_float_leq((a), (b), __FILE__, __LINE__, 1, (threshold))
#define EXPECT_FLOAT_LEQ_THRESHOLD(a,b, threshold) cunit_assert_float_leq((a), (b), __FILE__, __LINE__, 0, (threshold))

#define ASSERT_INT_LOWER(a,b) cunit_assert_int_lower((a), (b), __FILE__, __LINE__, 1)
#define EXPECT_INT_LOWER(a,b) cunit_assert_int_lower((a), (b), __FILE__, __LINE__, 0)

#define ASSERT_FLOAT_LOWER(a,b) cunit_assert_float_lower((a), (b), __FILE__, __LINE__, 1, CUNIT_DEFAULT_THRESHOLD)
#define EXPECT_FLOAT_LOWER(a,b) cunit_assert_float_lower((a), (b), __FILE__, __LINE__, 0, CUNIT_DEFAULT_THRESHOLD)

#define ASSERT_FLOAT_LOWER_THRESHOLD(a,b, threshold) cunit_assert_float_lower((a), (b), __FILE__, __LINE__, 1, (threshold))
#define EXPECT_FLOAT_LOWER_THRESHOLD(a,b, threshold) cunit_assert_float_lower((a), (b), __FILE__, __LINE__, 0, (threshold))

long double cunit_fabsl(long double x)
{
    if (x >= 0)
    {
        return x;
    }
    else
    {
        return -x;
    }

}

typedef void(*cunit_test_func)(void);
typedef struct
{
    cunit_test_func func;
    char* name;
} cunit_test_t;

void cunit_run_test(const cunit_test_t* test)
{
    pid_t child_process_pid = fork();
    if (child_process_pid == -1)
    {
        perror("fork()");
        exit(EXIT_FAILURE);
    }
    if (child_process_pid == 0)
    {
        test->func();
        _exit(EXIT_SUCCESS);
    }
    else
    {
        int stat_loc = 0;
        waitpid(child_process_pid, &stat_loc, 0);
        if (WIFEXITED(stat_loc))
        {
        }
        else if (WIFSIGNALED(stat_loc))
        {
            int signal = WTERMSIG(stat_loc);
            if (signal == SIGABRT)
            {
                return;
            }

            char* error_message = strsignal(signal);
            if (error_message == NULL)
            {
                printf("Test crashed. Failed to find the crash error.\n");
            }
            else
            {
                printf("Test crashed with the error:\n%s\n", error_message);
            }
        }
    }
}

void cunit_run_tests(const cunit_test_t* tests, size_t tests_count)
{
    for (size_t i = 0; i < tests_count; ++i)
    {
        printf("============================================\n");
        printf("Running test: %s\n", tests[i].name);
        fflush(NULL);
        cunit_run_test(&tests[i]);
    }
    printf("============================================\n");
}

void cunit_assert(int condition, const char* condition_expression,
                    const char* fileName, int lineNumber,
                    int shouldAbort)
{
    if (condition)
    {
        return;
    }

    printf("%s:%d FAILED. Expected %s\n", fileName, lineNumber, condition_expression);

    if (shouldAbort)
    {
        fflush(stdout);
        abort();
    }
}

void cunit_assert_int_eq(intmax_t a, intmax_t b,
                            const char* fileName, int lineNumber,
                            int shouldAbort)
{
    if (a == b)
    {
        return;
    }

    printf("%s:%d FAILED. Expected %jd == %jd\n", fileName, lineNumber, a, b);

    if (shouldAbort)
    {
        fflush(stdout);
        abort();
    }
}

void cunit_assert_float_eq(long double a, long double b,
                            const char* fileName, int lineNumber,
                            int shouldAbort, long double threshold)
{
    if (cunit_fabsl(a - b) <= threshold)
    {
        return;
    }

    printf("%s:%d FAILED. Expected %Lf == %Lf (used threshold: %Lf)\n", fileName, lineNumber, a, b, threshold);

    if (shouldAbort)
    {
        fflush(stdout);
        abort();
    }
}

void cunit_assert_int_leq(intmax_t a, intmax_t b,
                            const char* fileName, int lineNumber,
                            int shouldAbort)
{
    if (a <= b)
    {
        return;
    }
    printf("%s:%d FAILED. Expected %jd <= %jd\n", fileName, lineNumber, a, b);
    if (shouldAbort)
    {
        fflush(stdout);
        abort();
    }
}

void cunit_assert_float_leq(long double a, long double b,
                            const char* fileName, int lineNumber,
                            int shouldAbort, long double threshold)
{
    if (a <= b || cunit_fabsl(a - b) <= threshold)
    {
        return;
    }
    printf("%s:%d FAILED. Expected %Lf <= %Lf (used threshold: %Lf)\n", fileName, lineNumber, a, b, threshold);
    if (shouldAbort)
    {
        fflush(stdout);
        abort();
    }
}

void cunit_assert_int_lower(intmax_t a, intmax_t b,
                            const char* fileName, int lineNumber,
                            int shouldAbort)
{
    if (a < b)
    {
        return;
    }
    printf("%s:%d FAILED. Expected %jd < %jd\n", fileName, lineNumber, a, b);
    if (shouldAbort)
    {
        fflush(stdout);
        abort();
    }
}

void cunit_assert_float_lower(long double a, long double b,
                            const char* fileName, int lineNumber,
                            int shouldAbort, long double threshold)
{
    if (b - a > threshold)
    {
        return;
    }
    printf("%s:%d FAILED. Expected %Lf < %Lf (used threshold: %Lf)\n", fileName, lineNumber, a, b, threshold);
    if (shouldAbort)
    {
        fflush(stdout);
        abort();
    }
}

#endif /* CUNIT_H */

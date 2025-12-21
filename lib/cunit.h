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

#define CUNIT_ASSERT(condition) cunit_assert((condition), (#condition), __FILE__, __LINE__, 1)
#define CUNIT_EXPECT(condition) cunit_assert((condition), (#condition), __FILE__, __LINE__, 0)

#define CUNIT_ASSERT_INT_EQ(a,b) cunit_assert_int_eq((a), (b), __FILE__, __LINE__, 1)
#define CUNIT_EXPECT_INT_EQ(a,b) cunit_assert_int_eq((a), (b), __FILE__, __LINE__, 0)

#define CUNIT_ASSERT_FLOAT_EQ(a,b) cunit_assert_float_eq((a), (b), __FILE__, __LINE__, 1, CUNIT_DEFAULT_THRESHOLD)
#define CUNIT_EXPECT_FLOAT_EQ(a,b) cunit_assert_float_eq((a), (b), __FILE__, __LINE__, 0, CUNIT_DEFAULT_THRESHOLD)

#define CUNIT_ASSERT_FLOAT_EQ_THRESHOLD(a,b, threshold) cunit_assert_float_eq((a), (b), __FILE__, __LINE__, 1, (threshold))
#define CUNIT_EXPECT_FLOAT_EQ_THRESHOLD(a,b, threshold) cunit_assert_float_eq((a), (b), __FILE__, __LINE__, 0, (threshold))

#define CUNIT_ASSERT_INT_LEQ(a,b) cunit_assert_int_leq((a), (b), __FILE__, __LINE__, 1)
#define CUNIT_EXPECT_INT_LEQ(a,b) cunit_assert_int_leq((a), (b), __FILE__, __LINE__, 0)

#define CUNIT_ASSERT_FLOAT_LEQ(a,b) cunit_assert_float_leq((a), (b), __FILE__, __LINE__, 1, CUNIT_DEFAULT_THRESHOLD)
#define CUNIT_EXPECT_FLOAT_LEQ(a,b) cunit_assert_float_leq((a), (b), __FILE__, __LINE__, 0, CUNIT_DEFAULT_THRESHOLD)

#define CUNIT_ASSERT_FLOAT_LEQ_THRESHOLD(a,b, threshold) cunit_assert_float_leq((a), (b), __FILE__, __LINE__, 1, (threshold))
#define CUNIT_EXPECT_FLOAT_LEQ_THRESHOLD(a,b, threshold) cunit_assert_float_leq((a), (b), __FILE__, __LINE__, 0, (threshold))

#define CUNIT_ASSERT_INT_LOWER(a,b) cunit_assert_int_lower((a), (b), __FILE__, __LINE__, 1)
#define CUNIT_EXPECT_INT_LOWER(a,b) cunit_assert_int_lower((a), (b), __FILE__, __LINE__, 0)

#define CUNIT_ASSERT_FLOAT_LOWER(a,b) cunit_assert_float_lower((a), (b), __FILE__, __LINE__, 1, CUNIT_DEFAULT_THRESHOLD)
#define CUNIT_EXPECT_FLOAT_LOWER(a,b) cunit_assert_float_lower((a), (b), __FILE__, __LINE__, 0, CUNIT_DEFAULT_THRESHOLD)

#define CUNIT_ASSERT_FLOAT_LOWER_THRESHOLD(a,b, threshold) cunit_assert_float_lower((a), (b), __FILE__, __LINE__, 1, (threshold))
#define CUNIT_EXPECT_FLOAT_LOWER_THRESHOLD(a,b, threshold) cunit_assert_float_lower((a), (b), __FILE__, __LINE__, 0, (threshold))

#define CUNIT_ASSERT_STR_EQ(a,b) cunit_assert_str_eq((a), (b), __FILE__, __LINE__, 1)
#define CUNIT_EXPECT_STR_EQ(a,b) cunit_assert_str_eq((a), (b), __FILE__, __LINE__, 1)

#define CUNIT_ASSERT_STR_NEQ(a,b) cunit_assert_str_neq((a), (b), __FILE__, __LINE__, 1)
#define CUNIT_EXPECT_STR_NEQ(a,b) cunit_assert_str_neq((a), (b), __FILE__, __LINE__, 1)

#define CUNIT_TEST(func)                                    \
        void _cunit_test_##func(void);                      \
        __attribute__((constructor))                        \
        void _cunit_register_##func()                       \
        {                                                   \
            cunit_register_test(_cunit_test_##func, #func); \
        }                                                   \
        void _cunit_test_##func(void)                       \

#define CUNIT_SETUP()                           \
        void _cunit_setup(void);                \
        __attribute__((constructor))            \
        void _cunit_register_setup()            \
        {                                       \
            cunit_register_setup(_cunit_setup); \
        }                                       \
        void _cunit_setup(void)

#define CUNIT_CLEANUP()                             \
        void _cunit_cleanup(void);                  \
        __attribute__((constructor))                \
        void _cunit_register_cleanup()              \
        {                                           \
            cunit_register_cleanup(_cunit_cleanup); \
        }                                           \
        void _cunit_cleanup(void)

#define CUNIT_SETUP_ONETIME()                                   \
        void _cunit_setup_onetime(void);                        \
        __attribute__((constructor))                            \
        void _cunit_register_setup_onetime()                    \
        {                                                       \
            cunit_register_setup_onetime(_cunit_setup_onetime); \
        }                                                       \
        void _cunit_setup_onetime(void)

#define CUNIT_CLEANUP_ONETIME()                     \
        void _cunit_cleanup_onetime(void);                  \
        __attribute__((constructor))                \
        void _cunit_register_cleanup_onetime()              \
        {                                           \
            cunit_register_cleanup_onetime(_cunit_cleanup_onetime); \
        }                                           \
        void _cunit_cleanup_onetime(void)
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

typedef void(*cunit_func_t)(void);

typedef struct _cunit_linked_list_t
{
    struct _cunit_linked_list_t* next_node;
} cunit_linked_list_t;
 /*
  * Using intrusive lists, and having the linked_list property
  * as the first in the struct so that I can cast between
  * them seemlessly.
  */
typedef struct
{
    cunit_linked_list_t list_data;
    cunit_func_t func;
    char* name;
} cunit_test_t;

cunit_test_t* tests = NULL;
cunit_test_t* last_test = NULL;
cunit_func_t setup_func = NULL;
cunit_func_t cleanup_func = NULL;
cunit_func_t setup_onetime_func = NULL;
cunit_func_t cleanup_onetime_func = NULL;

void cunit_register_test(cunit_func_t func, char* name)
{
    cunit_test_t* test = malloc(sizeof(cunit_test_t));

    if (test == NULL)
    {
        fprintf(stderr, "malloc()");
        exit(EXIT_FAILURE);
    }

    *test = (cunit_test_t)
    {
        .func = func,
        .name = name,
        .list_data = (cunit_linked_list_t)
        {
            .next_node = NULL
        }
    };

    if (tests == NULL)
    {
        tests = test;
        last_test = test;
        return;
    }

    last_test->list_data.next_node = &test->list_data;
    last_test = test;
}

void cunit_register_setup(cunit_func_t func)
{
    if (setup_func != NULL)
    {
        fprintf(stderr, "setup function redefinition is not allowed.\n");
        exit(EXIT_FAILURE);
    }
    setup_func = func;
}

void cunit_register_cleanup(cunit_func_t func)
{
    if (cleanup_func != NULL)
    {
        fprintf(stderr, "cleanup function redefinition is not allowed.\n");
        exit(EXIT_FAILURE);
    }
    cleanup_func = func;
}

void cunit_register_setup_onetime(cunit_func_t func)
{
    if (setup_onetime_func != NULL)
    {
        fprintf(stderr, "setup_onetime function redefinition is not allowed.\n");
        exit(EXIT_FAILURE);
    }
    setup_onetime_func = func;
}

void cunit_register_cleanup_onetime(cunit_func_t func)
{
    if (cleanup_onetime_func != NULL)
    {
        fprintf(stderr, "cleanup_onetime function redefinition is not allowed.\n");
        exit(EXIT_FAILURE);
    }
    cleanup_onetime_func = func;
}

__attribute__((destructor))
void cunit_free_tests()
{
    cunit_test_t* test_previous = tests;
    cunit_test_t* test_current = tests;

    while (test_current != NULL)
    {
        if (test_current->list_data.next_node == NULL)
        {
            test_current = NULL;
        }
        else
        {
            test_current = (cunit_test_t*) test_current->list_data.next_node;
        }
        free(test_previous);
        test_previous = test_current;
    }

    tests = NULL;
}

void cunit_run_test(const cunit_test_t* test)
{
    /*
     * SETUP
     */
    if (setup_func != NULL)
    {
        printf("**** Running SetUp function....\n");
        fflush(NULL);
        setup_func();
        printf("**** SetUp finished successfully....\n");
        fflush(NULL);
    }

    /*
     * Running Test
     */
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
            }
            else
            {
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
        /*
         * Clean Up
         */
        if (cleanup_func != NULL)
        {
            printf("**** Running CleanUp function....\n");
            fflush(NULL);
            cleanup_func();
            printf("**** CleanUp finished successfully....\n");
        }
    }
}

void cunit_run_tests(const cunit_test_t* tests, size_t tests_count)
{
    /*
     * SetUpOneTime
     */
    printf("**** Running SetUpOneTime function....\n");
    fflush(NULL);
    setup_onetime_func();
    printf("**** SetUpOneTime function finished successfully....\n");

    for (size_t i = 0; i < tests_count; ++i)
    {
        printf("============================================\n");
        printf("Running test: %s\n", tests[i].name);
        fflush(NULL);
        cunit_run_test(&tests[i]);
    }
    printf("============================================\n");

    /*
     * CleanUpOneTime
     */
    printf("**** Running CleanUpOneTime function....\n");
    fflush(NULL);
    cleanup_onetime_func();
    printf("**** CleanUpOneTime function finished successfully....\n");
}

void cunit_run_registered_tests()
{
    /*
     * SetUpOneTime
     */
    printf("**** Running SetUpOneTime function....\n");
    setup_onetime_func();
    printf("**** SetUpOneTime function finished successfully....\n");

    cunit_test_t* current_test = tests;
    while (current_test != NULL)
    {
        printf("============================================\n");
        printf("Running test: %s\n", current_test->name);
        fflush(NULL);
        cunit_run_test(current_test);
        if (current_test->list_data.next_node == NULL)
        {
            current_test = NULL;
        }
        else
        {
            current_test = (cunit_test_t*) current_test->list_data.next_node;
        }
    }
    printf("============================================\n");

    /*
     * CleanUpOneTime
     */
    printf("**** Running CleanUpOneTime function....\n");
    cleanup_onetime_func();
    printf("**** CleanUpOneTime function finished successfully....\n");
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

void cunit_assert_str_eq(const char* a, const char* b,
                        char* fileName, int lineNumber,
                        int shouldAbort)
{
    if (strcmp(a, b) == 0)
    {
        return;
    }
    printf("%s:%d FAILED. Expected %s == %s\n", fileName, lineNumber, a, b);
    if (shouldAbort)
    {
        fflush(stdout);
        abort();
    }
}

void cunit_assert_str_neq(const char* a, const char* b,
                        char* fileName, int lineNumber,
                        int shouldAbort)
{
    if (strcmp(a, b) != 0)
    {
        return;
    }
    printf("%s:%d FAILED. Expected %s != %s\n", fileName, lineNumber, a, b);
    if (shouldAbort)
    {
        fflush(stdout);
        abort();
    }
}
#endif /* CUNIT_H */

/*
 * Copyright (c) 2025 Alon Filler
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef CUNIT_H
#define CUNIT_H

#include <stdint.h> // intmax_t
#include <stddef.h> // size_t

#define ERROR_MESSAGE_BUFFER 256
#ifdef CUNIT_USER_THRESHOLD
#define CUNIT_DEFAULT_THRESHOLD CUNIT_USER_THRESHOLD
#else
#define CUNIT_DEFAULT_THRESHOLD 0.0001
#endif

#define CUNIT_ASSERT_TRUE(condition) cunit__internal_assert_true((condition), (#condition), __FILE__, __LINE__, 1)
#define CUNIT_EXPECT_TRUE(condition) cunit__internal_assert_true((condition), (#condition), __FILE__, __LINE__, 0)

#define CUNIT_ASSERT_FALSE(condition) cunit__internal_assert_false((condition), (#condition), __FILE__, __LINE__, 1)
#define CUNIT_EXPECT_FALSE(condition) cunit__internal_assert_false((condition), (#condition), __FILE__, __LINE__, 0)

#define CUNIT_ASSERT_INT_EQ(a,b) cunit__internal_assert_int_eq((a), (b), __FILE__, __LINE__, 1)
#define CUNIT_EXPECT_INT_EQ(a,b) cunit__internal_assert_int_eq((a), (b), __FILE__, __LINE__, 0)

#define CUNIT_ASSERT_INT_NEQ(a,b) cunit__internal_assert_int_neq((a), (b), __FILE__, __LINE__, 1)
#define CUNIT_EXPECT_INT_NEQ(a,b) cunit__internal_assert_int_neq((a), (b), __FILE__, __LINE__, 0)

#define CUNIT_ASSERT_FLOAT_EQ(a,b) cunit__internal_assert_float_eq((a), (b), __FILE__, __LINE__, 1, CUNIT_DEFAULT_THRESHOLD)
#define CUNIT_EXPECT_FLOAT_EQ(a,b) cunit__internal_assert_float_eq((a), (b), __FILE__, __LINE__, 0, CUNIT_DEFAULT_THRESHOLD)

#define CUNIT_ASSERT_FLOAT_NEQ(a,b) cunit__internal_assert_float_neq((a), (b), __FILE__, __LINE__, 1, CUNIT_DEFAULT_THRESHOLD)
#define CUNIT_EXPECT_FLOAT_NEQ(a,b) cunit__internal_assert_float_neq((a), (b), __FILE__, __LINE__, 0, CUNIT_DEFAULT_THRESHOLD)

#define CUNIT_ASSERT_FLOAT_EQ_THRESHOLD(a,b, threshold) cunit__internal_assert_float_eq((a), (b), __FILE__, __LINE__, 1, (threshold))
#define CUNIT_EXPECT_FLOAT_EQ_THRESHOLD(a,b, threshold) cunit__internal_assert_float_eq((a), (b), __FILE__, __LINE__, 0, (threshold))

#define CUNIT_ASSERT_INT_LEQ(a,b) cunit__internal_assert_int_leq((a), (b), __FILE__, __LINE__, 1)
#define CUNIT_EXPECT_INT_LEQ(a,b) cunit__internal_assert_int_leq((a), (b), __FILE__, __LINE__, 0)

#define CUNIT_ASSERT_FLOAT_LEQ(a,b) cunit__internal_assert_float_leq((a), (b), __FILE__, __LINE__, 1, CUNIT_DEFAULT_THRESHOLD)
#define CUNIT_EXPECT_FLOAT_LEQ(a,b) cunit__internal_assert_float_leq((a), (b), __FILE__, __LINE__, 0, CUNIT_DEFAULT_THRESHOLD)

#define CUNIT_ASSERT_FLOAT_LEQ_THRESHOLD(a,b, threshold) cunit__internal_assert_float_leq((a), (b), __FILE__, __LINE__, 1, (threshold))
#define CUNIT_EXPECT_FLOAT_LEQ_THRESHOLD(a,b, threshold) cunit__internal_assert_float_leq((a), (b), __FILE__, __LINE__, 0, (threshold))

#define CUNIT_ASSERT_INT_LOWER(a,b) cunit__internal_assert_int_lower((a), (b), __FILE__, __LINE__, 1)
#define CUNIT_EXPECT_INT_LOWER(a,b) cunit__internal_assert_int_lower((a), (b), __FILE__, __LINE__, 0)

#define CUNIT_ASSERT_FLOAT_LOWER(a,b) cunit__internal_assert_float_lower((a), (b), __FILE__, __LINE__, 1, CUNIT_DEFAULT_THRESHOLD)
#define CUNIT_EXPECT_FLOAT_LOWER(a,b) cunit__internal_assert_float_lower((a), (b), __FILE__, __LINE__, 0, CUNIT_DEFAULT_THRESHOLD)

#define CUNIT_ASSERT_FLOAT_LOWER_THRESHOLD(a,b, threshold) cunit__internal_assert_float_lower((a), (b), __FILE__, __LINE__, 1, (threshold))
#define CUNIT_EXPECT_FLOAT_LOWER_THRESHOLD(a,b, threshold) cunit__internal_assert_float_lower((a), (b), __FILE__, __LINE__, 0, (threshold))

#define CUNIT_ASSERT_STR_EQ(a,b) cunit__internal_assert_str_eq((a), (b), __FILE__, __LINE__, 1)
#define CUNIT_EXPECT_STR_EQ(a,b) cunit__internal_assert_str_eq((a), (b), __FILE__, __LINE__, 0)

#define CUNIT_ASSERT_STR_NEQ(a,b) cunit__internal_assert_str_neq((a), (b), __FILE__, __LINE__, 1)
#define CUNIT_EXPECT_STR_NEQ(a,b) cunit__internal_assert_str_neq((a), (b), __FILE__, __LINE__, 0)

#define CUNIT_ASSERT_MEM_EQ(a,b, size) cunit__internal_assert_mem_eq((a), (b), (size), __FILE__, __LINE__, 1)
#define CUNIT_EXPECT_MEM_EQ(a,b, size) cunit__internal_assert_mem_eq((a), (b), (size), __FILE__, __LINE__, 0)

#define CUNIT_ASSERT_MEM_NEQ(a,b, size) cunit__internal_assert_mem_neq((a), (b), (size), __FILE__, __LINE__, 1)
#define CUNIT_EXPECT_MEM_NEQ(a,b, size) cunit__internal_assert_mem_neq((a), (b), (size), __FILE__, __LINE__, 0)
/*
 * assert that a contains b
 */
#define CUNIT_ASSERT_STR_CONTAINS(a,b) cunit__internal_assert_str_contains((a), (b), __FILE__, __LINE__, 1)
#define CUNIT_EXPECT_STR_CONTAINS(a,b) cunit__internal_assert_str_contains((a), (b), __FILE__, __LINE__, 0)

#define CUNIT_ASSERT_PTR_EQ(a,b) cunit__internal_assert_ptr_eq((a), (b), __FILE__, __LINE__, 1)
#define CUNIT_EXPECT_PTR_EQ(a,b) cunit__internal_assert_ptr_eq((a), (b), __FILE__, __LINE__, 0)

#define CUNIT_ASSERT_PTR_NEQ(a,b) cunit__internal_assert_ptr_neq((a), (b), __FILE__, __LINE__, 1)
#define CUNIT_EXPECT_PTR_NEQ(a,b) cunit__internal_assert_ptr_neq((a), (b), __FILE__, __LINE__, 0)

#define CUNIT_ASSERT_PTR_NULL(a) cunit__internal_assert_ptr_null((a), __FILE__, __LINE__, 1)
#define CUNIT_EXPECT_PTR_NULL(a) cunit__internal_assert_ptr_null((a), __FILE__, __LINE__, 0)

#define CUNIT_ASSERT_PTR_NOT_NULL(a) cunit__internal_assert_ptr_not_null((a), __FILE__, __LINE__, 1)
#define CUNIT_EXPECT_PTR_NOT_NULL(a) cunit__internal_assert_ptr_not_null((a), __FILE__, __LINE__, 0)

#define CUNIT_TEST(func)                                    \
        void _cunit_test_##func(void);                      \
        __attribute__((constructor))                        \
        void _cunit_register_##func()                       \
        {                                                   \
            cunit__internal_register_test(_cunit_test_##func, #func); \
        }                                                   \
        void _cunit_test_##func(void)                       \

#define CUNIT_SETUP()                           \
        void _cunit_setup(void);                \
        __attribute__((constructor))            \
        void _cunit_register_setup()            \
        {                                       \
            cunit__internal_register_setup(_cunit_setup); \
        }                                       \
        void _cunit_setup(void)

#define CUNIT_CLEANUP()                             \
        void _cunit_cleanup(void);                  \
        __attribute__((constructor))                \
        void _cunit_register_cleanup()              \
        {                                           \
            cunit__internal_register_cleanup(_cunit_cleanup); \
        }                                           \
        void _cunit_cleanup(void)

#define CUNIT_SETUP_ONETIME()                                   \
        void _cunit_setup_onetime(void);                        \
        __attribute__((constructor))                            \
        void _cunit_register_setup_onetime()                    \
        {                                                       \
            cunit__internal_register_setup_onetime(_cunit_setup_onetime); \
        }                                                       \
        void _cunit_setup_onetime(void)

#define CUNIT_CLEANUP_ONETIME()                     \
        void _cunit_cleanup_onetime(void);                  \
        __attribute__((constructor))                \
        void _cunit_register_cleanup_onetime()              \
        {                                           \
            cunit__internal_register_cleanup_onetime(_cunit_cleanup_onetime); \
        }                                           \
        void _cunit_cleanup_onetime(void)

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

void cunit_run_tests(const cunit_test_t* tests, size_t tests_count);
void cunit_run_registered_tests();
void cunit_free_tests();

void cunit__internal_register_test(cunit_func_t func, char* name);
void cunit__internal_register_setup(cunit_func_t func);
void cunit__internal_register_cleanup(cunit_func_t func);
void cunit__internal_register_setup_onetime(cunit_func_t func);
void cunit__internal_register_cleanup_onetime(cunit_func_t func);

void cunit__internal_assert_true(int condition, const char* condition_expression, const char* fileName, int lineNumber, int shouldAbort);
void cunit__internal_assert_false(int condition, const char* condition_expression, const char* fileName, int lineNumber, int shouldAbort);
void cunit__internal_assert_int_eq(intmax_t a, intmax_t b, const char* fileName, int lineNumber, int shouldAbort);
void cunit__internal_assert_int_neq(intmax_t a, intmax_t b, const char* fileName, int lineNumber, int shouldAbort);
void cunit__internal_assert_float_eq(long double a, long double b, const char* fileName, int lineNumber, int shouldAbort, long double threshold);
void cunit__internal_assert_float_neq(long double a, long double b, const char* fileName, int lineNumber, int shouldAbort, long double threshold);
void cunit__internal_assert_int_leq(intmax_t a, intmax_t b, const char* fileName, int lineNumber, int shouldAbort);
void cunit__internal_assert_float_leq(long double a, long double b, const char* fileName, int lineNumber, int shouldAbort, long double threshold);
void cunit__internal_assert_int_lower(intmax_t a, intmax_t b, const char* fileName, int lineNumber, int shouldAbort);
void cunit__internal_assert_float_lower(long double a, long double b, const char* fileName, int lineNumber, int shouldAbort, long double threshold);
void cunit__internal_assert_str_eq(const char* a, const char* b, char* fileName, int lineNumber, int shouldAbort);
void cunit__internal_assert_str_neq(const char* a, const char* b, char* fileName, int lineNumber, int shouldAbort);
void cunit__internal_assert_str_contains(const char* a, const char* b, char* fileName, int lineNumber, int shouldAbort);
void cunit__internal_assert_ptr_eq(const void* a, const void* b, const char* fileName, int lineNumber, int shouldAbort);
void cunit__internal_assert_ptr_neq(const void* a, const void* b, const char* fileName, int lineNumber, int shouldAbort);
void cunit__internal_assert_ptr_null(const void* a, const char* fileName, int lineNumber, int shouldAbort);
void cunit__internal_assert_ptr_not_null(const void* a, const char* fileName, int lineNumber, int shouldAbort);
void cunit__internal_assert_mem_eq(const void* a, const void* b, size_t length, const char* fileName, int lineNumber, int shouldAbort);
void cunit__internal_assert_mem_neq(const void* a, const void* b, size_t length, const char* fileName, int lineNumber, int shouldAbort);

#endif /* CUNIT_H */

#ifdef CUNIT_IMPLEMENTATION
#include <stdlib.h> // malloc, free
#include <stdio.h> // printf
#include <unistd.h> // fork
#include <sys/wait.h> // wait
#include <signal.h> // signal numbers, macros
#include <string.h> // strsignal

#include <stdlib.h> // malloc, free
#include <stdio.h> // printf
#include <unistd.h> // fork
#include <sys/wait.h> // wait
#include <signal.h> // signal numbers, macros
#include <string.h> // strsignal

static long double cunit__internal_fabsl(long double x);
static void cunit__internal_run_test(const cunit_test_t* test);

cunit_test_t* tests = NULL;
cunit_test_t* last_test = NULL;
size_t tests_count = 0;
size_t tests_count_passed = 0;

cunit_func_t setup_func = NULL;
cunit_func_t cleanup_func = NULL;
cunit_func_t setup_onetime_func = NULL;
cunit_func_t cleanup_onetime_func = NULL;

#ifndef CUNIT_USE_CUSTOM_MAIN
int main()
{
    cunit_run_registered_tests();
    cunit_free_tests(); /* This is completely optional as this function also runs in the destructor */
}
#endif


static long double cunit__internal_fabsl(long double x)
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

void cunit__internal_register_test(cunit_func_t func, char* name)
{
    cunit_test_t* test = malloc(sizeof(cunit_test_t));

    if (test == NULL)
    {
        fprintf(stderr, "malloc()");
        exit(EXIT_FAILURE);
    }
    ++tests_count;
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

void cunit__internal_register_setup(cunit_func_t func)
{
    if (setup_func != NULL)
    {
        fprintf(stderr, "setup function redefinition is not allowed.\n");
        exit(EXIT_FAILURE);
    }
    setup_func = func;
}

void cunit__internal_register_cleanup(cunit_func_t func)
{
    if (cleanup_func != NULL)
    {
        fprintf(stderr, "cleanup function redefinition is not allowed.\n");
        exit(EXIT_FAILURE);
    }
    cleanup_func = func;
}

void cunit__internal_register_setup_onetime(cunit_func_t func)
{
    if (setup_onetime_func != NULL)
    {
        fprintf(stderr, "setup_onetime function redefinition is not allowed.\n");
        exit(EXIT_FAILURE);
    }
    setup_onetime_func = func;
}

void cunit__internal_register_cleanup_onetime(cunit_func_t func)
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

static void cunit__internal_run_test(const cunit_test_t* test)
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
            ++tests_count_passed;
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
    tests_count_passed = 0;
    /*
     * SetUpOneTime
     */
    if (setup_onetime_func != NULL)
    {
        printf("**** Running SetUpOneTime function....\n");
        fflush(NULL);
        setup_onetime_func();
        printf("**** SetUpOneTime function finished successfully....\n");
    }

    for (size_t i = 0; i < tests_count; ++i)
    {
        printf("============================================\n");
        printf("Running test: %s\n", tests[i].name);
        fflush(NULL);
        cunit__internal_run_test(&tests[i]);
    }
    printf("============================================\n");

    /*
     * CleanUpOneTime
     */
    if (cleanup_onetime_func != NULL)
    {
        printf("**** Running CleanUpOneTime function....\n");
        fflush(NULL);
        cleanup_onetime_func();
        printf("**** CleanUpOneTime function finished successfully....\n");
    }

    /*
     * Printing Statistical Data
     */
    if (tests_count_passed == tests_count)
    {
        printf("All tests PASSED!\n");
        return;
    }
    printf("\n%lu tests failed out of %lu tests in total\n", tests_count - tests_count_passed, tests_count);
}

void cunit_run_registered_tests()
{
    tests_count_passed = 0;
    /*
     * SetUpOneTime
     */
    if (setup_onetime_func != NULL)
    {
        printf("**** Running SetUpOneTime function....\n");
        fflush(NULL);
        setup_onetime_func();
        printf("**** SetUpOneTime function finished successfully....\n");
    }

    cunit_test_t* current_test = tests;
    while (current_test != NULL)
    {
        printf("============================================\n");
        printf("Running test: %s\n", current_test->name);
        fflush(NULL);
        cunit__internal_run_test(current_test);
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
    if (cleanup_onetime_func != NULL)
    {

        printf("**** Running CleanUpOneTime function....\n");
        fflush(NULL);
        cleanup_onetime_func();
        printf("**** CleanUpOneTime function finished successfully....\n");
    }

    /*
     * Printing Statistical Data
     */
    if (tests_count_passed == tests_count)
    {
        printf("All tests PASSED!\n");
        return;
    }
    printf("\n%lu tests failed out of %lu tests in total\n", tests_count - tests_count_passed, tests_count);
}

void cunit__internal_assert_true(int condition, const char* condition_expression,
                    const char* fileName, int lineNumber,
                    int shouldAbort)
{
    if (condition)
    {
        return;
    }

    printf("%s:%d FAILED. Expected %s to be TRUE\n", fileName, lineNumber, condition_expression);

    if (shouldAbort)
    {
        fflush(stdout);
        abort();
    }
}
void cunit__internal_assert_false(int condition, const char* condition_expression,
                    const char* fileName, int lineNumber,
                    int shouldAbort)
{
    if (!condition)
    {
        return;
    }

    printf("%s:%d FAILED. Expected %s to be FALSE\n", fileName, lineNumber, condition_expression);

    if (shouldAbort)
    {
        fflush(stdout);
        abort();
    }
}

void cunit__internal_assert_int_eq(intmax_t a, intmax_t b,
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

void cunit__internal_assert_int_neq(intmax_t a, intmax_t b,
                            const char* fileName, int lineNumber,
                            int shouldAbort)
{
    if (a != b)
    {
        return;
    }

    printf("%s:%d FAILED. Expected %jd != %jd\n", fileName, lineNumber, a, b);

    if (shouldAbort)
    {
        fflush(stdout);
        abort();
    }
}

void cunit__internal_assert_float_eq(long double a, long double b,
                            const char* fileName, int lineNumber,
                            int shouldAbort, long double threshold)
{
    if (cunit__internal_fabsl(a - b) <= threshold)
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

void cunit__internal_assert_float_neq(long double a, long double b,
                            const char* fileName, int lineNumber,
                            int shouldAbort, long double threshold)
{
    // to be written tomorrow
    if (cunit__internal_fabsl(a - b) > threshold)
    {
        return;
    }

    printf("%s:%d FAILED. Expected %Lf != %Lf (used threshold: %Lf)\n", fileName, lineNumber, a, b, threshold);

    if (shouldAbort)
    {
        fflush(stdout);
        abort();
    }
}

void cunit__internal_assert_int_leq(intmax_t a, intmax_t b,
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

void cunit__internal_assert_float_leq(long double a, long double b,
                            const char* fileName, int lineNumber,
                            int shouldAbort, long double threshold)
{
    if (a <= b || cunit__internal_fabsl(a - b) <= threshold)
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

void cunit__internal_assert_int_lower(intmax_t a, intmax_t b,
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

void cunit__internal_assert_float_lower(long double a, long double b,
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

void cunit__internal_assert_str_eq(const char* a, const char* b,
                        char* fileName, int lineNumber,
                        int shouldAbort)
{
    const char* c = (a == NULL) ? "NULL" : a;
    const char* d = (b == NULL) ? "NULL" : b;

    if ( !(a == NULL || b == NULL) )
    {
        if (strcmp(a, b) == 0)
        {
            return;
        }
    }
    printf("%s:%d FAILED. Expected %s == %s\n", fileName, lineNumber, c, d);
    if (shouldAbort)
    {
        fflush(stdout);
        abort();
    }
}

void cunit__internal_assert_str_neq(const char* a, const char* b,
                        char* fileName, int lineNumber,
                        int shouldAbort)
{
    const char* c = (a == NULL) ? "NULL" : a;
    const char* d = (b == NULL) ? "NULL" : b;

    if ( !(a == NULL || b == NULL) )
    {
        // Cannot compare them!
        if (strcmp(a, b) != 0)
        {
            return;
        }
    }
    printf("%s:%d FAILED. Expected %s != %s\n", fileName, lineNumber, c, d);
    if (shouldAbort)
    {
        fflush(stdout);
        abort();
    }
}

void cunit__internal_assert_str_contains(const char* a, const char* b,
                        char* fileName, int lineNumber,
                        int shouldAbort)
{
    const char* c = (a == NULL) ? "NULL" : a;
    const char* d = (b == NULL) ? "NULL" : b;
    if ( !(a == NULL || b == NULL) )
    {
        if (strstr(a, b) != NULL)
        {
            return;
        }
    }
    printf("%s:%d FAILED. Expected %s to contain %s\n", fileName, lineNumber, c, d);
    if (shouldAbort)
    {
        fflush(stdout);
        abort();
    }
}

void cunit__internal_assert_ptr_eq(const void* a, const void* b,
                            const char* fileName, int lineNumber,
                            int shouldAbort)
{
    if ( !(a == NULL || b == NULL) )
    {
        if (a == b)
        {
            return;
        }
        else
        {
            printf("%s:%d FAILED. Expected %p == %p\n", fileName, lineNumber, a, b);
        }
    }
    else
    {
        printf("%s:%d FAILED. Expected equal addresses, but got NULL in at least one of them\n", fileName, lineNumber);
    }

    if (shouldAbort)
    {
        fflush(stdout);
        abort();
    }
}

void cunit__internal_assert_ptr_neq(const void* a, const void* b,
                            const char* fileName, int lineNumber,
                            int shouldAbort)
{
    if ( !(a == NULL || b == NULL) )
    {
        if (a != b)
        {
            return;
        }
        else
        {
            printf("%s:%d FAILED. Expected %p != %p\n", fileName, lineNumber, a, b);
        }
    }
    else
    {
        printf("%s:%d FAILED. Expected equal addresses, but got NULL in at least one of them\n", fileName, lineNumber);
    }

    if (shouldAbort)
    {
        fflush(stdout);
        abort();
    }
}

void cunit__internal_assert_ptr_null(const void* a, const char* fileName,
                            int lineNumber, int shouldAbort)
{
    if (a == NULL)
    {
        return;
    }

    printf("%s:%d FAILED. Expected pointer to be NULL, but got %p\n", fileName, lineNumber, a);

    if (shouldAbort)
    {
        fflush(stdout);
        abort();
    }
}

void cunit__internal_assert_ptr_not_null(const void* a, const char* fileName,
                            int lineNumber, int shouldAbort)
{
    if (a != NULL)
    {
        return;
    }

    printf("%s:%d FAILED. Expected valid pointer, but got NULL\n", fileName, lineNumber);

    if (shouldAbort)
    {
        fflush(stdout);
        abort();
    }
}

void cunit__internal_assert_mem_eq(const void* a, const void* b,
                            size_t length, const char* fileName,
                            int lineNumber, int shouldAbort)
{
    if (a == NULL || b == NULL)
    {
        printf("%s:%d FAILED. Expected valid pointers, but got NULL in at least one of them\n", fileName, lineNumber);
    }
    else
    {
        if ( memcmp(a, b, length) == 0 )
        {
            return;
        }
        printf("%s:%d FAILED. Expected contents of pointers %p and %p to be bytewise-identical\n", fileName, lineNumber, a, b);
    }

    if (shouldAbort)
    {
        fflush(stdout);
        abort();
    }
}

void cunit__internal_assert_mem_neq(const void* a, const void* b,
                            size_t length, const char* fileName,
                            int lineNumber, int shouldAbort)
{
    if (a == NULL || b == NULL)
    {
        printf("%s:%d FAILED. Expected valid pointers, but got NULL in at least one of them\n", fileName, lineNumber);
    }
    else
    {
        if ( memcmp(a, b, length) != 0 )
        {
            return;
        }
        printf("%s:%d FAILED. Expected contents of pointers %p and %p to be bytewise-different\n", fileName, lineNumber, a, b);
    }

    if (shouldAbort)
    {
        fflush(stdout);
        abort();
    }
}

#endif /* CUNIT_IMPLEMENTATION */

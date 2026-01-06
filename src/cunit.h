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

#ifdef CUNIT_USER_TIMEOUT_MS
#define CUNIT_TIMEOUT_MS CUNIT_USER_TIMEOUT_MS
#else
#define CUNIT_TIMEOUT_MS 10000
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

#define CUNIT_ASSERT_ARRAY_IS_PERMUTATION(a,b,chunk_length,length) cunit__internal_assert_array_is_permutation((a), (b), (chunk_length), (length), __FILE__, __LINE__, 1)
#define CUNIT_EXPECT_ARRAY_IS_PERMUTATION(a,b,chunk_length,length) cunit__internal_assert_array_is_permutation((a), (b), (chunk_length), (length), __FILE__, __LINE__, 0)

#define CUNIT_ASSERT_ARRAY_CONTAINS(a,b,chunk_length,length_a,length_b) cunit__internal_assert_array_contains((a), (b), (chunk_length), (length_a), (length_b), __FILE__, __LINE__, 1)
#define CUNIT_EXPECT_ARRAY_CONTAINS(a,b,chunk_length,length_a,length_b) cunit__internal_assert_array_contains((a), (b), (chunk_length), (length_a), (length_b), __FILE__, __LINE__, 0)
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
        static void _cunit_test_##func(void);               \
        __attribute__((constructor))                        \
        static void _cunit_register_##func(void)            \
        {                                                   \
            cunit__internal_register_func(_cunit_test_##func, CUNIT_FT_TEST, __FILE__, #func); \
        }                                                   \
        static void _cunit_test_##func(void)                \

#define CUNIT_SETUP()                           \
        static void _cunit_setup(void);                \
        __attribute__((constructor))            \
        static void _cunit_register_setup(void)        \
        {                                       \
            cunit__internal_register_func(_cunit_setup, CUNIT_FT_SETUP, __FILE__, NULL); \
        }                                       \
        static void _cunit_setup(void)

#define CUNIT_CLEANUP()                             \
        static void _cunit_cleanup(void);                  \
        __attribute__((constructor))                \
        static void _cunit_register_cleanup(void)          \
        {                                           \
            cunit__internal_register_func(_cunit_cleanup, CUNIT_FT_CLEANUP, __FILE__, NULL); \
        }                                           \
        static void _cunit_cleanup(void)

#define CUNIT_SETUP_ONETIME()                                   \
        static void _cunit_setup_onetime(void);                        \
        __attribute__((constructor))                            \
        static void _cunit_register_setup_onetime(void)                \
        {                                                       \
            cunit__internal_register_func(_cunit_setup_onetime, CUNIT_FT_SETUP_ONETIME, __FILE__, NULL); \
        }                                                       \
        static void _cunit_setup_onetime(void)

#define CUNIT_CLEANUP_ONETIME()                     \
        static void _cunit_cleanup_onetime(void);          \
        __attribute__((constructor))                \
        static void _cunit_register_cleanup_onetime(void)  \
        {                                           \
            cunit__internal_register_func(_cunit_cleanup_onetime, CUNIT_FT_CLEANUP_ONETIME, __FILE__, NULL); \
        }                                           \
        static void _cunit_cleanup_onetime(void)

typedef enum
{
    CUNIT_FT_TEST,
    CUNIT_FT_SETUP,
    CUNIT_FT_CLEANUP,
    CUNIT_FT_SETUP_ONETIME,
    CUNIT_FT_CLEANUP_ONETIME
} cunit_func_type_t;

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
    const char* name;
} cunit_test_t;

typedef struct
{
    cunit_linked_list_t list_data;
    cunit_test_t* test_first;
    cunit_test_t* test_last;
    const char* name;
    cunit_func_t setup_func;
    cunit_func_t cleanup_func;
    cunit_func_t setup_onetime_func;
    cunit_func_t cleanup_onetime_func;
} cunit_suite_t;

void cunit_run_tests(const cunit_test_t* tests, size_t tests_count);
void cunit_run_registered_tests(void);
void cunit_free_tests(void);

void cunit__internal_debug_print_tests_list(void);

void cunit__internal_register_func(cunit_func_t func, cunit_func_type_t func_type, const char* suiteName, const char* testName);
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
void cunit__internal_assert_array_is_permutation(const void* a, const void* b, size_t chunk_size, size_t length, const char* fileName, int lineNumber, int shouldAbort);
void cunit__internal_assert_array_contains(const void* a, const void* b, size_t chunk_size, size_t length_a, size_t length_b, const char* fileName, int lineNumber, int shouldAbort);

#endif /* CUNIT_H */

#ifdef CUNIT_IMPLEMENTATION

#include <stdlib.h> // malloc, free
#include <stdio.h> // printf
#include <unistd.h> // fork
#include <sys/wait.h> // wait
#include <signal.h> // signal numbers, macros
#include <string.h> // strsignal
#include <poll.h> // poll
#include <stdbool.h> // bool

static long double cunit__internal_fabsl(long double x);
static cunit_suite_t* cunit__internal_init_suite(const char* suiteName);
static void cunit__internal_register_suite(cunit_suite_t* suite);
static cunit_suite_t* cunit__internal_find_suite(const char* suiteName);
static void cunit__internal_register_test_to_suite(cunit_func_t func, const char* name, cunit_suite_t* suite);
static void cunit__internal_run_test(const cunit_suite_t* suite, const cunit_test_t* test);

cunit_suite_t* suites = NULL;
cunit_suite_t* last_suite = NULL;

cunit_test_t* tests = NULL;
cunit_test_t* last_test = NULL;
size_t tests_count = 0;
size_t tests_count_passed = 0;

cunit_func_t setup_func = NULL;
cunit_func_t cleanup_func = NULL;
cunit_func_t setup_onetime_func = NULL;
cunit_func_t cleanup_onetime_func = NULL;

#ifndef CUNIT_USE_CUSTOM_MAIN
int main(void)
{
    cunit__internal_debug_print_tests_list();
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

static cunit_suite_t* cunit__internal_init_suite(const char* suiteName)
{
    cunit_suite_t* suite = malloc(sizeof(cunit_suite_t));
    if (suite == NULL)
    {
        fprintf(stderr, "malloc()");
        exit(EXIT_FAILURE);
    }

    *suite = (cunit_suite_t)
    {
        .list_data = (cunit_linked_list_t)
        {
            .next_node = NULL
        },
        .name = suiteName,
        .setup_func = NULL,
        .setup_onetime_func = NULL,
        .cleanup_func = NULL,
        .cleanup_onetime_func = NULL,
        .test_first = NULL,
        .test_last = NULL
    };

    return suite;
}

static void cunit__internal_register_suite(cunit_suite_t* suite)
{
    if (cunit__internal_find_suite(suite->name))
    {
        fprintf(stderr, "Cannot create multiple suites with the same name.\n");
        exit(EXIT_FAILURE);
    }

    if (suites == NULL)
    {
        suites = suite;
        last_suite = suite;
    }
    else
    {
        last_suite->list_data.next_node = (cunit_linked_list_t*) suite;
        last_suite = suite;
    }
}

static cunit_suite_t* cunit__internal_find_suite(const char* suiteName)
{
    cunit_suite_t* current_suite = suites;
    while (current_suite != NULL)
    {
        if ( strcmp(current_suite->name, suiteName) == 0 )
        {
            return current_suite;
        }
        else
        {
            current_suite = (cunit_suite_t*) current_suite->list_data.next_node;
        }
    }

    return NULL;
}

static void cunit__internal_register_test_to_suite(cunit_func_t func, const char* name, cunit_suite_t* suite)
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

    if (suite->test_last == NULL)
    {
        suite->test_first = test;
        suite->test_last = test;
    }
    else
    {
        suite->test_last->list_data.next_node = (cunit_linked_list_t*) test;
        suite->test_last = test;
    }
}

void cunit__internal_debug_print_tests_list(void)
{
    printf("\n");
    cunit_suite_t* current_suite = suites;
    while (current_suite != NULL)
    {
        printf("Printing tests for suite: %s\n", current_suite->name);
        cunit_test_t* current_test = current_suite->test_first;
        while (current_test != NULL)
        {
            printf("\t\t%s\n", current_test->name);
            current_test = (cunit_test_t*) current_test->list_data.next_node;
        }
        current_suite = (cunit_suite_t*) current_suite->list_data.next_node;
    }
    printf("\n");
}

/*
 * {func} the handler
 * {func_type} what it handles
 * {suiteName} under what suite should the function be registered
 * {testName} if registering a test, how should it be called? Passed as NULL for any other {func_type} than {CUNIT_FT_TEST}
 */
void cunit__internal_register_func(cunit_func_t func, cunit_func_type_t func_type, const char* suiteName, const char* testName)
{
    cunit_suite_t* suite = cunit__internal_find_suite(suiteName);
    if (suite == NULL)
    {
        suite = cunit__internal_init_suite(suiteName);
        cunit__internal_register_suite(suite);
    }

    cunit_func_t* current_func_addr;
    char* func_type_name;

    switch (func_type)
    {
        case (CUNIT_FT_TEST):
            func_type_name = "TEST";
            cunit__internal_register_test_to_suite(func, testName, suite);
            return;
            break;
        case (CUNIT_FT_SETUP):
            current_func_addr = &suite->setup_func;
            func_type_name = "SETUP";
            break;
        case (CUNIT_FT_CLEANUP):
            current_func_addr = &suite->cleanup_func;
            func_type_name = "CLEANUP";
            break;
        case (CUNIT_FT_SETUP_ONETIME):
            current_func_addr = &suite->setup_onetime_func;
            func_type_name = "SETUP_ONETIME";
            break;
        case (CUNIT_FT_CLEANUP_ONETIME):
            current_func_addr = &suite->cleanup_onetime_func;
            func_type_name = "CLEANUP_ONETIME";
            break;
        default:
            current_func_addr = NULL;
            func_type_name = "UNKNOWN FUNCTION";
            break;
    }

    if ( strcmp(func_type_name, "UNKNOWN FUNCTION") == 0 )
    {
        fprintf(stderr, "Enum value %d is out of range for cunit_func_type_t.\n", func_type);
        exit(EXIT_FAILURE);
    }

    if (*current_func_addr != NULL)
    {
        fprintf(stderr, "%s function redefinition is not allowed.\n", func_type_name);
        exit(EXIT_FAILURE);
    }

    *current_func_addr = func;
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
void cunit_free_tests(void)
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

static void cunit__internal_run_test(const cunit_suite_t* suite, const cunit_test_t* test)
{
    /*
     * SETUP
     */
    if (suite->setup_func != NULL)
    {
        printf("**** Running SetUp function....\n");
        fflush(NULL);
        suite->setup_func();
        printf("**** SetUp finished successfully....\n");
        fflush(NULL);
    }

    /* Running Test, using Self-Piping for Timeouts */
    int timeout_pipe_fd[2] = { 0 };
    if (pipe(timeout_pipe_fd) == -1)
    {
        perror("pipe()");
        exit(EXIT_FAILURE);
    }


    pid_t child_process_pid = fork();
    if (child_process_pid == -1)
    {
        perror("fork()");
        exit(EXIT_FAILURE);
    }
    if (child_process_pid == 0)
    {
        close(timeout_pipe_fd[0]); /* Closing the read end of the pipe */
        test->func();
        _exit(EXIT_SUCCESS);
    }
    else
    {
        close(timeout_pipe_fd[1]); /* Closing the write end of the pipe */

        struct pollfd timeout_pipe_fd_for_poll =
        {
            .fd = timeout_pipe_fd[0],
            .events = POLLHUP | POLLIN
        };

        int timeout_result = poll(&timeout_pipe_fd_for_poll, 1, CUNIT_TIMEOUT_MS);
        if (timeout_result == -1)
        {
            perror("poll()");
            exit(EXIT_FAILURE);
        }
        /*
         * if poll() timed out, the child has to be terminated.
         * else, the child is already dead and this is a no-op:
         *    ESRCH  The target process or process group does not exist.  Note
         *    that an existing process might be a zombie, a process that
         *    has terminated execution, but has not yet been wait(2)ed
         *    for. <===== from the kill() man page.
         */
        kill(child_process_pid, SIGKILL);

        /* Child is now dead, either exited, or killed. */

        int status = 0;
        waitpid(child_process_pid, &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS)
        {
            ++tests_count_passed;
        }
        else if (WIFSIGNALED(status))
        {
            int signal = WTERMSIG(status);
            if (signal == SIGABRT)
            {
            }
            else if (signal == SIGKILL)
            {
                printf("The test timed out after %d miliseconds.\n", CUNIT_TIMEOUT_MS);
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

        close(timeout_pipe_fd[0]); // Closing the read end of the pipe

        /*
         * Clean Up
         */
        if (suite->cleanup_func != NULL)
        {
            printf("**** Running CleanUp function....\n");
            fflush(NULL);
            suite->cleanup_func();
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
        //cunit__internal_run_test(&tests[i], NULL); // Not supporting this anymore, for now at least...
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

void cunit_run_registered_tests(void)
{
    tests_count_passed = 0;
    /*
     * SetUpOneTime
     */
    cunit_suite_t* current_suite = suites;
    while (current_suite != NULL)
    {
        printf("============================================\n");
        if (current_suite->setup_onetime_func != NULL)
        {
            printf("**** Running SetUpOneTime function....\n");
            fflush(NULL);
            current_suite->setup_onetime_func();
            printf("**** SetUpOneTime function finished successfully....\n");
        }

        printf("Running tests in suite: %s\n", current_suite->name);

        cunit_test_t* current_test = current_suite->test_first;
        while (current_test != NULL)
        {
            printf("Running test: %s\n", current_test->name);
            fflush(NULL);
            cunit__internal_run_test(current_suite, current_test);
            current_test = (cunit_test_t*) current_test->list_data.next_node;
        }

        /*
         * CleanUpOneTime
         */
        if (current_suite->cleanup_onetime_func != NULL)
        {

            printf("**** Running CleanUpOneTime function....\n");
            fflush(NULL);
            current_suite->cleanup_onetime_func();
            printf("**** CleanUpOneTime function finished successfully....\n");
        }
        printf("============================================\n");

        current_suite = (cunit_suite_t*) current_suite->list_data.next_node;
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

void cunit__internal_assert_array_is_permutation(const void* a, const void* b, size_t chunk_size, size_t length, const char* fileName, int lineNumber, int shouldAbort)
{
    if (a == NULL || b == NULL)
    {
        printf("%s:%d FAILED. Expected valid pointers, but got NULL in at least one of them\n", fileName, lineNumber);
    }
    else
    {
        bool is_found_all = true;
        for (size_t i = 0; i < length; ++i)
        {
            const void* a_current_element = a + i * chunk_size;
            bool is_found = false;
            for (size_t j = 0; j < length; ++j)
            {
                const void* b_current_element = b + j * chunk_size;
                if ( memcmp(a_current_element, b_current_element, chunk_size) == 0 )
                {
                    is_found = true;
                }
            }
            if (!is_found)
            {
                printf("%s:%d FAILED. Expected contents of %p to contain element number %lu, with address %p, found in %p.\n", fileName, lineNumber, b, i + 1, a_current_element, a);
                is_found_all = false;
            }
        }
        if (is_found_all)
        {
            return;
        }
    }

    if (shouldAbort)
    {
        fflush(stdout);
        abort();
    }
}

void cunit__internal_assert_array_contains(const void* a, const void* b, size_t chunk_size, size_t length_a, size_t length_b, const char* fileName, int lineNumber, int shouldAbort)
{
    if (a == NULL || b == NULL)
    {
        printf("%s:%d FAILED. Expected valid pointers, but got NULL in at least one of them\n", fileName, lineNumber);
    }
    else
    {
        bool is_found_all = true;
        for (size_t i = 0; i < length_b; ++i)
        {
            const void* b_current_element = b + i * chunk_size;
            bool is_found = false;
            for (size_t j = 0; j < length_a; ++j)
            {
                const void* a_current_element = a + j * chunk_size;
                if ( memcmp(b_current_element, a_current_element, chunk_size) == 0 )
                {
                    is_found = true;
                }
            }
            if (!is_found)
            {
                printf("%s:%d FAILED. Expected contents of %p to contain element number %lu, with address %p, found in %p.\n", fileName, lineNumber, a, i + 1, b_current_element, b);
                is_found_all = false;
            }
        }
        if (is_found_all)
        {
            return;
        }
    }

    if (shouldAbort)
    {
        fflush(stdout);
        abort();
    }
}
#endif /* CUNIT_IMPLEMENTATION */

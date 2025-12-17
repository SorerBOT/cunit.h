#ifndef CUNIT_H
#define CUNIT_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define ASSERT(condition) cunit_assert((condition), (#condition), __FILE__, __LINE__)

#define ERROR_MESSAGE_BUFFER 256

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
            char error_message[ERROR_MESSAGE_BUFFER];
            strsignal_r(signal, error_message, ERROR_MESSAGE_BUFFER);
            printf("Test crashed with the error:\n%s\n", error_message);
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

void cunit_assert(int condition, const char* condition_expression, const char* fileName, int lineNumber)
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

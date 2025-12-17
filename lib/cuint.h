#ifndef CUNIT_H
#define CUNIT_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define ASSERT(condition) cunit_assert((condition), (#condition), __FILE__, __LINE__)

typedef void(*cunit_test_func)(void);

void cunit_test(cunit_test_func test)
{
    fflush(NULL);
    pid_t child_process_pid = fork();
    if (child_process_pid == -1)
    {
        perror("fork()");
        exit(EXIT_FAILURE);
    }
    if (child_process_pid == 0)
    {
        test();
        _exit(EXIT_SUCCESS);
    }
    else
    {
        int stat_loc = 0;
        waitpid(child_process_pid, &stat_loc, 0);
        if (WIFEXITED(stat_loc))
        {
            int exit_code = WEXITSTATUS(stat_loc);
        }
        else if (WIFSIGNALED(stat_loc))
        {
            // crashed
        }
    }
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

# cunit.h
Like NUnit or JUnit, but tiny **header onlu**, and written in C for C development.

## How do I use it?
Each tests file represents a single testing-suite. Use the `CUNIT_TEST` macro in order to define a test, and use the macros: `CUNIT_SETUP`, `CUNIT_CLEANUP`, `CUNIT_SETUP_ONETIME`, `CUNIT_CLEANUP_ONETIME` to define functions that would run before and after every test in the current suite (file of tests). Here is how a complete testing suite might look:
```c
#include <stdio.h>
#include "../lib/cunit.h"

CUNIT_SETUP_ONETIME()
{
    printf("Establish connection to DB....\n");
}
CUNIT_CLEANUP_ONETIME()
{
    printf("Terminate connection to DB....\n");
}
CUNIT_SETUP()
{
    printf("Create DB entries for test....\n");
}
CUNIT_CLEANUP()
{
    printf("Delete DB after test....\n");
}
CUNIT_TEST(str_eq)
{
    CUNIT_ASSERT_STR_EQ("Hello World", "Hello World");
    CUNIT_EXPECT_STR_NEQ(NULL, "Bimba");
    CUNIT_EXPECT_STR_NEQ(NULL, NULL);
}

```
## When does a test timeout?
The default timeout duration is 3 seconds. However that can easily be changed by defining:
```c
#define CUNIT_USER_TIMEOUT_MS 10000 // <-- insert your timeout in miliseconds, e.g: 10000 for 10 seconds
...
#define CUNIT_IMPLEMENTATION
#include ".../cunit.h"
```
## What if I want to define my own main function?
The library defines a default main function, which takes care of running the tests and de-allocating memory (de-allocating memory also happens in the destructor) and runs it without requiring the user to do anything. Should the user wish to define his own, custom main function (even though I cannot seem to find any probable reason for him to wish to do so), he may simply define:
```c
#define CUNIT_USE_CUSTOM_MAIN
...
#define CUNIT_IMPLEMENTATION
#include ".../cunit.h"
```
and then add a definition for a `main` function in his own code.

## Available Asseritons:
The library uses two types of assertions, those starting with `ASSERT` are fatal, and will cause the test to terminate prematurely when failed and those starting with `EXPECT` would only log the error, without causing the test to fail.
| Fatal Assertion | Non-Fatal Expectation | Description |
| :--- | :--- | :--- |
| `CUNIT_ASSERT_TRUE(cond)` | `CUNIT_EXPECT_TRUE(cond)` | Fails if `cond` is 0 (False). |
| `CUNIT_ASSERT_FALSE(cond)` | `CUNIT_EXPECT_FALSE(cond)` | Fails if `cond` is non-zero (True). |

### Integer Comparisons
Used for comparing standard integer types.

| Fatal Assertion | Non-Fatal Expectation | Description |
| :--- | :--- | :--- |
| `CUNIT_ASSERT_INT_EQ(a, b)` | `CUNIT_EXPECT_INT_EQ(a, b)` | Verifies `a == b` |
| `CUNIT_ASSERT_INT_NEQ(a, b)` | `CUNIT_EXPECT_INT_NEQ(a, b)` | Verifies `a != b` |
| `CUNIT_ASSERT_INT_LEQ(a, b)` | `CUNIT_EXPECT_INT_LEQ(a, b)` | Verifies `a <= b` |
| `CUNIT_ASSERT_INT_LOWER(a, b)` | `CUNIT_EXPECT_INT_LOWER(a, b)` | Verifies `a < b` |

### Floating Point Comparisons
Used for comparing floats/doubles. 
* **Standard:** Uses `CUNIT_DEFAULT_THRESHOLD` for precision.
* **Threshold:** Allows you to specify a custom `threshold` (epsilon/tolerance).

| Fatal Assertion | Non-Fatal Expectation | Description |
| :--- | :--- | :--- |
| `CUNIT_ASSERT_FLOAT_EQ(a, b)` | `CUNIT_EXPECT_FLOAT_EQ(a, b)` | Verifies `a` equals `b` (default tolerance). |
| `CUNIT_ASSERT_FLOAT_EQ_THRESHOLD(a, b, t)` | `CUNIT_EXPECT_FLOAT_EQ_THRESHOLD(a, b, t)` | Verifies `a` equals `b` (tolerance `t`). |
| `CUNIT_ASSERT_FLOAT_NEQ(a, b)` | `CUNIT_EXPECT_FLOAT_NEQ(a, b)` | Verifies `a` does not equal `b`. |
| `CUNIT_ASSERT_FLOAT_LEQ(a, b)` | `CUNIT_EXPECT_FLOAT_LEQ(a, b)` | Verifies `a <= b` (default tolerance). |
| `CUNIT_ASSERT_FLOAT_LEQ_THRESHOLD(a, b, t)` | `CUNIT_EXPECT_FLOAT_LEQ_THRESHOLD(a, b, t)` | Verifies `a <= b` (tolerance `t`). |
| `CUNIT_ASSERT_FLOAT_LOWER(a, b)` | `CUNIT_EXPECT_FLOAT_LOWER(a, b)` | Verifies `a < b` (default tolerance). |
| `CUNIT_ASSERT_FLOAT_LOWER_THRESHOLD(a, b, t)` | `CUNIT_EXPECT_FLOAT_LOWER_THRESHOLD(a, b, t)` | Verifies `a < b` (tolerance `t`). |

### String Comparisons
Used for C-style null-terminated strings (`char*`).

| Fatal Assertion | Non-Fatal Expectation | Description |
| :--- | :--- | :--- |
| `CUNIT_ASSERT_STR_EQ(a, b)` | `CUNIT_EXPECT_STR_EQ(a, b)` | Verifies string `a` is identical to string `b`. |
| `CUNIT_ASSERT_STR_NEQ(a, b)` | `CUNIT_EXPECT_STR_NEQ(a, b)` | Verifies string `a` is different from string `b`. |
| `CUNIT_ASSERT_STR_CONTAINS(a, b)` | `CUNIT_EXPECT_STR_CONTAINS(a, b)` | Verifies string `a` contains substring `b`. |

### Pointer Comparisons
Used for checking memory addresses and NULL states.

| Fatal Assertion | Non-Fatal Expectation | Description |
| :--- | :--- | :--- |
| `CUNIT_ASSERT_PTR_EQ(a, b)` | `CUNIT_EXPECT_PTR_EQ(a, b)` | Verifies pointer `a` == pointer `b`. |
| `CUNIT_ASSERT_PTR_NEQ(a, b)` | `CUNIT_EXPECT_PTR_NEQ(a, b)` | Verifies pointer `a` != pointer `b`. |
| `CUNIT_ASSERT_PTR_NULL(a)` | `CUNIT_EXPECT_PTR_NULL(a)` | Verifies pointer `a` is `NULL`. |
| `CUNIT_ASSERT_PTR_NOT_NULL(a)` | `CUNIT_EXPECT_PTR_NOT_NULL(a)` | Verifies pointer `a` is not `NULL`. |

### Memory Block Comparisons
Used for comparing raw blocks of memory (like `memcmp`).

| Fatal Assertion | Non-Fatal Expectation | Description |
| :--- | :--- | :--- |
| `CUNIT_ASSERT_MEM_EQ(a, b, size)` | `CUNIT_EXPECT_MEM_EQ(a, b, size)` | Verifies the first `size` bytes of `a` and `b` are identical. |
| `CUNIT_ASSERT_MEM_NEQ(a, b, size)` | `CUNIT_EXPECT_MEM_NEQ(a, b, size)` | Verifies the first `size` bytes of `a` and `b` are different. |

## How does it work?

### Test Registration
In my experience (which is not THAT vast) the predominant majority of unit-tests are quite simple, they revolve around numerical comparisons and assertions and only seldom do they ever crash. For this reason I believe that one of the most distinct features of a testing-library, instead of just writing a main function which goes over standard tests, is having the ability to register tests neatly. In this project, I used the `__attribute(constructor)__` feature, available in modern compilers, which, coupled with some pre-processing _magic_, enabled me to create the following API for registering a test:
```c
CUNIT_TEST(compare_numbers)
{
    int x = 5;
    int y = 3;
    ASSERT_INT_LEQ(x,y); // assert x <= y
}
```
Under the hood, the `CUNIT_TEST` macro looks **almost** like this:
```c
#define CUNIT_TEST(func)                        \
        void func(void);                        \
        __attribute__((constructor))            \
        void register_##func()                  \
        {                                       \
            cunit_register_test(func, #func);   \
        }                                       \
        void func(void)                         \
```
There's a bit to unpack here, but mostly what it does is:
1. Take a function name `func`
2. Declare the function with `void` type for compatibility with older C versions
3. Create a function, with the `__attribute__(constructor)`, that would register the test BEFORE main runs.
4. Then create the actual function `func`. The body of the function is what follows the macro invocation.


If this did not bring a smile to your face, I don't know what would ;)
## Test Running
Each test is ran in a different process, in order to minimise friction between the tests.

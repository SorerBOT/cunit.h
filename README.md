# cunit.h
Like JUnit, but tiny, and written in C for C development.


## How does it work?

### Test Registration
In my experience (which is not vast) the predominant majority of unit-tests are quite simple, they revolve around numerical comparisons and assertions and only seldom do they ever crash. For this reason I believe that one of the most distinct features of a testing-library, instead of just writing a main function which goes over standard tests, is having the ability to register tests neatly. In this project, I used the `__attribute(constructor)__` feature, available in modern compilers, which, coupled with some pre-processing _magic_, enabled me to create the following API for registering a test:
```c
CUNIT_TEST(compare_numbers)
{
    int x = 5;
    int y = 3;
    ASSERT_INT_LEQ(x,y); // assert x <= y
}
```
Under the hood, the `CUNIT_TEST` macro looks like this:
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

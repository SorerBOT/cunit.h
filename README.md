# cunit.h
Like NUnit or JUnit, but tiny, and written in C for C development.

## How do I use it?
Create a **single** tests file. Use the `CUNIT_TEST`, `CUNIT_SETUP`, `CUNIT_CLEANUP`, `CUNIT_SETUP_ONETIME`, `CUNIT_CLEANUP_ONETIME` in order to add tests, a per-test setup function, a per-test cleanup function, a general--one time setup function, and a general--one time cleanup funciton. Here is how a complete testing suite might look:
```c
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
int main()
{
    cunit_run_registered_tests();
    cunit_free_tests(); /* This is completely optional as this function also runs in the destructor */
}
```
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

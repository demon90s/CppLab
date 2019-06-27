#include <stdio.h>
#include "unity/unity.h"

void ohfuck(void)
{
    TEST_FAIL();

    printf("never!!\n");
}

void ohignore(void)
{
    TEST_IGNORE();

    printf("never!!\n");
}

void ohassert(void)
{
    int a = 42;

    TEST_ASSERT(a == 42);
    TEST_ASSERT_EQUAL(42, a);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(ohfuck);
    RUN_TEST(ohignore);
    RUN_TEST(ohassert);

    return UNITY_END();
}

#include <stdio.h>
#include "unity/unity.h"

void ohfuck(void)
{
    TEST_FAIL();
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(ohfuck);

    return UNITY_END();
}

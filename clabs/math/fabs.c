/*
    fabs(arg)
    计算浮点值 arg 的绝对值。
*/

#include <stdio.h>
#include <math.h>
#include <assert.h>

int main(int argc, char const *argv[])
{
    double pi = 3.14;

    assert(fabs(pi) == 3.14);
    assert(fabs(-pi) == 3.14);

    printf("[TEST] fabs PASS\n");

    return 0;
}

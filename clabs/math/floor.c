/*
    floor(arg)
    返回不大于 arg 的最大整数值（向下取整）
*/

#include <stdio.h>
#include <math.h>
#include <assert.h>

int main(int argc, char const *argv[])
{
    assert(floor(2.7) == 2.0);
    assert(floor(-2.7) == -3.0);

    printf("[TEST] floor PASS\n");

    return 0;
}

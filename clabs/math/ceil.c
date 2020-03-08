/*
    ceil
    double ceil(double arg)
    返回不小于 arg 的最小整数（向上取整）

    若 arg 为0或者正负无穷，则不修改
*/

#include <math.h>
#include <stdio.h>
#include <assert.h>

int main(int argc, char const *argv[])
{
    assert(ceil(2.4) == 3.0);
    assert(ceil(-2.4) == -2.0);
    assert(ceil(0) == 0);
    assert(ceil(INFINITY) == INFINITY);

    printf("[TEST] ceil PASS\n");

    return 0;
}

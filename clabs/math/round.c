/*
    double round(double x);
    返回离x最近的整数（就近取整，四舍五入???）
*/

#include <stdio.h>
#include <math.h>
#include <assert.h>

int main()
{
    assert(round(3.3) == 3.0);
    assert(round(3.6) == 4.0);

    assert(round(-3.3) == -3.0);
    assert(round(-3.6) == -4.0);

    printf("[TEST] round PASS\n");

    return 0;
}
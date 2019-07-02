#include <assert.h>

/*
    c11启用的宏
    #include <assert.h>
    static_assert(exp, msg)

    它在编译期对常量表达式exp求值，如果结果是0，那么引发编译错误，并提示 msg 。
    否则，什么都不会发生。
*/

int main()
{
    static_assert(1 + 1 == 2, "compile OK");

    //static_assert(1 - 1 != 0, "Oh no.....");

    return 0;
}

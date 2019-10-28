/*
    函数指针
*/

#include <stdio.h>

void F()
{
    printf("Hello~ function pointer\n");
}

void Foo(void (*f)())
{
    f();
}

int main()
{
    // 定义一个函数指针变量
    {
        void (*fp)();
        fp = F;
        fp();
    }

    // 定义一个函数指针别名
    {
        typedef void(*Fp)();
        Fp fp = F;
        fp();
    }

    // 使用函数指针做函数参数
    {
        Foo(F);
    }
}
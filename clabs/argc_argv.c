#include <stdio.h>

int main(int argc, char *argv[])
{
    // argc表示参数个数 >=1
    // argv表示参数字符串列表 argv[0]表示启动程序

    printf("argc = %d\n", argc);

    for (int i = 0; i < argc; i++)
    {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
}
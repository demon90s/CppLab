/*
    __VA_ARGS__ 是一个预定义宏，表示 ... 的实际内容

    前面需要加## ，不是字符串连接的意思，而是为了兼容 ... 为空的情况
*/

#include <stdio.h>

#define Log(format, ...) \
    printf(format "\n", ##__VA_ARGS__);\
    fflush(stdout);

int main()
{
    Log("hello, %s", "world");

    return 0;
}
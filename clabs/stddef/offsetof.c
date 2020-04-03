/*
    offsetof 宏
    定义于 stddef.h

    offsetof(s, a)
    计算得到结构s的起点到指定成员a间的字节数。
*/

#include <stddef.h>
#include <stdio.h>
#include <assert.h>

// 4字节对齐
#pragma pack(push, 4)
struct s {
    char a;
    int b[2];
    float c;
};
#pragma pack(pop)

int main(int argc, char const *argv[])
{
    assert(offsetof(struct s, a) == 0);

    assert(offsetof(struct s, b) == 4);

    assert(offsetof(struct s, c) == 12);

    printf("[TEST] offsetof PASS\n");

    return 0;
}

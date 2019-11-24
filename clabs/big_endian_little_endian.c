/*
    大端存储、小端存储

    对于一个数
    - 如果大端存储，高位字节存放到低位地址（big bit在前）
    - 如果小端存储，高位字节存放到高位地址（little bit在前）

    几乎所有的网络协议都是 big endian

    Linux系统采取的是 little ending

    内存地址0x0是最低位

    数的最低位是最右位
*/

#include <stdio.h>

// 获取系统是 big endian 还是 little endian
union TestEndian {
    short a;
    char b[2]; // b[0] 是内存低8位，b[1]是内存高8位
};
void get_endian()
{
    union TestEndian te;
    te.a = 0x4321;

    printf("&b[0]=%p\n", &te.b[0]);
    printf("&b[1]=%p\n", &te.b[1]);

    if (te.b[0] == 0x43 && te.b[1] == 0x21) {
        printf("this system is big endian\n");
    }
    else if (te.b[0] == 0x21 && te.b[1] == 0x43) {
        printf("this system is little endian\n");
    }
    else {
        printf("unkown\n");
    }
}

int main()
{
    get_endian();

    return 0;
}
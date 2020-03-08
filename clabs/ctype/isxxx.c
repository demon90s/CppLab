/*
    #include <ctype.h>
    isalnum(c)      c是否是字母或数字
    isalpha(c)      c是否是字母
    iscntrl(c)      c是否是控制字符
    isdigit(c)      c是否是十进制数字
    isgraph(c)      c是否是可显示字符（除空格外）
    islower(c)      c是否是小写字母
    isprint(c)      c是否是可显示字符（包括空格）
    ispunct(c)      c是否是标点符号
    isspace(c)      c是否是空白字符
    isupper(c)      c是否是大写字母
    isxdigit(c)     c是否是十六进制数字

    控制字符包括 \0x00 \0x1f \0x7f

    注意，传进去的是一个字符。

    测试成功返回非零数，失败返回0。
*/

#include <stdio.h>
#include <ctype.h>
#include <assert.h>

int main(int argc, char const *argv[])
{
    assert(isalnum('a'));
    assert(isalnum('8'));
    assert(isalnum('.') == 0);
    printf("[TEST] isalnum PASS\n");

    assert(isxdigit('A'));
    assert(isxdigit('1'));
    assert(isxdigit('O') == 0);
    printf("[TEST] isxdigit PASS\n");
}

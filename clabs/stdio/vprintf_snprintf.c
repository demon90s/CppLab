/*
    int vprintf(const char *format, va_list vlist);
    int snprintf(char *str, size_t size, const char* fmt, va_list ap);

    用于编写包装函数，此函数带有可变实参列表，然后将它传递给 vprintf 。
    返回写的字符数量，不包括末尾的0 。

    snprintf 最多写size个字符，且包括尾0。如果不够写，那么返回应该写的字符数量。
*/

#include <stdarg.h>
#include <stdio.h>

/* 返回format的字符串长度，不包括末尾的o */
int WrapPrint(const char* prefix, const char *format, ...)
{
    printf("%s ", prefix);

    va_list vlist;
    va_start(vlist, format);
    int ret = vprintf(format, vlist);
    va_end(vlist);

    printf("\n");

    return ret;
}
void test_vprintf()
{
    int ret = WrapPrint("Wow that's cool", "%s", "of course!");

    printf("format write chars: %d\n", ret);
}

#define BUFF_SZ 6
void test_snprintf()
{
    char buffer[BUFF_SZ];

    int ret = snprintf(buffer, BUFF_SZ, "hello");
    if (ret >= BUFF_SZ)
    {
        fprintf(stderr, "buff not enough to write, ret: %d, buff: %s\n", ret, buffer);
    }
    else
    {
        printf("ret: %d, buff: %s\n", ret, buffer);
    }
    
}

int main(int argc, char const *argv[])
{
    //test_vprintf();
    test_snprintf();

    return 0;
}

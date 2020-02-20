/*
    char *strchr(const char *s, int c);
    在字符串s中搜索字符c，返回找到的第一个字符的地址，如果找不到，返回空指针。

    char *strrchr(const char *s, int c);
    在字符串s中反向搜索字符c，返回从最后面找到的第一个字符的地址，如果找不到，返回空指针。

    void *memchr(const void *s, int c, size_t n);
    与 strchr 类似，但会在搜索了n个字符后停止，而不是遇到空字符。
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 分割字符串,把结果返回成一个数组指针, 其末尾元素用NULL表示
// 客户要负责释放掉这个数组内的字符串
char** split_string(const char *str, char delim)
{
    int count = 1;  // 子串数量
    const char *s = str;
    const char *p = str;
    while ((p = strchr(s, delim)) != NULL)
    {
        count++;
        s = p + 1;
    }

    // 分配字符串数组空间,多加一个做哨兵
    char **str_arr = (char**)malloc((count+1) * sizeof(char*));
    memset(str_arr, 0, (count+1) * sizeof(char*));

    // 填充数组
    count = 0;
    s = str;
    p = str;
    while ((p = strchr(s, delim)) != NULL)
    {
        int len = p - s;
        char *sub_str = (char*)malloc(sizeof(char) * (len + 1));
        memset(sub_str, 0, len + 1);
        strncpy(sub_str, s, len);

        str_arr[count++] = sub_str;

        s = p + 1;
    }

    // last sub str
    int len = strlen(s);
    char *sub_str = (char*)malloc(sizeof(char) * (len + 1));
    memset(sub_str, 0, len + 1);
    strncpy(sub_str, s, len);

    str_arr[count++] = sub_str;
    
    return str_arr;
}

void test_split_string()
{
    char **str_arr = split_string("hello:world:ni:hao", ':');

    int n = 0;
    char *sub_str = str_arr[n];
    while (sub_str != NULL)
    {
        printf("%s\n", sub_str);

        sub_str = str_arr[++n];
    }

    // free
    n = 0;
    sub_str = str_arr[n];
    while (sub_str != NULL)
    {
        free(sub_str);

        sub_str = str_arr[++n];
    }

    free(str_arr);
}

void test_strchr()
{
    char *p, str[] = "From follows function.";
    p = strchr(str, 'f');
    if (p != NULL) {
        printf("find, pos: %ld\n", p - str);
    }
    else {
        printf("not find\n");
    }
}

void test_strrchr()
{
    char *p, str[] = "From follows function.";
    p = strrchr(str, 'f');
    if (p != NULL) {
        printf("find, pos: %ld\n", p - str);
    }
    else {
        printf("not find\n");
    }
}

void test_memchr()
{
    char *p, str[5] = "Hello";
    p = memchr(str, 'o', sizeof(str));
    if (p != NULL) {
        printf("find, pos: %ld\n", p - str);
    }
    else {
        printf("not find\n");
    }
}

int main(int argc, char const *argv[])
{
    //test_strchr();
    //test_strrchr();
    //test_memchr();

    test_split_string();

    return 0;
}

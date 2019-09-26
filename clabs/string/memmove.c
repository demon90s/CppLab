/*
    void* memmove(void *des, const void *src, size_t num);
    从 src 中拷贝 num 个字节到 des 。
    返回 des 。
    为了避免 overflow ，需要保证 des 和 src 的空间都至少 num 个字节大小。
    des 和 src 的空间可以重叠。
*/

#include <stdio.h>
#include <string.h>

void test1()
{
    char str[] = "memmove can be very useful.....";
    memmove(str + 20, str + 15, 11);
    puts(str);
}

void test2()
{
    // 模拟一个队列的入队/出队操作
    int arr[] = {1, 2, 3, 4};

    memmove(arr + 1, arr, sizeof(arr) - sizeof(arr[0]));
    arr[0] = 100;

    for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // out: 100 1 2 3
}

int main(int argc, char const *argv[])
{
    test1();
    test2();

    return 0;
}

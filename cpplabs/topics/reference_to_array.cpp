/* 指向数组的引用 */

#include <cassert>
#include <cstdio>

int main()
{
    int arr[4] {};

    int (&ra)[4] = arr; // ra是指向数组的引用

    ra[0] = 100;

    assert(arr[0] == 100);

    printf("[TEST] reference to array SUCC\n");
}

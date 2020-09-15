#include <stdio.h>

int main()
{
    printf("0 xor 1: %d\n", 0 ^ 1);
    printf("1 xor 0: %d\n", 1 ^ 0);
    printf("0 xor 0: %d\n", 0 ^ 0);
    printf("1 xor 1: %d\n", 1 ^ 1);

    printf("false xor true: %d\n", false ^ true);
    printf("true xor false: %d\n", true ^ false);
    printf("false xor false: %d\n", false ^ false);
    printf("true xor true: %d\n", true ^ true);
}
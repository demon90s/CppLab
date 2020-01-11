/*
    #include <string.h>
    char* strerror(int errno);

    根据 errno 返回其错误描述。
*/

#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define CHECK_EXIT(res) \
if ((res) != 0) {\
    fprintf(stderr, "system call error at %s:%d, reason: %s\n", __FILE__, __LINE__, strerror(errno));\
    exit(EXIT_FAILURE);\
}

void test1()
{
    double d;
    double res;

    printf("Enter d: ");
    scanf("%lf", &d);

    errno = 0;
    res = sqrt(d);      /* 不能对负数做平方根 */
    if (errno != 0) {
        fprintf(stderr, "sqrt error: %s\n", strerror(errno));
        return;
    }
    else {
        printf("sqrt(%g) = %g\n", d, res);
    }
}

void test2()
{
    double d;
    double res;

    printf("Enter d: ");
    scanf("%lf", &d);

    errno = 0;
    CHECK_EXIT(sqrt(d));      /* 不能对负数做平方根 */
    
    printf("sqrt(%g) = %g\n", d, res);
}

int main()
{
    //test1();
    test2();
    return 0;
}
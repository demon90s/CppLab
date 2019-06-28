/*
 * printf scanf
 * 格式化输入输出
 * 
 * 转换说明：
 * d  	->	int 十进制
 * u	->	unsigned int
 * o	->	8进制整数
 * x	->	16进制整数
 * f	->	float or double, not for scanf double
 * lf	->	double for scanf
 * s	-> 	const char *
 * 
 * printf 返回写入的字符数，不包括空字符
 * scanf 返回成功匹配的个数，如果出现错误或者达到流end，返回EOF，出现错误时ferror is set 。
 */

#include <stdio.h>
#include <string.h>

/*
 * 读写 int 和 float
 */
void example1()
{
	int i;
	float f;

	printf("Enter integer: ");
	scanf("%d", &i);
	printf("%d\n", i);

	printf("Enter float: ");
	scanf("%f", &f);
	printf("%f\n", f);

	printf("Enter integer(至多两位整数): ");
	scanf("%2d", &i);
	printf("%d\n", i);
}

/*
 * 读写无符号整数 p80
 */
void example2()
{
	unsigned int u;

	printf("Enter unsigned interger(base 10): ");
	scanf("%u", &u);
	printf("%u\n", u);

	printf("Enter unsigned interger(base 8): ");
	scanf("%o", &u);
	printf("%o\n", u);

	printf("Enter unsigned interger(base 16): ");
	scanf("%x", &u);
	printf("%x\n", u);
}

/*
 * 读写短整数、长整数 p80
 */
void example3()
{
	short int s;
	long int l;

	printf("Enter short int: ");
	scanf("%hd", &s);
	printf("%hd\n", s);

	printf("Enter long int: ");
	scanf("%ld", &l);
	printf("%ld\n", l);
}

/*
 * 读写double p83
 */
void example4()
{
	double d;

	printf("Enter double: ");
	scanf("%lf", &d);
	printf("%f", d);
}

/*
 * 读写字符 p86
 * 不会跳过开始的空白字符
 */
void example5()
{
	char ch;
	
	printf("Enter char: ");
	scanf("%c", &ch);
	printf("0x%x\n", ch);
}

/*
 * 写 size_t
 */
void example_size_t()
{
	printf("sizeof int: %zu\n", sizeof(int));
}

/*
 * 写字符串
 */
void example6()
{
	printf("%s\n", "Hello World");

	// %*s 代表字符串宽度是*
	// 这里就是6的宽度，因此输出 ###bar ，#代表空格
	int depth = 6;
	printf("%*s\n", depth, "bar");
}

/*
 * 读字符串
 * 程序员保证buf足够
 * 从第一个非空白字符开始读
 * 遇空白终止读取(将其放回)，末尾被自动添加0
*/
void example_scanf_string()
{
	char buf[1024];

	printf("Enter string: ");
	scanf("%s", buf);
	printf("%s\n", buf);
	printf("length: %zu\n", strlen(buf));
}

/* 安全使用 scanf 读取字符串的例子 */
void example_scanf_string2()
{
	char str[5];
	scanf("%4s", str);
	printf("%s\n", str);
}

int main()
{
	//example1();
	//example2();
	//example3();
	//example4();
	//example5();
	//example6();
	//example_size_t();
	//example_scanf_string();
	example_scanf_string2();

	return 0;
}

#include <limits.h>
#include <stdio.h>

// see: https://zh.cppreference.com/w/cpp/header/climits

void print_platform()
{
	// gcc macro
	#ifdef __i386__
	printf("platform: 32\n");
	#endif

	#ifdef __x86_64__
	printf("platform: 64\n");
	#endif

	printf("\n");
}

int main()
{
	print_platform();

	// 字节的位数
	printf("char bit: %d\n", CHAR_BIT);

	// char的取值
	printf("char range: [%d, %d]\n", CHAR_MIN, CHAR_MAX);

	// short的取值
	printf("short range: [%d, %d]\n", SHRT_MIN, SHRT_MAX);

	// int的取值
	printf("int range: [%d, %d]\n", INT_MIN, INT_MAX);

	// long的取值
	printf("long range: [%ld, %ld]\n", LONG_MIN, LONG_MAX);

	// long long的取值
	printf("long long range: [%lld, %lld]\n", LLONG_MIN, LLONG_MAX);

	printf("==================> unsigned type range\n");

	// unsigned char的取值
	printf("unsigned char range: [%u, %u]\n", 0, UCHAR_MAX);

	// unsigned short的取值
	printf("unsigned short range: [%u, %u]\n", 0, USHRT_MAX);

	// unsigned int的取值
	printf("unsigned int range: [%u, %u]\n", 0, UINT_MAX);

	// unsigned long的取值
	printf("unsigned long range: [%lu, %lu]\n", 0LU, ULONG_MAX);

	// unsigned long long的取值
	printf("unsigned long long range: [%llu, %llu]\n", 0LLU, ULLONG_MAX);

	return 0;
}

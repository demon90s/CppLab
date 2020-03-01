/*
std::string::copy

size_type copy(char *dest, size_type count, size_type pos = 0) const;

复制子串 [pos, pos + count) 到 dest 所指的字符串。

若请求的子串越过 string 结尾，或若 count == npos ，则复制的子串为 [pos, size()) ，产生的字符串结尾没有空字符。

若 pos > size() ，则抛出 std::out_of_range 。

返回复制的字符数。
*/

#include <iostream>
#include <string>
#include <cassert>
#include <cstring>

void test1()
{
	std::string str = "Hello World";
	char cstr[12]; memset(cstr, -1, sizeof(cstr));	// 故意这么做,copy不会添加空字符
	int n = str.copy(cstr, std::string::npos);

	assert(cstr[11] == -1);
	assert(n == 11);	// 复制了11个字符,没有包括空字符

	cstr[11] = '\0';
	assert(strcmp(cstr, "Hello World") == 0);

	char cstr2[6] {};
	str.copy(cstr2, sizeof(cstr2) - 1);
	assert(strcmp(cstr2, "Hello") == 0);

	str.copy(cstr2, sizeof(cstr2) - 1, 6);
	assert(strcmp(cstr2, "World") == 0);
}

int main()
{
	test1();

	std::cout << "[TEST] string::copy PASS\n";
	return 0;
}

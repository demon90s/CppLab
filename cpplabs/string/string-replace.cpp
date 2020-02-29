/*
 * s.replace(range, args) 删除s中范围 range 内的字符，替换为 args 指定的字符。
 * range 或者是一个下标和一个长度，或者是一对指向s的迭代器。返回一个指向s的引用。
 */

#include <iostream>
#include <string>
#include <cassert>

int main()
{
	std::string s = "Hello, world";

	s.replace(0, 5, "Hi");

	assert(s == "Hi, world");

	std::cout << "[TEST] string::replace PASS\n";

	return 0;
}

/*
 * s.assign(args) 将s中的字符替换为 args 指定的字符。返回一个指向s的引用。
 */

#include <iostream>
#include <string>
#include <cassert>

int main()
{
	std::string s = "Hey";

	s.assign("Hi");
	assert(s == "Hi");

	std::cout << "[TEST] string::assign PASS\n";
	return 0;
}

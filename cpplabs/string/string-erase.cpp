/*
 * s.erase(pos, len) 删除从位置 pos 开始的 len 个字符。如果 len 被省略，则删除
 * 从 pos 开始至s末尾的所有字符。返回一个指向s的引用。
 */

#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>

int main()
{
	std::string s = "Hello World";
	s.erase(5);
	assert(s == "Hello");

	s = "1";
	s.erase(1);	// end位置，不越界
	assert(s == "1");

	bool catch_exp = false;
	try {
		s.erase(2); // 越界了，抛出异常
	} catch (std::out_of_range) {
		catch_exp = true;
	}
	assert(catch_exp);


	std::cout << "[TEST] string::erase PASS\n";
	return 0;
}

/*
 * s.rfind(args) 查找s中 args 最后一次出现的位置
 */

#include <iostream>
#include <string>
#include <cassert>

int main()
{
	std::string s = "AnnieBellenie";

	auto pos = s.rfind("nie");
	
	assert(pos == 10);

	std::cout << "[TEST] string::rfind PASS\n";

	return 0;
}

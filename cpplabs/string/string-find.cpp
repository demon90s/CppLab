/*
 * s.find(args) 查找s中 args 第一次出现的位置
 * s.find(args, pos) 查找s中始于 pos 位置的 args 第一次出现的位置
 * 
 * 找不到返回 npos
 */

#include <iostream>
#include <string>
#include <cassert>

void test1()
{
	std::string name = "AnnaBelle";

	auto pos = name.find("Bell");
	assert(pos == 4);

	pos = name.find("Bea");
	assert(pos == std::string::npos);
}

int main()
{
	test1();

	std::cout << "[TEST] string::find PASS\n";

	return 0;
}

// 测试getline
// getline(stream, str, delim)
// 从流中读取数据，直到遇到delim，默认delim是\n，将已经读到的内容拷贝给str，不包括delim
// 返回stream
// 如果读到文件尾，设置eofbit

#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>

void test1()
{
	// 输入测试：hello#world
	std::string str;
	std::istringstream iss("hello#world");

	// 截取hello
	std::getline(iss, str, '#');
	assert(str == "hello");

	// 输出剩下的world
	std::getline(iss, str);
	assert(str == "world");
	assert(iss);

	// 到达尾
	std::getline(iss, str);
	assert(!iss && iss.eof());
}

void test2()
{
	std::istringstream iss("hello|world");

	std::string word;
	std::vector<std::string> str_vec;
	while (getline(iss, word, '|'))
	{
		str_vec.push_back(word);
	}
	assert(str_vec.size() == 2);
	assert(str_vec[0] == "hello");
	assert(str_vec[1] == "world");
}

int main()
{
	test1();
	test2();

	std::cout << "[TEST] getline PASS\n";
}

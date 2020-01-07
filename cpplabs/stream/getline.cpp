// 测试getline

#include <iostream>
#include <sstream>

using namespace std;

void test()
{
	// 输入测试：hello#world
	string str;

	// 截取hello
	getline(cin, str, '#');
	cout << str << endl;

	// 输出剩下的world
	getline(cin, str);
	cout << str << endl;

	// 输入CTRL+D，str被置为空字符串
	getline(cin, str);
	cout << str << endl;
	if (str.size() == 0)
		cout << "str is empty" << endl;
}

void test2()
{
	std::string str;

	std::cin >> str;
	istringstream iss(str);

	std::string word;
	while (getline(iss, word, '|'))
	{
		cout << word << endl;
	}
}

int main()
{
	test2();

	return 0;
}

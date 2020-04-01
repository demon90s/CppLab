// test: 测试类型别名

#include <iostream>
#include <map>
#include <cassert>

using namespace std;

typedef long long 	Int64;			// 简单的类型别名
typedef char		Name[32];		// 数组类型别名（char[32]）
typedef void 		(*Func)(int);	// 函数指针类型

class Funcs;
typedef void		(Funcs::*f)();	// Funcs类里面的函数指针类型
class Funcs {
public:
	Funcs() {
		funcs_map.insert({"f1", &Funcs::f1});
	}

	void Call(const std::string &func)
	{
		auto it = funcs_map.find(func);
		if (it != funcs_map.end())
		{
			auto func = it->second;
			(this->*func)();
		}
	}

private:
	void f1() { cout << "f1" << endl; }
	std::map<std::string, f> funcs_map;
};

#define PRINT(x)\
do { printf("sizeof %s: %lu\n", #x, sizeof(x)); } while(0)

int main()
{
	PRINT(Int64);				// 8
	PRINT(Name);				// 32
	PRINT(Func);				// 8

	Funcs funcs;
	funcs.Call("f1");

	// 下面是坑
	{
		typedef int *IntP;
		int a = 42;
		const IntP pi = &a;
		// pi是顶层而非底层，即不能修改pi，却可以修改它绑定的对象
		*pi = 100;
		assert(a == 100);
		//pi = nullptr; // compile error: assignment of read-only variable
	}

	return 0;
}

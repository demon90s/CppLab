/*
 一致性初始化（ Uniform Initialization ）

 即面对何初始化动作，都可以使用大括号来初始化，若不设定初值，采用值初始化。

 对于“窄化”，使用大括号初始化将被拒绝。

 深层次解释：
 1. {...} 实际上是一个 initializer_list, 其底层又是一个 array<T, N>
 2. 如果对象的类型构造函数支持 initializer_list, 那么直接将初始化包传给构造函数
 3. 如果没有构造函数支持 initializer_list, 编译器把参数分解，传递给对应构造函数
 4. 传递一个空包，则对对象执行值初始化（对象需要支持默认构造函数）
*/

#include <vector>
#include <string>

struct Foo
{
	Foo(int _x, int _y) : x(_x), y(_y) {}
	int x, y;
};

void examples()
{
	int values[] {1, 2, 3};
	std::vector<int> v{1, 2, 3};
	std::vector<std::string> {"Berlin", "New York", "London"};

	int i{};	// i = 0
	int *p{};	// p = nullptr

	Foo foo{3, 4};

	// 窄化
	//int x{5.0};	// ERROR: narrowing, but some compiler, just warning
	//char c{9999};	// narrowing
	
	(void)values;
	(void)i;
	(void)p;
	//(void)x;
	//(void)c;
}

int main()
{
	examples();

	return 0;
}

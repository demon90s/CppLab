// 定位new表达式

#include <iostream>
#include <cassert>

struct Foo
{
	Foo(int _a, int _b) : a(_a), b(_b) { std::cout << "Foo::Foo()\n"; }
	~Foo() { std::cout << "Foo::~Foo()\n"; }
	int a, b;
};

int main()
{
	char *buffer = new char[sizeof(Foo)];

	auto foo = new (buffer) Foo(2, 3); // 定位new不分配内存，只在预先分配的内存地址上构造对象

	assert(foo->a == 2);
	assert(foo->b == 3);

	assert((void*)foo == (void*)buffer);

	foo->~Foo();					  // 手动调用析构函数

	delete []buffer;

	std::cout << "[TEST] placement new PASS\n";
}

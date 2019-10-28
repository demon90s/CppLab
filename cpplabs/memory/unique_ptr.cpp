// unique_ptr
// unique_ptr 独占它所指向的对象
// 它禁止拷贝或赋值

#include <cstdlib>
#include <iostream>
#include <memory>

struct Foo
{
public:
	Foo() {}
	~Foo() { std::cout << "Foo release" << std::endl; }
};

void test1()
{
	std::unique_ptr<Foo[]> up(new Foo[3]);
	//up.release();	// pointer release() 放弃掉管理权
}

void test2()
{
	// test memory leak: valgrind ./unique_ptr
	std::unique_ptr<char[]> a(new char[rand()]);
}

void test3()
{
	std::unique_ptr<Foo> up(new Foo);

	up.reset(new Foo);	// reset resource
}

// copy temperory unique_ptr
// 我们可以拷贝一个将要销毁的 unique_ptr
void example1()
{
	auto clone = [](int i) -> std::unique_ptr<int> {
		return std::unique_ptr<int>(new int(i));
	};

	auto p = clone(42);

	std::cout << *p << std::endl;
}

// custom deleter
void CustomDeleter()
{
	auto deleter = [](Foo *fp) {
		std::cout << "custom delete Foo\n";
		delete fp;
	};

	std::unique_ptr<Foo, decltype(deleter)> cup(new Foo, deleter);

	std::cout << "sizeof cup=" << sizeof(cup) << std::endl;	// 8, just like raw pointer(use lambda)
}

int main()
{
	//test2();
	//test3();
	//example1();
	CustomDeleter();

	std::cout << "main return" << std::endl;
	return 0;
}

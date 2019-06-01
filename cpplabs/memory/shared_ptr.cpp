#include <iostream>
#include <memory>
#include <string>

// shared_ptr
// 智能指针，可使用引用计数来共享资源

void test1()
{
	// make_shared<T>(args)
	// 如同 emplace, args 是传递给T的构造函数参数列表
	auto p = std::make_shared<std::string>(5, 'H');

	std::cout << *p << std::endl;	
}

void test_use_count()
{
	auto p1 = std::make_shared<int>(10);
	auto p2(p1);
	auto p3(p2);

	std::cout << "p1 use_count: " << p1.use_count() << std::endl;
	std::cout << "p2 use_count: " << p2.use_count() << std::endl;
	std::cout << "p3 use_count: " << p3.use_count() << std::endl;
}

// deletor type: void (T*)
void test_deleter()
{
	auto deleter = [](int* p)
	{
		std::cout << "delete data: " << *p << std::endl;
		delete p;
	};

	std::shared_ptr<int> p(new int(42), deleter);
}

// reset
// 将智能指针设置为空，如果它是唯一的资源句柄，那么释放掉资源
void test_reset()
{
	std::shared_ptr<int> p1(new int(42));
	auto p2 = p1;

	std::cout << p2 << ": " << *p2 << std::endl;		// add: 42

	p2.reset();
	std::cout << p2 << std::endl;						// 0

	std::cout << p1.use_count() << std::endl;			// 1
}

int main()
{
	//test1();
	//test_use_count();
	//test_deleter();
	test_reset();

	return 0;
}

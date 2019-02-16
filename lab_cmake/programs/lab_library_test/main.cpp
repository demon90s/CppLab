#include <iostream>
#include <functional>
#include "Bitset.h"
#include "SmallFuncs.h"
#include "templates.hpp"
#include "Serializer.hpp"
#include "TraceBack/TraceBack.h"
#include "Array2D.hpp"
#include "colorprintf.h"
#include "FileReader.hpp"
#include "LimitList.hpp"
#include "NameFilter/NameFilter.hpp"
#include "ObjectPool.hpp"
#include "Factory.hpp"
#include "str_bkdr.hpp"

void TestBitset();
void TestGetMinIndex();
void TestSerializer();
void TestTraceBack();
void TestNum();
void TestArray2D();
void TestColorPrint();
void TestFileReader();
void TestIsUTF8();
void TestGetMaxMin();
void TestLimitList();
void TestNameFilter();
void TestTimeStrToTimestamp();
void Test_LL_TO_INT();
void Test_PrintFlag();
void Test_ObjectPool();
void Test_Factory();
void Test_str_bkdr();

int main(int argc, char* argv[])
{
	std::cout << argv[0] << std::endl;

	//TestBitset();
	//TestGetMinIndex();
	//TestSerializer();
	//TestTraceBack();
	//TestNum();
	//TestArray2D();
	//TestColorPrint();
	//TestFileReader();
	//TestIsUTF8();
	//TestGetMaxMin();
	//TestLimitList();
	//TestNameFilter();
	//TestTimeStrToTimestamp();
	//Test_LL_TO_INT();
	//Test_PrintFlag();
	//Test_ObjectPool();
	//Test_Factory();
	Test_str_bkdr();

	Pause("paused...");

	return 0;
}

void TestBitset()
{
	Bitset8 b8;
	b8.Set(1);
	b8.Set(2);
	std::cout << b8 << std::endl;

	b8.Reset();
	std::cout << b8 << std::endl;
}

void TestGetMinIndex()
{
	int arr[] = { 1, 3, 8, 2, 0, 5 };
	std::cout << GetMinIndex(arr) << std::endl;
	std::cout << GetMaxIndex(arr) << std::endl;
}

void TestSerializer()
{
	struct Foo
	{
		float pi;
		long long l;
	};

	Serializer s;
	{
		int a = 42;
		double d = 3.14;
		int arr[] = { 1, 2, 3 };
		Foo foo{ 6.18f, 1000 };

		s.Write(a, d, arr, foo);
	}

	DeSerializer us(s.Ptr(), s.Size());
	{
		int a;
		double d;
		int arr[3];
		Foo foo;

		us.Read(a, d, arr, foo);

		// output
		std::cout << a << " "
			<< d << std::endl;

		for (auto i : arr)
			std::cout << i << " ";
		std::cout << std::endl;

		std::cout << foo.pi << " " << foo.l << std::endl;
	}
}

void TestTraceBack()
{
	TraceBack();
}

void TestNum()
{
	LimitNum<0, 100> number;
	number = 1000;
	std::cout << number << std::endl;

	number = number - 90;
	std::cout << number << std::endl;

	number = number + 20;
	std::cout << number << std::endl;

	number = number * 5;
	std::cout << number << std::endl;

	number = number / 10;
	std::cout << number << std::endl;

	number = number % 3;
	std::cout << number << std::endl;

	number = 1000;
	std::cout << number << std::endl;

	number -= 90;
	std::cout << number << std::endl;

	number += 20;
	std::cout << number << std::endl;

	number *= 5;
	std::cout << number << std::endl;

	number /= 10;
	std::cout << number << std::endl;

	number %= 3;
	std::cout << number << std::endl;
}

void TestArray2D()
{
	Array2D<int, 3, 4> arr2d;

	for (int row = 0; row < arr2d.Row(); ++row)
	{
		for (int col = 0; col < arr2d.Col(); ++col)
		{
			int idx = arr2d.GetIdx(row, col);
			arr2d[idx] = idx + 1;
		}
	}

	arr2d.Sort(std::greater<int>());
	arr2d.Sort(0, std::less<int>());

	std::cout << "done\n";
}

void TestColorPrint()
{
	CONSOLE_ERROR("This is an error");
	CONSOLE_DEBUG("%s", "This is a Debug");
	CONSOLE_WARNING("This is a warning");
}

void TestFileReader()
{
	FileReader fr;
	if (fr.Load("test.txt"))
	{
		std::cout << fr.Data() << std::endl;
	}
	else
	{
		std::cerr << "Load file failure" << std::endl;
	}
}

void TestIsUTF8()
{
	if (Is_File_UTF8_NoBom("test.txt"))
	{
		std::cout << "file is utf8 no bom" << std::endl;
	}
	else
	{
		std::cout << "file is NOT utf8 no bom" << std::endl;
	}
}

void TestGetMaxMin()
{
	int a[] = { 3, 4, 10, 9, 100 };
	int max, min;

	GetMaxMin(a, &max, &min);

	std::cout << "max: " << max << "\n";
	std::cout << "min: " << min << "\n";
}

void TestLimitList()
{
	/*{
		LimitList<int, 5> limit_list{ 1, 2, 3, 4, 5, 6, 7 };

		for (const auto &v : limit_list)
		{
			printf("%d ", v);
		}
		printf("\n");
	}*/
	
	/*{
		LimitList<int, 5> limit_list;
		limit_list.PushBack(1);
		limit_list.PushBack(2);
		limit_list.PushBack(3);

		limit_list.PushFront(3);
		limit_list.PushFront(2);
		limit_list.PushFront(1);

		for (const auto &v : limit_list)
		{
			printf("%d ", v);
		}
		printf("\n");

		for (auto it = limit_list.begin(); it != limit_list.end();)
		{
			if (*it == 2) it = limit_list.Erase(it);
			else ++it;
		}

		for (const auto &v : limit_list)
		{
			printf("%d ", v);
		}
		printf("\n");

		limit_list.PopFront();
		limit_list.PopBack();

		for (const auto &v : limit_list)
		{
			printf("%d ", v);
		}
		printf("\n");
	}*/

	{
		LimitList<int, 5> limit_list{42, 100, 22, 13};
		for (const auto &v : limit_list)
		{
			printf("%d ", v);
		}
		printf("\n");

		limit_list.Sort();
		for (const auto &v : limit_list)
		{
			printf("%d ", v);
		}
		printf("\n");

		limit_list.Sort([](const int& a, const int& b) { return a > b; });
		for (const auto &v : limit_list)
		{
			printf("%d ", v);
		}
		printf("\n");
	}

	/*{
		LimitList<int, 5> limit_list{ 42, 100, 22, 13 };
		int arr[5] = { -100000, -100000, -100000, -100000, -100000 };

		limit_list.ToCArray(arr);
		for (const auto &v : arr)
		{
			printf("%d ", v);
		}
		printf("\n");

		limit_list.Clear();
		for (const auto &v : limit_list)
		{
			printf("%d ", v);
		}
		printf("\n");
	}*/
}

void TestNameFilter()
{
	std::string err;
	bool ret = NameFilter::Instance().Init("name.txt", &err);
	if (!ret)
	{
		printf("Init NameFilter failure: %s\n", err.c_str());
		return;
	}

	printf("Init NameFilter succ\n");

	std::string input;
	std::cout << "Enter word to test: ";
	while (getline(std::cin, input))
	{
		if (NameFilter::Instance().HasSensitiveWord(input.length(), input.c_str()))
		{
			std::cout << "Has sensitive word" << std::endl;
		}
		else
		{
			std::cout << "Fine" << std::endl;
		}

		std::cout << "Enter word to test: ";
	}
}

void TestTimeStrToTimestamp()
{
	std::string time_str;

	std::cout << "Enter time str(yyyy-mm-dd hh:mm::ss): ";
	while (getline(std::cin, time_str))
	{
		time_t timestamp = 0;
		if (TimeStrToTimestamp(time_str.c_str(), &timestamp))
		{
			std::cout << timestamp << std::endl;
		}
		else
		{
			std::cout << "invalid time str" << std::endl;
		}

		std::cout << "Enter time str(yyyy-mm-dd hh:mm::ss): ";
	}
}

void Test_LL_TO_INT()
{
	{
		long long ll_v = 112345678900000000;

		std::cout << ll_v << std::endl;
		std::cout << (int)ll_v << std::endl;
		std::cout << LL_TO_INT(ll_v) << std::endl;
	}

	{
		long long ll_v = -11234567890000000;

		std::cout << ll_v << std::endl;
		std::cout << (int)ll_v << std::endl;
		std::cout << LL_TO_INT(ll_v) << std::endl;
	}
}

void Test_PrintFlag()
{
	unsigned int flag = 0xF0;

	(void)flag;
}

void Test_ObjectPool()
{
	class Foo
	{
	public:
		Foo() : buffer{}  { std::cout << "Foo::Foo()" << std::endl; }
		~Foo() { std::cout << "Foo::~Foo()" << std::endl; }
		void Print() { std::cout << "Foo::Print()" << std::endl; }

	private:
		char buffer[1024 * 1024];
	};

	/*{
		ObjectPool<Foo> obj_pool;
		auto pooled_obj = obj_pool.GetPooledObject();
		pooled_obj->Print();
		obj_pool.ReturnPooledObject(pooled_obj);
	}*/
	
	while (true)
	{
		PISleep(500);

		/*static */ObjectPool<Foo> obj_pool; // check if alloc new memory
		ObjectPool<Foo>::Object foo_list[3];
		for (auto &foo : foo_list)
		{
			foo = obj_pool.GetPooledObject();
			foo->Print();
		}

		for (auto foo : foo_list)
		{
			obj_pool.ReturnPooledObject(foo);
		}
	}
}

void Test_Factory()
{
	class Base {
	public:
		virtual ~Base() {}
		virtual void Whoami() const = 0;
	};

	class Derived1 : public Base {
		void Whoami() const override {
			std::cout << "I am Derived1" << std::endl;
		}
	};

	class Derived2 : public Base {
		void Whoami() const override {
			std::cout << "I am Derived2" << std::endl;
		}
	};

	typedef std::function<std::shared_ptr<Base>()> CreateObject;
	Factory<CreateObject> factory;
	factory.RegisterObject("Derived1",
						   [](){ return std::make_shared<Derived1>(); });
	factory.RegisterObject("Derived2",
						   [](){ return std::make_shared<Derived2>(); });

	std::shared_ptr<Base> d1 = factory.Create("Derived1");
	std::shared_ptr<Base> d2 = factory.Create("Derived2");

	d1->Whoami();
	d2->Whoami();
}

void Test_str_bkdr()
{
	std::string name;
	std::cout << "enter name: " << std::endl;
	std::cin >> name;

	switch(TypicalBKDR(name.c_str())) {
			case "diwen"_bkdr:
					std::cout << "Hello diwen\n";
					break;

			case "miemie"_bkdr:
					std::cout << "Hello miemie\n";
					break;

			default:
					std::cout << "Hello guest " << name << std::endl;
					break;
	}
}

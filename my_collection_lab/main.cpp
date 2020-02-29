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
#include "FunctorTable.hpp"
#include "marcofuncs.hpp"

void TestBitset();
void TestGetMinIndex();
void TestSerializer();
void TestTraceBack();
void TestArray2D();
void TestColorPrint();
void TestFileReader();
void TestIsUTF8();
void TestGetMaxMin();
void TestNameFilter();
void TestTimeStrToTimestamp();
void Test_PrintFlag();
void Test_ObjectPool();
void Test_FunctorTable();

int main(int argc, char* argv[])
{
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
    //Test_FunctorTable();

	return 0;
}

void TestBitset()
{
	/*
	{
		Bitset8 b8;
		b8.Set(1);
		b8.Set(2);
		std::cout << b8 << std::endl;

		b8.Reset();
		std::cout << b8 << std::endl;
	}
	*/

	{
		Bitset32 b32;
		b32.Set(1);
		std::cout << b32 << std::endl;

		Bitset32 b32_2;
		b32_2.Set(2);
		std::cout << b32_2 << std::endl;

		b32 |= b32_2;
		std::cout << b32 << std::endl;
	}
	
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

void Test_FunctorTable()
{
    FunctorTable ft;

    ft.Register(1, []() {
       Log("Fuck~~~~1");
    });

    ft.Register(2, []() {
       Log("Fuck~~~~2");
    });

    ft.Call(1);
    ft.Call(2);
    ft.Call(3);
}
#include <iostream>
#include "Bitset.h"
#include "SmallFuncs.h"
#include "templates.hpp"
#include "Serializer.hpp"
#include "TraceBack/TraceBack.h"
#include "Array2D.hpp"
#include "colorprintf.h"
#include "FileReader.hpp"

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
	TestGetMaxMin();

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
	Num<0, 100> number;
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
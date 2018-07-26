#include <iostream>
#include "Bitset.h"
#include "SmallFuncs.h"
#include "templates.hpp"
#include "Serializer.hpp"
#include "TraceBack/TraceBack.h"

void TestBitset();
void TestGetMinIndex();
void TestSerializer();
void TestTraceBack();
void TestNum();

int main()
{
	//TestBitset();
	//TestGetMinIndex();
	//TestSerializer();
	//TestTraceBack();
	TestNum();

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
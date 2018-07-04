#include <iostream>
#include "Bitset.h"
#include "SmallFuncs.h"
#include "templates.hpp"
#include "Serializer.hpp"

void TestBitset();
void TestGetMinIndex();
void TestSerializer();

int main()
{
	//TestBitset();
	//TestGetMinIndex();
	TestSerializer();

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
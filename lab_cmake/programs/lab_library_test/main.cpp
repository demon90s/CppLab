#include <iostream>
#include "Bitset.h"
#include "SmallFuncs.h"
#include "templates.hpp"

void TestBitset();
void TestGetMinIndex();

int main()
{
	//TestBitset();
	TestGetMinIndex();

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
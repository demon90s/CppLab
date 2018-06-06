#include "RandFuncs.h"
#include <map>
#include <iostream>

std::random_device& RD()
{
	static std::random_device rd;
	return rd;
}

std::mt19937& GEN()
{
	static std::mt19937 gen(RD()());
	return gen;
}

unsigned long RandNum(unsigned long min, unsigned long max)
{
	if (min == max) return min;

	if (min > max) std::swap(min, max);

	std::uniform_int_distribution<unsigned long> dist(min, max);

	return dist(RD());
}

extern void Test_RandFuncs()
{
	std::map<unsigned long, int> m;

	for (int i = 0; i < 100000; ++i)
	{
		++m[RandNum(1, 10)];
	}

	for (auto &p : m)
	{
		std::cout << p.first << " occured: " << p.second << " times" << std::endl;
	}
}

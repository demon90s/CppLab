#include "RandFuncs.h"
#include <iostream>
#include <string>

/*
- usage: rand [number]

- default number is 100

- e.g.
$ rand 100
42
*/
int main(int argc, char *argv[])
{
	unsigned long min = 0, max = 0;
	if (argc <= 1)
	{
		max = 100;
	}
	else
	{
		try
		{
			max = std::stoul(argv[1]);
		}
		catch (...)
		{
			std::cout << "usage: rand [number]" << std::endl;
			return -1;
		}
	}

	std::cout << RandNum(min, max);
}
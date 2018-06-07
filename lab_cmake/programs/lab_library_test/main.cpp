#include <iostream>
#include "Bitset.h"
#include "SmallFuncs.h"

int main()
{
	Bitset8 b8;
	b8.Set(1);
	b8.Set(2);
	std::cout << b8 << std::endl;

	Pause();

	return 0;
}
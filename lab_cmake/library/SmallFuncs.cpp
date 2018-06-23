#include "SmallFuncs.h"
#include <cstdlib>
#include <iostream>

#ifdef __unix
#include <unistd.h>
#endif

void Pause(const char *notice)
{
	if (notice)
	{
		std::cout << notice << std::flush;
	}
#ifdef __unix
	pause();
#endif

#ifdef _MSC_VER
	system("pause > nul");
#endif
}
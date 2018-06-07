#include "SmallFuncs.h"
#include <cstdlib>

#ifdef __unix
#include <unistd.h>
#endif

void Pause()
{
#ifdef __unix
	pause();
#endif

#ifdef _MSC_VER
	system("pause > nul");
#endif
}
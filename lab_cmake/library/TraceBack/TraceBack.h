#pragma once

#ifdef _MSC_VER
#include "StackWalker.h"
#else
#include "stacktrace.h"
#endif
#include <string>

// 输出程序的调用堆栈
inline void TraceBack()
{
	std::string out;
#ifdef _MSC_VER
	StackWalker sw;
	sw.ShowCallstack(&out);
#else
	stacktrace(out);
#endif
	std::vector<std::string> frames;
	ParseParam(out.c_str(), frames, "\n");
	
	for (size_t i = 0; i < frames.size(); ++i)
	{
		printf("#%lu: %s\n", i, frames[i].c_str());
	}
}

inline void TraceBack(std::string *str)
{
#ifdef _MSC_VER
	StackWalker sw;
	sw.ShowCallstack(str);
#else
	stacktrace(*str);
#endif
	std::string out = *str;
	std::vector<std::string> frames;
	ParseParam(out.c_str(), frames, "\n");

	for (size_t i = 0; i < frames.size(); ++i)
	{
		printf("#%lu: %s\n", i, frames[i].c_str());
	}
}

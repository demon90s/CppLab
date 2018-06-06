#ifndef RAND_TOOL_H
#define RAND_TOOL_H

#include <random>

extern void Test_RandFuncs();

// 获取一个范围内[min, max]的随机值
extern unsigned long RandNum(unsigned long min, unsigned long max);

#endif // RAND_TOOL_H

#ifndef SMALL_FUNCS_H
#define SMALL_FUNCS_H

#include <time.h>

// 挂起进程，可以选择输出一个字符串作为提示
extern void Pause(const char *notice = nullptr);

// 获取毫秒时间戳
extern unsigned long PITime();

// 时间字符串（格式如 2018-09-16 10:12:08）转换成时间戳
extern bool TimeStrToTimestamp(const char *time_str, time_t *timestamp);

// 两个int与一个long long之间的转换
long long ConvertParamToLongLong(int param_0, int param_1);
void ParseParamFromLongLong(long long key, int *param_0, int *param_1);

// 取随机整数值，取值范围是[beg, end)
int RandomNum(int beg, int end);

// 判断 Buffer 是否是 UTF8 格式的序列
extern bool IsUTF8(const char* buffer, long size);

// 判断 Buffer 是否是 UTF8 带 BOM 格式的序列
extern bool IsUTF8_Bom(const char* buffer, long size);

// 判断文件是否是 UTF-8 无 BOM 格式的
extern bool Is_File_UTF8_NoBom(const char *filename);

#endif // SMALL_FUNCS_H
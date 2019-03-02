#ifndef SMALL_FUNCS_H
#define SMALL_FUNCS_H

#include <time.h>
#include <string>
#include <cstring>
#include <vector>

// 挂起进程，可以选择输出一个字符串作为提示
extern void Pause(const char *notice = nullptr);

// 获取毫秒时间戳
extern unsigned long PITime();

// 睡眠执行线程若干毫秒
void PISleep(unsigned long timems);

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

// 按分隔符分解字符串，存到result里，返回分解的字符串个数, 但不线程安全
int ParseParam(const char *src, std::vector<std::string> &result, const char *delim);

// 按分隔符分解字符串，将分割好的字符串返回
std::vector<std::string> SplitString(const std::string &str, const char* delim);

#endif // SMALL_FUNCS_H

#pragma once
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

// 静态检查，输出字符串内容就是检查内容
#define STATIC_ASSERT(expr) static_assert(expr, #expr)

// 简化数组拷贝，加了静态检查
#define ARRAYCPY(dst, src)\
do\
{\
	memcpy((dst), (src), sizeof(src));\
	static_assert(sizeof(src) == sizeof(dst), "ARRAYCPY sizeof(src) == sizeof(dst)");\
	static_assert(sizeof((src)[0]) == sizeof((dst)[0]), "ARRAYCPY sizeof((src)[0]) == sizeof((dst)[0])");\
} while(0)

// 设置、判断、清除标记位，bit取值范围：[0, 64)
#define SET_BIT(flag, bit) ((flag) |= (UInt64)1 << (bit))
#define IS_BIT_SET(flag, bit) (((flag) & ((UInt64)1 << (bit))) != 0)
#define CLEAR_BIT(flag, bit) ((flag) &= ~((UInt64)1 << (bit)))

// long long 转换成 int ，如果超过了 int 的最值，就取它的最值
#define LL_TO_INT(ll_v) ((ll_v) > INT_MAX ? INT_MAX : ((ll_v) < INT_MIN ? INT_MIN : (int)(ll_v)))

// 字符串拷贝 转long long是为了屏蔽LINUX下的警告
#define STRNCPY(dst_str, src_str, dst_len)                     \
{                                                              \
	if (NULL != (dst_str) && (int)(dst_len) > 0)               \
	{                                                          \
		if (NULL != (src_str) && ((long long)dst_str) != ((long long)src_str))       \
		{                                                      \
			strncpy((dst_str), (src_str), (dst_len) - 1);      \
			(dst_str)[(dst_len) - 1] = '\0';                   \
		}										               \
		else                                                   \
		{                                                      \
			(dst_str)[0] = '\0';                               \
		}                                                      \
	}                                                          \
}

// 定长字符串数组拷贝
#define F_STRNCPY(dst_str, src_str, len)                       \
{                                                              \
	if (NULL != (dst_str) && (int)(len) > 0)                   \
	{                                                          \
		if (NULL != (src_str) && (dst_str) != (src_str))       \
		{                                                      \
			memcpy((dst_str), (src_str), (len) - 1);           \
			(dst_str)[(len) - 1] = '\0';                       \
		}                                                      \
		else                                                   \
		{                                                      \
			(dst_str)[0] = '\0';                               \
		}                                                      \
	}                                                          \
}

// 字符串格式化操作函数
inline int SNPRINTF(char *dst, int len, const char *format, ...)
{
	if (NULL == dst || len <= 0 || NULL == format) return -1;

	va_list va;
	va_start(va, format);

	int ret = vsnprintf(dst, len, format, va);
	if (ret >= len) ret = -1;

	va_end(va);

	dst[len - 1] = '\0';

	return ret;
}

// Format Log
#define Log(format, ...) printf(format "\n", ##__VA_ARGS__); fflush(stdout);
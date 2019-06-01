#pragma once
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

// ��̬��飬����ַ������ݾ��Ǽ������
#define STATIC_ASSERT(expr) static_assert(expr, #expr)

// �����鿽�������˾�̬���
#define ARRAYCPY(dst, src)\
do\
{\
	memcpy((dst), (src), sizeof(src));\
	static_assert(sizeof(src) == sizeof(dst), "ARRAYCPY sizeof(src) == sizeof(dst)");\
	static_assert(sizeof((src)[0]) == sizeof((dst)[0]), "ARRAYCPY sizeof((src)[0]) == sizeof((dst)[0])");\
} while(0)

// ���á��жϡ�������λ��bitȡֵ��Χ��[0, 64)
#define SET_BIT(flag, bit) ((flag) |= (UInt64)1 << (bit))
#define IS_BIT_SET(flag, bit) (((flag) & ((UInt64)1 << (bit))) != 0)
#define CLEAR_BIT(flag, bit) ((flag) &= ~((UInt64)1 << (bit)))

// long long ת���� int ����������� int ����ֵ����ȡ������ֵ
#define LL_TO_INT(ll_v) ((ll_v) > INT_MAX ? INT_MAX : ((ll_v) < INT_MIN ? INT_MIN : (int)(ll_v)))

// �ַ������� תlong long��Ϊ������LINUX�µľ���
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

// �����ַ������鿽��
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

// �ַ�����ʽ����������
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
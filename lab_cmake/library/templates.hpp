#ifndef __TEMPLATES_HPP__
#define __TEMPLATES_HPP__

#include <vector>
#include <climits>
#include "marcofuncs.hpp"

// 获取数组中最小元素的下标
template<typename T, unsigned N>
inline int GetMinIndex(T (&arr)[N])
{
	int index = 0;
	const T *tmp = &arr[0];
	for (int i = 1; i < N; ++i)
	{
		if (*tmp > arr[i])
		{
			index = i;
			tmp = &arr[i];
		}
	}
	return index;
}

// 获取数组中最大元素的下标
template<typename T, unsigned N>
inline int GetMaxIndex(T(&arr)[N])
{
	int index = 0;
	const T *tmp = &arr[0];
	for (int i = 1; i < N; ++i)
	{
		if (*tmp < arr[i])
		{
			index = i;
			tmp = &arr[i];
		}
	}
	return index;
}

// 按分隔符分解字符串，存到result里，返回分解的字符串个数
inline int ParseParam(const char *src, std::vector<std::string> &result, const char *delim)
{
	static char temp[4096] = {};

	STRNCPY(temp, src, sizeof(temp));
	result.clear();

	char *token = strtok(temp, delim);

	while (NULL != token)
	{
		result.push_back(token);
		token = strtok(NULL, delim);
	}

	return (int)result.size();
}

// 有范围的整数，取值：[LOWER, UPPER]
template<long long LOWER = 0, long long UPPER = INT_MAX>
class Num
{
public:
	Num() : m_val(0) { this->Check(); }
	Num(long long val) : m_val(val) { this->Check(); }
	operator long long() { return m_val; }

	Num& operator+=(const Num& number)
	{
		m_val += number.m_val;
		this->Check();
		return *this;
	}

	Num& operator-=(const Num& number)
	{
		m_val -= number.m_val;
		this->Check();
		return *this;
	}

	Num& operator*=(const Num& number)
	{
		m_val *= number.m_val;
		this->Check();
		return *this;
	}

	Num& operator/=(const Num& number)
	{
		m_val /= number.m_val;
		this->Check();
		return *this;
	}

	Num& operator%=(const Num& number)
	{
		m_val %= number.m_val;
		this->Check();
		return *this;
	}

private:
	void Check()
	{
		if (m_val < LOWER) m_val = LOWER;
		else if (m_val > UPPER) m_val = UPPER;
	}

	long long m_val;
};

#endif // __TEMPLATES_HPP__

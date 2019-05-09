#ifndef __TEMPLATES_HPP__
#define __TEMPLATES_HPP__

#include <vector>
#include <sstream>
#include <climits>
#include <cstdlib>
#include "marcofuncs.hpp"

// 返回数组的元素的个数
template <typename T, int N>
inline int ArrayItemCount(T(&arr)[N])
{
	return N;
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


/*
* string转换成基础类型，返回是否转换成功
*/
template<typename T>
bool string_to_basetype(const std::string &str, T &val)
{
	std::istringstream iss(str);
	if (iss >> val)
		return true;
	else
		return false;
}

/*
* 基础类型转换成string，返回是否转换成功
*/
template<typename T>
bool basetype_to_string(T &val, std::string &str)
{
	std::ostringstream oss;
	if (oss << val) {
		str = oss.str();
		return true;
	}
	return false;
}

// 有范围的整数，取值：[LOWER, UPPER]
template<long long LOWER = 0, long long UPPER = INT_MAX>
class LimitNum
{
public:
	LimitNum() : m_val(0) { this->Check(); }
	LimitNum(long long val) : m_val(val) { this->Check(); }
	operator long long() { return m_val; }

	LimitNum& operator+=(const LimitNum& number)
	{
		m_val += number.m_val;
		this->Check();
		return *this;
	}

	LimitNum& operator-=(const LimitNum& number)
	{
		m_val -= number.m_val;
		this->Check();
		return *this;
	}

	LimitNum& operator*=(const LimitNum& number)
	{
		m_val *= number.m_val;
		this->Check();
		return *this;
	}

	LimitNum& operator/=(const LimitNum& number)
	{
		m_val /= number.m_val;
		this->Check();
		return *this;
	}

	LimitNum& operator%=(const LimitNum& number)
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

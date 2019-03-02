#ifndef __TEMPLATES_HPP__
#define __TEMPLATES_HPP__

#include <vector>
#include <sstream>
#include <climits>
#include "marcofuncs.hpp"

// ���������Ԫ�صĸ���
template <typename T, int N>
inline int ArrayItemCount(T(&arr)[N])
{
	return N;
}

// ��ȡ��������СԪ�ص��±�
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

// ��ȡ���������Ԫ�ص��±�
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

// ��ȡ�����е����ֵ����Сֵ
template<typename T, unsigned N>
inline void GetMaxMin(T(&arr)[N], T* max, T* min)
{
	*max = *min = arr[0];
	for (int i = 0; i < N; ++i)
	{
		if (*max < arr[i]) *max = arr[i];
		if (*min > arr[i]) *min = arr[i];
	}
}

/*
* stringת���ɻ������ͣ������Ƿ�ת���ɹ�
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
* ��������ת����string�������Ƿ�ת���ɹ�
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

// �з�Χ��������ȡֵ��[LOWER, UPPER]
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

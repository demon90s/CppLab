#ifndef __TEMPLATES_HPP__
#define __TEMPLATES_HPP__

#include <vector>
#include <climits>
#include "marcofuncs.hpp"

// ��ӡ flag
template<typename T>
inline void PrintFlag(T _flag)
{
	char buf[65] = { 0 };

	unsigned long long flag = 0;
	memcpy(&flag, &_flag, sizeof(_flag));

	ultoa((unsigned long)flag, buf, 2);

	printf("flag: %s\n", buf);
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

// ���ָ����ֽ��ַ������浽result����طֽ���ַ�������
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

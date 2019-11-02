#ifndef __BIT_SET_HPP__
#define __BIT_SET_HPP__

#include <iostream>
#include <string>
#include <list>
#include <cstring>
#include <climits>

// 支持N位bit的标记结构，N必须是字节比特位（8）的倍数
// bit位从最低位开始（最右）
template <unsigned N>
class Bitset
{
	static const int BIT_FIELD_SIZE = CHAR_BIT * sizeof(unsigned char);	// 一个位域占一个字节
	static const int BIT_FIELD_COUNT = N / BIT_FIELD_SIZE;
	static const int BIT_COUNT = N;										// 总共支持N个bit
public:
	Bitset() { this->Reset(); }
	void Reset();														// 重置所有bit位
	bool Test(int bit) const;											// 判断第bit位是否激活
	void Set(int bit);													// 设置第bit位为1
	void UnSet(int bit);												// 设置第bit位为0
	constexpr int Bit() const { return N; }								// 总共支持多少比特位
	int CountOfSet() const;												// 总共设置了多少bit位

	operator std::string() const { return ToStdString(); }
	operator unsigned long long() const { return ToULongLong(); }
	operator unsigned int() const { return ToUInt(); }
	void operator|=(const Bitset &rhs);

	std::string ToStdString() const;
	unsigned long long ToULongLong() const;
	unsigned int ToUInt() const;

	void Copy(unsigned char (&bit_set)[BIT_FIELD_COUNT]);

private:
	static_assert(N > 0 && N % BIT_FIELD_SIZE == 0, "Invalid Bitset Instance");

	unsigned char bit_field_list[BIT_FIELD_COUNT] = {0};
};

// typedef
using Bitset8   = Bitset<8>;
using Bitset32	= Bitset<32>;
using Bitset64	= Bitset<64>;
using Bitset128 = Bitset<128>;
using Bitset256 = Bitset<256>;
using Bitset512 = Bitset<512>;

//-------------------------------------------------------------------------------------------

// implement

template <unsigned N> inline
void Bitset<N>::Reset()
{
	memset(bit_field_list, 0, sizeof(bit_field_list));
}

template <unsigned N> inline
bool Bitset<N>::Test(int bit) const
{
	if (bit < 0 || bit >= BIT_COUNT)
	{
		return false;
	}

	const int bit_field = bit / BIT_FIELD_SIZE;

	if (bit_field < 0 || bit_field >= BIT_FIELD_COUNT)
	{
		return false;
	}

	unsigned char flag = bit_field_list[bit_field];
	int real_bit = bit % BIT_FIELD_SIZE;

	return (flag & (1 << real_bit)) != 0;
}

template <unsigned N> inline
void Bitset<N>::Set(int bit)
{
	if (bit < 0 || bit >= BIT_COUNT)
	{
		return;
	}

	const int bit_field = bit / BIT_FIELD_SIZE;

	if (bit_field < 0 || bit_field >= BIT_FIELD_COUNT)
	{
		return;
	}

	unsigned char &flag = bit_field_list[bit_field];
	int real_bit = bit % BIT_FIELD_SIZE;

	flag |= (1 << real_bit);
}

template <unsigned N> inline
void Bitset<N>::UnSet(int bit)
{
	if (bit < 0 || bit >= BIT_COUNT)
	{
		return;
	}

	const int bit_field = bit / BIT_FIELD_SIZE;

	if (bit_field < 0 || bit_field >= BIT_FIELD_COUNT)
	{
		return;
	}

	unsigned char &flag = bit_field_list[bit_field];
	int real_bit = bit % BIT_FIELD_SIZE;

	flag &= ~(1 << real_bit);
}

template <unsigned N> inline
int Bitset<N>::CountOfSet() const
{
	int count = 0;
	for (unsigned i = 0; i < N; i++)
	{
		if (this->Test(i))
		{
			count++;
		}
	}
	return count;
}

template <unsigned N> inline
std::string Bitset<N>::ToStdString() const
{
	std::list<char> tmp_list;
	for (unsigned i = 0; i < N; ++i)
	{
		if (this->Test(i))
		{
			tmp_list.push_front('1');
		}
		else
		{
			tmp_list.push_front('0');
		}
	}
	return std::string(tmp_list.begin(), tmp_list.end());
}

template <unsigned N> inline
unsigned long long Bitset<N>::ToULongLong() const
{
	unsigned long long ret = 0;
	for (unsigned i = 0; i < N && i < sizeof(ret) * CHAR_BIT; ++i)
	{
		if (this->Test(i))
		{
			ret |= 1ULL << i;
		}
	}
	return ret;
}

template <unsigned N> inline
unsigned int Bitset<N>::ToUInt() const
{
	unsigned int ret = 0;
	for (unsigned i = 0; i < N && i < sizeof(ret) * CHAR_BIT; ++i)
	{
		if (this->Test(i))
		{
			ret |= 1U << i;
		}
	}
	return ret;
}

template <unsigned N> inline
std::ostream& operator<<(std::ostream &os, const Bitset<N> &bs)
{
	os << bs.ToStdString();
	return os;
}

template <unsigned N> inline
void Bitset<N>::Copy(unsigned char (&bit_set)[BIT_FIELD_COUNT])
{
	static_assert(sizeof(bit_field_list) == sizeof(bit_set), "Invalid param");

	memcpy(bit_set, bit_field_list, sizeof(bit_set));
}

template <unsigned N> inline
void Bitset<N>::operator|=(const Bitset<N> &rhs)
{
	for (unsigned i = 0; i < N; ++i)
	{
		if (rhs.Test(i))
		{
			this->Set(i);
		}
	}
}

template <unsigned N> inline
Bitset<N> operator|(const Bitset<N> &lhs, const Bitset<N> &rhs)
{
	Bitset<N> bs = lhs;
	bs |= rhs;
	return bs;
}

//-------------------------------------------------------------------------------------------

#endif // __BIT_SET_HPP__

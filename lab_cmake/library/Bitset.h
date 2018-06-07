#ifndef __BIT_SET_HPP__
#define __BIT_SET_HPP__

#include <iostream>
#include <string>
#include <list>

// 支持N位bit的标记结构，N必须是字节比特位（8）的倍数
// bit位从最低位开始（最右）
template <unsigned N>
struct Bigset
{
	static const int BIT_FIELD_SIZE = 8 * sizeof(unsigned char);		// 一个位域占一个字节
	static const int BIT_FIELD_COUNT = N / BIT_FIELD_SIZE;
	static const int BIT_COUNT = N;										// 总共支持N个bit

	static_assert(N > 0 && N % BIT_FIELD_SIZE == 0, "Invalid Bitset Instance");

	bool Test(int bit) const;			// 判断第bit位是否激活
	void Set(int bit);					// 设置第bit位为1
	void ReSet(int bit);				// 设置第bit位为0

	std::string ToString() const;		// 返回数据的字符串表示

	unsigned char bit_field_list[BIT_FIELD_COUNT] = {0};
};

template <unsigned N> inline
std::string Bigset<N>::ToString() const
{
	std::list<char> tmp_list;
	for (int i = 0; i < N; ++i)
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
std::ostream& operator<<(std::ostream &os, const Bigset<N> &bs)
{
	os << bs.ToString();
	return os;
}

// typedef
using Bitset8	= Bigset<8>;
using Bitset16	= Bigset<16>;
using Bitset32	= Bigset<32>;
using Bitset64	= Bigset<64>;
using Bitset128 = Bigset<128>;
using Bitset256 = Bigset<256>;
using Bitset512 = Bigset<512>;

//-------------------------------------------------------------------------------------------

// implement

template <unsigned N> inline
bool Bigset<N>::Test(int bit) const
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
void Bigset<N>::Set(int bit)
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
void Bigset<N>::ReSet(int bit)
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

//-------------------------------------------------------------------------------------------

#endif // __BIT_SET_HPP__
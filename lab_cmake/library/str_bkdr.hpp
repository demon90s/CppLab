#pragma once

#include <string>
#include <iostream>

// ���ַ����ڱ�����ת���� hash ֵ�ķ���
// g++-7 ͨ������

namespace detail {
	template<unsigned SEED>
	constexpr unsigned const_bkdr(unsigned hash, const char* str) noexcept
	{
		return *str ? const_bkdr<SEED>(
			static_cast<unsigned>(static_cast<uint64_t>(hash) * SEED + (*str))
			, str + 1) : hash;
	}
}

// Typical BKDR hash function
constexpr unsigned TypicalBKDR(const char *str) noexcept
{
		return detail::const_bkdr<131>(0, str);
}

// BKDR
constexpr unsigned operator ""_bkdr(const char *str, size_t) noexcept
{
		return TypicalBKDR(str);
}

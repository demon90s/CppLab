#ifndef __TEMPLATES_HPP__
#define __TEMPLATES_HPP__

#include <vector>
#include <sstream>
#include <climits>
#include <cstdlib>
#include <cstdarg>

// in c++ 17, you can use std::size
template <typename T, int N>
inline int ArrayItemCount(T(&arr)[N])
{
	return N;
}

// 注意，这两个函数，效率比较低
template<typename T>
bool string_to_basetype(const std::string &str, T &val)
{
	std::istringstream iss(str);
	if (iss >> val)
		return true;
	else
		return false;
}

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

#endif // __TEMPLATES_HPP__

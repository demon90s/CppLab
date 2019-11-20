#pragma once

#include <cstring>
#include <string>
#include <cassert>

template<int LEN = 32>
class FixLenStr
{
public:
    FixLenStr() :
        m_data {}
    {
        assert(LEN > 0);
    }

    FixLenStr(const char *str) :
        FixLenStr()
    {
        strncpy(m_data, str, LEN);
        m_data[LEN - 1] = 0;
    }

    FixLenStr(const std::string &str) :
        FixLenStr(str.c_str())
    {
    }

    int Size() const
    {
        return LEN;
    }

    int Len() const
    {
        return static_cast<int>(strlen(m_data));
    }

    void Reset(const char *str)
    {
        this->operator=(str);
    }

    void Reset()
    {
        memset(m_data, 0, sizeof(m_data));
    }

    const char *Data() const
    {
        return m_data;
    }

    void Copy(char (&raw)[LEN]) const
    {
        memcpy(raw, m_data, LEN);
    }

public:
    FixLenStr &operator=(const FixLenStr &str)
    {
        memmove(m_data, str.m_data, LEN);
        return *this;
    }

    FixLenStr &operator=(const char *str)
    {
        strncpy(m_data, str, LEN);
        m_data[LEN - 1] = 0;
        return *this;
    }

    FixLenStr &operator=(const std::string &str)
    {
        return this->operator=(str.c_str());
    }

    operator const char*() const
    {
        return this->Data();
    }

    operator std::string() const
    {
        return this->Data();
    }

private:
    char m_data[LEN];
};

template<int LEN>
std::ostream &operator<<(std::ostream &os, const FixLenStr<LEN> &str)
{
    os << str.Data();
    return os;
}

using FixStr32 = FixLenStr<32>;
using FixStr64 = FixLenStr<64>;
using FixStr256 = FixLenStr<256>;
using FixStr1024 = FixLenStr<1024>;

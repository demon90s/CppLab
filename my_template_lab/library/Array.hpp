#pragma once

#include <string>
#include <cassert>
#include <functional>

template<typename T, int N>
class Array
{
public:
    Array() :
        m_data {}
    {}

    Array(const std::initializer_list<T> &il) :
        m_data {}
    {
        int count = 0;
        for (const T& item : il)
        {
            if (count >= this->Size()) break;
            m_data[count++] = item;
        }
    }

    int Size() const
    {
        return N;
    }

    bool InvalidIndex(int index) const
    {
        return index < 0 || index >= this->Size();
    }

    T &operator[](int index)
    {
        assert(!InvalidIndex(index));

        return m_data[index];
    }

    const T &operator[](int index) const
    {
        return static_cast<const T&>(
            (const_cast<Array*>(this)->operator[](index)));
    }

public:
    void Travel(std::function<void(T&)> f)
    {
        for (auto &item : m_data)
        {
            f(item);
        }
    }

    void Travel(std::function<void(const T&)> f)
    {
        for (const auto &item : m_data)
        {
            f(item);
        }
    }

    void Copy(T (&raw)[N]) const
    {
        for (int i = 0; i < N; i++)
        {
            raw[i] = m_data[i];
        }
    }

public:
    // iterators
    T *begin()
    {
        return m_data;
    }

    const T *begin() const
    {
        return static_cast<const T*>(
            (const_cast<Array*>(this)->begin()));
    }

    const T *cbegin() const
    {
        return this->begin();
    }

    T *end()
    {
        return m_data + this->Size();
    }

    const T *end() const
    {
        return static_cast<const T*>(
            (const_cast<Array*>(this)->end()));
    }

    const T *cend() const
    {
        return this->end();
    }

private:
    T m_data[N];
};

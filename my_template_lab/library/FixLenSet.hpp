#pragma once

// 定长无序set，元素唯一
// 要求 T 实现 operator== 操作

// 若要用key找，要求T实现一个叫Key的静态函数，返回一个T作为匹配对象
// 函数签名如： T Key(K key)

// 若set满，继续插入就会失败

#include <functional>
#include <algorithm>
#include <iostream>
#include "Bitset.h"

template<typename T, int N>
class FixLenSet
{
private:
    T m_set[N];

    static const int INDEX_COUNT = ((N % 8 == 0) ? (N / 8) : (N / 8 + 1)) * 8;
    Bitset<INDEX_COUNT> m_used_flag;

public:
    FixLenSet() :
        m_set {}
    {}

    void Reset()
    {
        for (auto &item : m_set)
        {
            item = T {};
        }
        m_used_flag.Reset();
    }

    T *Insert(const T &v)
    {
        T *cur = this->GetItem(v);
        if (cur)
        {
            return cur;
        }
        else
        {
            int insert_index = this->GetFreeIndex();
            if (insert_index == -1)
            {
                return nullptr;
            }
            else
            {
                m_set[insert_index] = v;
                m_used_flag.Set(insert_index);
                return &m_set[insert_index];
            }
        }
    }

    T *GetItem(const T &v, int *index_out = nullptr)
    {
        auto it = std::find(std::begin(m_set), std::end(m_set), v);
        if (it != std::end(m_set))
        {
            int index = static_cast<int>(std::distance(std::begin(m_set), it));
            if (!m_used_flag.Test(index))
            {
                return nullptr;
            }

            if (index_out)
            {
                *index_out = index;
            }
            return &(*it);
        }
        return nullptr;
    }

    const T *GetItem(const T &v, int *index_out = nullptr) const
    {
        return static_cast<const T *>(
            const_cast<FixLenSet*>(this)->GetItem(v, index_out));
    }

    template<typename K>
    T *GetItem(const K &key, int *index_out = nullptr)
    {
        return this->GetItem(T::Key(key), index_out);
    }

    template<typename K>
    const T *GetItem(const K &key, int *index_out = nullptr) const
    {
        return static_cast<const T *>(
            const_cast<FixLenSet*>(this)->GetItem(key, index_out));
    }

    void Erase(const T &v)
    {
        int erase_index = -1;
        auto item = this->GetItem(v, &erase_index);
        if (item)
        {
            m_used_flag.UnSet(erase_index);
        }
    }

    template<typename K>
    void Erase(const K &key)
    {
        this->Erase(T::Key(key));
    }

    bool HasItem(const T &v) const
    {
        return this->GetItem(v) != nullptr;
    }

    template<typename K>
    bool HasItem(const K &key) const
    {
        return this->GetItem(key) != nullptr;
    }

public:
    int GetFreeIndex()
    {
        for (int i = 0; i < N; i++)
        {
            if (!m_used_flag.Test(i))
            {
                return i;
            }
        }
        return -1;
    }

    void Print()
    {
        std::cout << "----------------------------\n";
        for (int i = 0; i < N; i++)
        {
            if (m_used_flag.Test(i))
            {
                std::cout << m_set[i] << std::endl;
            }
        }
        std::cout << "----------------------------\n";
    }
};

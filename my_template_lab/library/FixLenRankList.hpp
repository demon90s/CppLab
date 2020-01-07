#pragma once

/*
    定长可排序列表
    要求 T 类型自行实现 operator< , operator== 运算符
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

template<typename T, int LEN>
class FixLenRankList
{
private:
    int m_max_index;
    T m_rank_list[LEN];

public:
    FixLenRankList() :
        m_max_index(0),
        m_rank_list {}
    {
    }

    void Reset()
    {
        m_max_index = 0;
        for (auto &item : m_rank_list)
        {
            item = T {};
        }
    }

    // 找一个最小的替换，Push不会排序
    void Push(const T &item)
    {
        // 已在列表中，更新
        auto it = std::find(std::begin(m_rank_list), std::end(m_rank_list), item);
        if (it != std::end(m_rank_list))
        {
            *it = item;
            return;
        }

        // 比最小的还小，忽略
        auto min_it = std::min_element(std::begin(m_rank_list), std::end(m_rank_list));
        if (item < *min_it)
        {
            return;
        }

        // 替换最小的
        *min_it = item;

        // 重新计算最大值
        auto max_it = std::max_element(std::begin(m_rank_list), std::end(m_rank_list));
        m_max_index = std::distance(std::begin(m_rank_list), max_it);
    }

    // 排序
    void Sort()
    {
        std::stable_sort(std::begin(m_rank_list), std::end(m_rank_list), 
            [](const T &lhs, const T &rhs) { return rhs < lhs; });
    }

    // 获取第一名，一定是最新的
    const T &GetTop() const
    {
        return m_rank_list[m_max_index];
    }

    // 不保证已排序
    std::vector<T> GetTopList(int count) const
    {
        std::vector<T> top;
        top.reserve(count);
        for (int i = 0; i < count && i < LEN; i++)
        {
            top.push_back(m_rank_list[i]);
        }
        return top;
    }

public:
    // iterators
    const T *begin() const
    {
        return m_rank_list;
    }

    const T *end() const
    {
        return m_rank_list;
    }

public:
    void PrintRankList() const
    {
        std::cout << "-----------------------------------\n";
        std::cout << "rank\tvalue\n";
        for (int rank = 0; rank < LEN; rank++)
        {
            std::cout << rank + 1 << "\t" << m_rank_list[rank] << std::endl;
        }
        std::cout << "-----------------------------------\n";
    }
};

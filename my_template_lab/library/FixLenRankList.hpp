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
    int m_need_sort_flag;
    T m_rank_list[LEN];

public:
    FixLenRankList() :
        m_need_sort_flag(0),
        m_rank_list {}
    {
        static_assert(LEN > 0, "LEN MUST > 0");
    }

    void Reset()
    {
        m_need_sort_flag = 0;
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
        m_need_sort_flag = 1;
    }

    // 获取第一名，一定是最新的
    const T &GetTop() const
    {
        if (m_need_sort_flag)
        {
            const_cast<FixLenRankList*>(this)->Sort();
        }
        return m_rank_list[0];
    }

    // 保证已排序
    std::vector<T> GetTopList(int count = LEN) const
    {
        if (m_need_sort_flag)
        {
            const_cast<FixLenRankList*>(this)->Sort();
        }

        std::vector<T> top;
        top.reserve(count);
        for (int i = 0; i < count && i < LEN; i++)
        {
            top.push_back(m_rank_list[i]);
        }
        return top;
    }

public:
    void PrintRankList() const
    {
        auto rank_list = this->GetTopList();

        std::cout << "-----------------------------------\n";
        std::cout << "rank\tvalue\n";
        for (size_t rank = 0; rank < rank_list.size(); rank++)
        {
            std::cout << rank + 1 << "\t" << rank_list[rank] << std::endl;
        }
        std::cout << "-----------------------------------\n";
    }

private:
    // 排序
    void Sort()
    {
        std::stable_sort(std::begin(m_rank_list), std::end(m_rank_list), 
            [](const T &lhs, const T &rhs) { return rhs < lhs; });

        m_need_sort_flag = 0;
    }
};

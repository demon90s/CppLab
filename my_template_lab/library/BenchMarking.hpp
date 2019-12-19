#pragma once

#include <chrono>
#include <iostream>
#include <functional>

// 基准测试，采用RAII衡量调用栈花费的时间，精度与 std::chrono::duration 一致
// 默认精度: 毫秒
template<typename RATIO = std::chrono::milliseconds>
class BenchMarking
{
public:
    BenchMarking(std::function<void(std::size_t)> ouput_func = nullptr)
    {
        m_start_tp = std::chrono::high_resolution_clock::now();

        m_ouput_func = ouput_func;
    }

    ~BenchMarking()
    {
        auto end_tp = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<RATIO>(m_start_tp);
        auto end = std::chrono::time_point_cast<RATIO>(end_tp);

        auto diff = end - start;

        std::size_t dur = diff.count();

        if (m_ouput_func == nullptr)
            std::cout << "BenchMarking duration: " << dur << std::endl;
        else
            m_ouput_func(dur);
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start_tp;
    std::function<void(std::size_t)> m_ouput_func;
};
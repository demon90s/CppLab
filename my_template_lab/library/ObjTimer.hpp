#pragma once

#include <map>
#include <ctime>

template<typename T>
class Timer
{
    typedef void (T::*TimerFunc)();

public:
    Timer(T *obj) :
        m_obj(obj),
        m_func_invoke_time_map([](TimerFunc *lhs, TimerFunc *rhs) { return (long long)lhs < (long long)rhs; })
    {
    }

    Timer(const Timer&) = delete;
    Timer &operator=(const Timer&) = delete;

    void AddFunc(TimerFunc f, int delay_second)
    {
        if (m_func_invoke_time_map.find(f) != m_func_invoke_time_map.end())
        {
            return;
        }

        m_func_invoke_time_map[f] = time(NULL) + delay_second;
    }

    void CheckInvoke()
    {
        time_t now = time(NULL);

        for (auto it = m_func_invoke_time_map.begin(); it != m_func_invoke_time_map.end();)
        {
            if (it->second >= now)
            {
                (m_obj->*it->first)();

                it = m_func_invoke_time_map.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

private:
    T *m_obj;

    std::map<TimerFunc, time_t, bool(*)(TimerFunc*, TimerFunc*)> m_func_invoke_time_map;
};

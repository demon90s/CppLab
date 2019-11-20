#pragma once

#include <list>

template<typename T>
class ObjFuncInvoker
{
    typedef void (T::*Func)();
public:
    ObjFuncInvoker(T *obj) :
        m_obj(obj)
    {
    }
    ObjFuncInvoker(const ObjFuncInvoker&) = delete;
    ObjFuncInvoker &operator=(const ObjFuncInvoker&) = delete;

    void Register(Func f)
    {
        for (auto item : m_func_set)
        {
            if (item == f)
            {
                return;
            }
        }
        m_func_set.push_back(f);
    }

    void Invoke()
    {
        if (m_func_set.size() == 0)
        {
            return;
        }

        for (auto item : m_func_set)
        {
            (m_obj->*item)();
        }
        m_func_set.clear();
    }

private:
    T *m_obj;
    std::list<Func> m_func_set;
};

#ifndef FUNCTOR_TABLE_HPP
#define FUNCTOR_TABLE_HPP

#include <unordered_map>
#include <functional>

/*
 * 简单地函数表，可由一个整数来索引一个可调用对象
 */

class FunctorTable
{
    typedef std::function<void()> Func;
public:
    FunctorTable();

    // 注册一个可调用对象，由 type 索引它
    void Register(int type, Func func);

    // 调用一个由 type 索引的可调用对象
    void Call(int type);

private:
    // no copy
    FunctorTable(const FunctorTable&) = delete;
    FunctorTable& operator=(const FunctorTable&) = delete;

    std::unordered_map<int, Func> m_funcs;
};

#endif // FUNCTOR_TABLE_HPP

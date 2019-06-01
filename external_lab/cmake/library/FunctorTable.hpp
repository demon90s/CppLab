#ifndef FUNCTOR_TABLE_HPP
#define FUNCTOR_TABLE_HPP

#include <unordered_map>
#include <functional>

/*
 * �򵥵غ���������һ������������һ���ɵ��ö���
 */

class FunctorTable
{
    typedef std::function<void()> Func;
public:
    FunctorTable();

    // ע��һ���ɵ��ö����� type ������
    void Register(int type, Func func);

    // ����һ���� type �����Ŀɵ��ö���
    void Call(int type);

private:
    // no copy
    FunctorTable(const FunctorTable&) = delete;
    FunctorTable& operator=(const FunctorTable&) = delete;

    std::unordered_map<int, Func> m_funcs;
};

#endif // FUNCTOR_TABLE_HPP

#include "ObjFuncInvoker.hpp"
#include <iostream>

class Foo
{
public:
    Foo() :
        m_func_invoker(this)
    {
        m_func_invoker.Register(&Foo::Test);
        m_func_invoker.Register(&Foo::Test);
        m_func_invoker.Register(&Foo::Test);
    }

    void Test()
    {
        std::cout << "Test Invoked\n";
    }

    void Check()
    {
        m_func_invoker.Invoke();
    }

private:
    ObjFuncInvoker<Foo> m_func_invoker;
};

/*
int main()
{
    Foo foo;

    foo.Check();
}
*/
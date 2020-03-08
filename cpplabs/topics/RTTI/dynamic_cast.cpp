#include <iostream>
#include <string>
#include <cassert>

class Base
{
public:
    virtual ~Base() {}
};

class D1 : public Base
{
public:
    std::string m_name = "D1";
};

class D2 : public Base
{
public:
    std::string m_name = "D2";
};

int main()
{
    Base *d1 = new D1();
    Base *d2 = new D2();

    // 向下转换成功，返回真实地址
    D1 *d = dynamic_cast<D1*>(d1);
    assert(d != 0);
    assert(d->m_name == "D1");

    // 向下转换失败，返回0
    d = dynamic_cast<D1*>(d2);
    assert(d == 0);

    // 对引用进行向下转换，失败抛出 bad_cast 异常
    D1 &rd = dynamic_cast<D1&>(*d1);
    assert(rd.m_name == "D1");

    bool catched = false;
    try { D1 &rd2 = dynamic_cast<D1&>(*d2); 
    }
    catch (std::bad_cast e) {
        catched = true;
    }
    assert(catched);

    delete d1;
    delete d2;

    std::cout << "[TEST] dynamic_cast PASS\n";
}
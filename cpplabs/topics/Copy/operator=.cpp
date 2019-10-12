/*
    处理自赋值时要面对的两个问题：
    1. 异常安全
    2. 资源管理

    在代码实现层面，解决了异常安全可能也顺带解决了资源管理。
*/

#include <iostream>
#include <string>

class Widget
{
public:
    Widget(std::string s) : m_ps(new std::string(s)) {}
    ~Widget() { delete m_ps; }
    Widget(const Widget& rhs) : m_ps(new std::string(*rhs.m_ps)) {}

    Widget& operator=(const Widget &rhs)
    {
        auto tmp = m_ps;
        m_ps = new std::string(*rhs.m_ps);
        delete tmp;
        return *this;
    }

    std::string GetS() const { return *m_ps; }

private:
    std::string *m_ps;
};

int main()
{
    Widget w1("hello");
    Widget w2("world");

    w2 = w1;
    w1 = w1;

    std::cout << w2.GetS() << std::endl;    // hello
    std::cout << w1.GetS() << std::endl;    // hello

    return 0;
}
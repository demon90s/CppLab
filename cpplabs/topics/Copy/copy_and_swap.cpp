/*
    copy and swap 技术可以用来解决自赋值问题
*/

#include <iostream>
#include <string>

class Widget
{
public:
    Widget(std::string s) : m_ps(new std::string(s)) {}
    ~Widget() { delete m_ps; }
    Widget(const Widget& rhs) : m_ps(new std::string(*rhs.m_ps)) {}

    void swap(Widget &rhs)
    {
        std::swap(m_ps, rhs.m_ps);
    }

    Widget& operator=(const Widget &rhs)
    {
        auto tmp = rhs;
        this->swap(tmp);
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
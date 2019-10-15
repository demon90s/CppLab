/*
    万能引用，即在模板函数中使用的可以表示任何类型的类型 T&&
    完美转发，将万能引用参数转发给另一个函数，保持其类型
*/

#include <iostream>

class Bar
{
public:
    Bar(int v) : m_v(new int(v)) {}
    ~Bar() { delete m_v; }
    Bar(const Bar&) = delete;
    Bar& operator=(const Bar&) = delete;

    int GetV() const { return *m_v; }

private:
    int *m_v;
};

void foo(Bar &&b)
{
    std::cout << b.GetV() << std::endl;
}

template<typename T>
void relay(T &&v)
{
    foo(std::forward<T>(v));
}

int main()
{
    relay(Bar(100));    // 100, 未经拷贝转发到底 relay -> foo

    return 0;
}
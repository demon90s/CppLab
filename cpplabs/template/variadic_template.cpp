// 可变参数模板
// 例子中的 Args 代表一个模板参数**包**

#include <iostream>

template<typename T>
void print(const T &v)
{
    std::cout << v << std::endl;
}

template<typename T, typename... Args>
void print(const T &v, const Args&... args)
{
    std::cout << v << std::endl;
    print(args...);
}

int main()
{
    print(42, 3.14, "hello");
}
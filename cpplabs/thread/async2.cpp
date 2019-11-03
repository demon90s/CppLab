#include <future>
#include <iostream>

int factorial(int n)
{
    std::cout << "factorial called, n: " << n << std::endl;
    int res = 1;
    for (int i = n; i >= 1; i--)
    {
        res *= i;
    }
    return res;
}

int main()
{
    int n;

    // deferred, 则直到调用 get 才会启动函数，等同于同步调用
    /*
    std::future<int> fu = std::async(std::launch::deferred, factorial, std::ref(n));
    std::cout << "enter n: ";
    std::cin >> n;
    std::cout << fu.get() << std::endl;
    */

    // async，异步调用，启动线程
    std::future<int> fu = std::async(std::launch::async, factorial, n = 4);
    std::cout << fu.get() << std::endl;

    return 0;
}
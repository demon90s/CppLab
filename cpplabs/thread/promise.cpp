/*
    #include <future>

    可以传递一个future给一个asyn callable object
*/

#include <future>
#include <iostream>

int factorial(std::future<int> &f)
{
    int n = f.get();

    int res = 1;
    for (int i = n; i >= 1; i--)
    {
        res *= i;
    }

    return res;
}

int main()
{
    std::promise<int> p;
    std::future<int> f = p.get_future();
    std::future<int> fu = std::async(factorial, std::ref(f));

    std::cout << "enter n: ";
    int n;
    std::cin >> n;

    p.set_value(n);
    std::cout << fu.get() << std::endl;

    return 0;
}
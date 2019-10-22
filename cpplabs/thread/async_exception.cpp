/*
    后台操作会因异常而终止，但它不会在此线程被处理，
    而是会再次被传播出去。

    当调用 get 时就会再次抛出它。
*/

#include <iostream>
#include <future>
#include <vector>

// 此后台程序迟早会抛出一个异常
void task1()
{
    std::vector<int> ivec;
    while (true)
    {
        for (int i = 0; i < 1000000; i++)
            ivec.push_back(0);

        std::cout.put('.').flush();
    }
}

int main()
{
    auto f = std::async(task1);

    std::cout << "enter some character: ";
    std::cin.get();

    try
    {
        f.get();
    }
    catch (const std::exception &e)
    {
        std::cerr << "catch exception: " << e.what() << std::endl;
    }

    return 0;
}
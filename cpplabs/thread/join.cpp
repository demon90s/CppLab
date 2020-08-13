/*
    join 一个线程
    也就是等待线程执行完毕。
*/

#include <thread>
#include <iostream>

void test_join()
{
    std::thread t([](){ std::cout << "thread start." << std::endl; });

    t.join();
    // 不能对已经 join 的线程再次 join，此行为将引发异常
    //t.join();

    // 可以先判断是否能join，再选择 join
    if (t.joinable())
    {
        t.join();
    }
}

int main()
{
    test_join();
}

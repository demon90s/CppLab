#include <atomic>
#include <iostream>
#include <thread>
#include <cassert>

void simple_test_atomic()
{
    std::atomic<int> cnt(0);

    auto f = [&cnt]() { cnt++; };

    std::thread t1(f), t2(f), t3(f);

    // ok, 不会有数据竞争问题

    t1.join();
    t2.join();
    t3.join();

    assert(cnt == 3);
}

int main()
{
    simple_test_atomic();
}
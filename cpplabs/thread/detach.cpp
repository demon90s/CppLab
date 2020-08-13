// detach 分离执行线程
// 前提是执行线程是 joinable 的 ，否则会有异常抛出

#include <iostream>
#include <thread>
#include <chrono>



int main()
{
    // 启动一个线程
    {
        std::thread t([]() {

            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "thread start." << std::endl;

            // sleep thread for 5 seconds
            std::this_thread::sleep_for(std::chrono::seconds(5));

            // 下面这句话执行不到了
            std::cout << "thread end." << std::endl;
        });

        // 分离线程
        std::cout << "before detach, thread joinable? " << t.joinable() << std::endl;
        t.detach();
        std::cout << "after detach, thread joinable? " << t.joinable() << std::endl;
    }

    // 主线程只 sleep 2秒，然后退出
    std::this_thread::sleep_for(std::chrono::seconds(2));
}
/*
    #include <mutex>
    class mutex;

    互斥琐

    lock 加锁
    unlock 解锁
    trylock 尝试加锁
*/
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <list>
#include <string>

std::mutex output_lock;

void sync_output(const char *msg)
{
	output_lock.lock();
	std::cout << msg << std::endl;
	output_lock.unlock();
}

int main()
{
	// 同步输出
	std::thread t1([]() { sync_output("t1 output test"); });
	std::thread t2([]() { sync_output("t2 output test"); });

	// 非同步输出，输出就很乱
	//std::thread t1([]() { std::cout << "t1 output test" << std::endl; });
	//std::thread t2([]() { std::cout << "t2 output test" << std::endl; });

	t1.join();
	t2.join();
}

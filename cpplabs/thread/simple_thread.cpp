// 一个最简单的 thread

// 对一个 thread 对象，只能执行一次 join 或 detach

// 可以使用 thread::joinable 可以判断是否可以 join

/*
	构造完毕线程立刻开始执行。线程函数可以是一个可调用对象。
	若不能开始线程，则抛出 std::system_error 
*/

#include <iostream>
#include <thread>

void thread_func()
{
	std::cout << "thread function begin" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "thread function end" << std::endl;
}

// join
void test_join()
{
	std::thread t(thread_func); // t starts running

	t.join(); // main thread waits for t to finish

	std::cout << "main thread end" << std::endl;
	return;
}

// detach
void test_detach()
{
	std::thread t(thread_func); // t starts running

	t.detach(); // t will freely on its own, once detached, forever detached -- becomes a deamon process
	std::cout << "main thread: thread detached" << std::endl;

	std::cout << "main thread end, sleeping 3 second" << std::endl;

	std::this_thread::sleep_for(std::chrono::seconds(3));
	return;
}

// functor thread
void test_functor()
{
	auto work_thread = [](std::string msg) {
		std::cout << "thread run: " << msg << std::endl;	
	};

	std::thread t(work_thread, "test functor");

	t.join();
}

int main()
{
	//test_join();
	//test_detach();
	test_functor();

	return 0;
}

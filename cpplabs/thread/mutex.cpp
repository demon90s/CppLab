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

template<typename T>
class JobQueue {
public:
	JobQueue() {}

	int Size() {
		m_lock.lock();
		int sz = (int)m_q.size();
		m_lock.unlock();
		return sz;
	}

	void Push(const T &v) {
		m_lock.lock();
		m_q.push_back(v);
		m_lock.unlock();
	}

	T Pop() {
		m_lock.lock();
		T v = m_q.front();
		m_q.pop_front();
		m_lock.unlock();
		return v;
	}

private:
	JobQueue(const JobQueue&) = delete;
	JobQueue& operator=(const JobQueue&) = delete;

	std::mutex m_lock;
	std::list<T> m_q;
};

class Job {
public:
	Job(std::string name) : m_name(name) {}

	void Invoke() {
		std::cout << "do job " << m_name << "\n";
	}

private:
	std::string m_name;
};

bool run = false;
void work_thread(JobQueue<Job> *jq) {
	while (run) {
		if (jq->Size() > 0) {
			// do IO in this thread
			Job j = jq->Pop();
			j.Invoke();

			std::this_thread::sleep_for(std::chrono::milliseconds(300));
		}
	}
}

int main()
{
	JobQueue<Job> jq;

	run = true;
	std::thread t(work_thread, &jq);

	// business
	for (int i = 0; i < 5; i++)
	{
		std::string name = "job" + std::to_string(i + 1);
		Job j(name);
		jq.Push(j);
	}

	std::this_thread::sleep_for(std::chrono::seconds(5));
	run = false;

	t.join();

	return 0;
}

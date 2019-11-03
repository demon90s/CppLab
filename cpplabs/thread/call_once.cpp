/*
    #include <mutex>

    保证只有一个线程执行一次可调用对象。
*/

#include <mutex>
#include <iostream>
#include <fstream>
#include <thread>

class FileLogger
{
public:
    void Write(const std::string &msg)
    {
        std::call_once(m_open_flag, [this]() { m_ofs.open("log.txt"); });
        {
            std::lock_guard<std::mutex> lck(m_mtx);
            m_ofs << msg << "\n";
        }
    }

private:
    std::once_flag m_open_flag;
    std::mutex m_mtx;
    std::ofstream m_ofs;
};

int main()
{
    FileLogger fl;

    // spawn 10 thread
    std::thread t_list[10];
    for (size_t i = 0; i < std::size(t_list); i++)
    {
        t_list[i] = std::thread([&fl, i]() { fl.Write("Hello " + std::to_string(i)); });
    }

    for (auto &t : t_list)
    {
        t.join();
    }

    return 0;
}

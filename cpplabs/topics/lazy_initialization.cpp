/*
    有时候，在创建一个实例的时候，不需要初始化某些资源。

    因为可能之后一直不使用，创建的必要性不大。

    而是在使用的时候，判断是否需要初始化，这就叫 Lazy initialization
*/

#include <fstream>
#include <string>

class FileLogger
{
public:
    FileLogger()
    {
    }

    void Write(const std::string &msg)
    {
        if (!m_fs.is_open())
        {
            m_fs.open("./log.txt");
        }

        if (m_fs.is_open())
        {
            m_fs << msg << "\n";
        }
    }

private:
    std::ofstream m_fs;
};

int main()
{
    FileLogger fl;
    fl.Write("hello");
    fl.Write("world");
    
    return 0;
}
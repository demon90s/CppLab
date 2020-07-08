#include <string>
#include <chrono>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

class BenchMark
{
public:
    BenchMark(const char *_test) : test(_test)
    {
        beg = std::chrono::steady_clock::now();
    }

    ~BenchMark()
    {
        auto end = std::chrono::steady_clock::now();

        auto dur = end - beg;

        std::cout << test << ", cose time: " << std::chrono::duration_cast<std::chrono::microseconds>(dur).count() / 1000.0 << " ms\n";
    }

private:
    std::chrono::steady_clock::time_point beg;
    std::string test;
};

void Insert_test()
{
    static const int TIMES = 1000000;

    {
        BenchMark bm("Insert_test - vector::push_back");

        std::vector<int> con;
        for (int i = 0; i < TIMES; i++)
        {
            con.push_back(i);
        }
    }

    {
        BenchMark bm("Insert_test - list::push_back");

        std::list<int> cond;
        for (int i = 0; i < TIMES; i++)
        {
            cond.push_back(i);
        }
    }

    {
        BenchMark bm("Insert_test - set::insert");

        std::set<int> cond;
        for (int i = 0; i < TIMES; i++)
        {
            cond.insert(i);
        }
    }

    {
        BenchMark bm("Insert_test - unordered_set::insert");

        std::unordered_set<int> cond;
        for (int i = 0; i < TIMES; i++)
        {
            cond.insert(i);
        }
    }
}

int main()
{
    Insert_test();
}
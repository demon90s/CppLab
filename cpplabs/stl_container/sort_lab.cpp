#include <vector>
#include <list>
#include <set>
#include <iostream>
#include <chrono>
#include <string>
#include <algorithm>
#include <cstdlib>

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

int main()
{
    // 实验表明：std::sort 要快很多 set最慢

    // 1 gen million random num
    std::vector<int> pool;
    for (int i = 0; i < 1000000; i++)
    {
        pool.push_back(rand());
    }

    // vector sort
    {
        std::vector<int> vec(pool);

        BenchMark bm("vector sort");

        //std::sort(vec.begin(), vec.end());
        std::stable_sort(vec.begin(), vec.end());
    }

    // set sort 1
    {
        BenchMark bm("set sort 1");

        std::set<int> s(pool.begin(), pool.end());
    }

    // set sort 2
    {
        std::set<int> s;
        BenchMark bm("set sort 2");

        for (int i : pool)
        {
            s.insert(i);
        }
    }

    // list sort
    {
        std::list<int> l(pool.begin(), pool.end());

        BenchMark bm("list sort");

        l.sort();
    }
}

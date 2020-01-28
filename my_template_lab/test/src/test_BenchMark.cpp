#include "../library/BenchMarking.hpp"

/*
int main()
{
    int v = 0;
    {
        //BenchMarking<std::chrono::microseconds> bm;
        BenchMarking<> bm([](std::size_t dur_ms) { std::cout << "BenchMarking finish, duration: " << dur_ms / 1000.0 << " s\n"; });
        for (int i = 0; i < 100000; i++)
        {
            v += i;
        }

        for (int i = 0; i < 1000; i++)
        {
            FILE *fp = tmpfile();
            fprintf(fp, "hello");
            fclose(fp);
        }
    }

    std::cout << v << std::endl;
}
*/
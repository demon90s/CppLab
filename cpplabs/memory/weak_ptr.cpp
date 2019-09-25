/*
    #include <memory>
    weak_ptr
    类似Raw Pointer, 但有了更安全的保护机制。它指向一个shared_ptr。
*/

#include <iostream>
#include <memory>
#include <string>

int main()
{
    std::weak_ptr<std::string> wsp;

    {
        std::shared_ptr<std::string> sp = std::make_shared<std::string>("Hello"); 

        wsp = sp;

        if (!wsp.expired())
        {
            std::cout << *wsp.lock() << std::endl;  // Hello
        }
    }

    std::cout << wsp.use_count() << std::endl;      // 0

    return 0;
}
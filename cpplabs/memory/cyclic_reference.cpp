/*
    cyclic reference
    循环引用，使用智能指针也可以引发的内存泄露
*/

#include <iostream>
#include <memory>
#include <string>

class Dog {
    std::string m_name;
    std::shared_ptr<Dog> m_friend;  // 可能造成循环引用

    std::weak_ptr<Dog> m_friend_fix;    // 解决方案，使用 weak_ptr
public:
    Dog(std::string name) : m_name(name) { std::cout << m_name << " created\n"; }
    ~Dog() { std::cout << m_name << " destroyed\n"; }

    void MakeFriend(std::shared_ptr<Dog> dog) 
    //{ m_friend = dog; }
    { m_friend_fix = dog; }
};

int main()
{
    {
        std::shared_ptr<Dog> d1 = std::make_shared<Dog>("Kitty");
        std::shared_ptr<Dog> d2 = std::make_shared<Dog>("Funny");

        d1->MakeFriend(d2);
        d2->MakeFriend(d1);
    }

    // memory leak:
    // 1. d2 release, ref -> 1
    // 2. d2(Dog) not release

    // solution: use weakptr or do not use self share_ptr

    return 0;
}

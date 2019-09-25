/*
    #include <memory>

    static_pointer_cast
    dynamic_pointer_cast
    const_pointer_cast

    用于转换智能指针（向下转换），其由 static_cast, dynamic_cast, const_cast 实现。
*/

#include <iostream>
#include <memory>

class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {
public:
    void f() const {
        std::cout << "Derived\n";
    }
};

int main()
{
    std::shared_ptr<Base> pb = std::make_shared<Derived>();

    auto pd = std::static_pointer_cast<Derived>(pb);

    pd->f();

    return 0;
}
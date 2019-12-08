#include <string>
#include <iostream>

// recursive inheritance
template<typename... Args> class Tuple;

template<>
class Tuple<>
{};

template<typename Head, typename... Tail>
class Tuple<Head, Tail...>
: private Tuple<Tail...>
{
    typedef Tuple<Tail...> inherited;

public:
    Tuple() {}
    Tuple(Head v, Tail... vtail)
        : m_head(v), inherited(vtail...) {}

    Head head() { return m_head; }
    
    inherited& tail() { return *this; }

protected:
    Head m_head;
};

int main()
{
    // 继承层级
    // Tuple<>
    // Tuple<std::string>
    // Tuple<double, std::string>
    // Tuple<int, double, std::string>
    Tuple<int, double, std::string> t(42, 3.14, "hello");

    std::cout << t.head() << std::endl;
    std::cout << t.tail().head() << std::endl;
    std::cout << t.tail().tail().head() << std::endl;
}

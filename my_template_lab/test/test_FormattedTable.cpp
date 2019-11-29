#include "../library/FormattedTable.hpp"
#include <iostream>

struct Position
{
    int x, y;
};

std::ostream& operator<<(std::ostream &os, const Position &position)
{
    os << position.x << " " << position.y;
    return os;
}

int main()
{
    std::string wen = "程";

    auto is_asc = [](const char *str) -> bool
    {
        return (str[0] & (1 << 8)) == 0;
    };

    std::cout << is_asc(wen.c_str()) << std::endl;
    std::cout << is_asc("333") << std::endl;

    printf("[%-*s]\n", 8, "文");
    printf("[%-*s]\n", 8, "wen");

    FormattedTable pt;

    pt.SetFieldList( { 
        "Name", "Age", "Prof", "Position"
    });

    pt.AddRow("diwen", 29, "Programmer", Position{30, 20});
    pt.AddRow("帝文", 29, "程序员哈哈哈啊哈哈哈哈和", Position{30, 20});
    pt.AddRow("lee", 32, "Product", Position{10, 10});

    std::cout << pt.GetFormattedTable() << std::endl;

    pt.SetFieldList({
        "ID", "Country", "Power"
    });

    pt.AddRow("1", "China", "1000");
    pt.AddRow("2", "USA", "111");

    std::cout << pt.GetFormattedTable() << std::endl;
}

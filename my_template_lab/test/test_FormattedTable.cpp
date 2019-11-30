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
    FormattedTable pt;

    pt.SetFieldList( { 
        "Name", "Age", "Prof", "Position"
    });

    pt.AddRow("diwen", 29, "Programmer", Position{30, 20});
    pt.AddRow("帝文orz```.我我", 29, "程", Position{30, 20});
    pt.AddRow("lee", 32, "Product", Position{10, 10});

    std::cout << pt.GetFormattedTable() << std::endl;

    pt.SetFieldList({
        "ID", "Country", "Power"
    });

    pt.AddRow("1", "China", "1000");
    pt.AddRow("2", "USA", "111");

    std::cout << pt.GetFormattedTable() << std::endl;
}

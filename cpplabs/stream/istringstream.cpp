#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	istringstream iss("abc");
	char c;
	iss >> c;

	cout << c << endl;		// a

	iss >> c;
	cout << c << endl;		// b

	return 0;
}

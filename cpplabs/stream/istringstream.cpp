#include <iostream>
#include <sstream>
#include <cassert>

using namespace std;

int main()
{
	istringstream iss("abc");
	char c;
	iss >> c;

	assert(c == 'a');

	iss >> c;
	assert(c == 'b');

	iss >> c;
	assert(iss);
	assert(c == 'c');
	
	iss >> c;	// opera fail
	assert(!iss);
	assert(c == 'c');

	std::cout << "[TEST] istringstream PASS\n";

	return 0;
}

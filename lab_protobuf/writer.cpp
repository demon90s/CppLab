#include <fstream>
#include "hello.pb.h"

using namespace std;

int main()
{
	hello::Test msg1;
	msg1.set_id(101);
	msg1.set_str("Hello");

	// Write the new address book back to disk.
	fstream output("./log", ios::out | ios::trunc | ios::binary);

	if (!msg1.SerializeToOstream(&output))
	{
		cerr << "Failed to write msg." << endl;
		return -1;
	}

	return 0;
}

#include <fstream>
#include <sys/shm.h>
#include "common.h"
#include "hello.pb.h"

using namespace std;

void ListMsg(const hello::Test &msg)
{
	cout << "id:\t" << msg.id() << endl;
	cout << "str:\t" << msg.str() << endl;

	cout << "arr:\t";
	for (int i = 0; i < msg.arr_size(); i++)
	{
		cout << msg.arr(i) << " ";
	}
	cout << "\n";

	cout << "p.n:\t" << msg.p().n() << endl;
	cout << "p.a:\t" << msg.p().a() << endl;
	cout << "p.s:\t";
	for (int i = 0; i < msg.p().s_size(); i++)
	{
		cout << msg.p().s(i) << " ";
	}
	cout << "\n";

	cout << "opt:\t" << msg.opt() << endl;

	// 更多其他类型
	cout << "b:\t" << msg.b() << endl;
	cout << "d:\t" << msg.d() << endl;
	cout << "f:\t" << msg.f() << endl;

	// output with debug functions, only print setted fields
	cout << "------------------------------------\n";
	cout << msg.DebugString();
}

// 从文件中反序列化出来
void ParseFromIstream(hello::Test &msg)
{
	fstream input("./log", ios::in | ios::binary);
	if (!msg.ParseFromIstream(&input))
	{
		cerr << "Failed to parse address book." << endl;
		exit(1);
	}
}

// 从buffer中反序列化出来
void ParseFromBuffer(hello::Test &msg)
{
	struct SharedBlock sb;
	int read_len = 0;

	{
		// 从共享内存中读出数据
		int shm_id;
		shm_id = shmget(SHM_KEY, sizeof(struct SharedBlock), 0666);
		if (shm_id == -1) {
			fprintf(stderr, "shmget failed\n");
			exit(1);
		}

		void* shm_ptr;
		shm_ptr = shmat(shm_id, NULL, SHM_RDONLY);
		if (shm_ptr == (void*)-1) {
			fprintf(stderr, "shmat failed\n");
			exit(1);
		}

		struct SharedBlock *sb_ptr = (struct SharedBlock*)shm_ptr;
		read_len = sb_ptr->len;
		memcpy(sb.data, sb_ptr->data, sb_ptr->len);
	}

	if (!msg.ParseFromArray(sb.data, read_len))
	{
		cerr << "Failed to parse address book from buffer." << endl;
		exit(1);
	}
}

int main()
{
	hello::Test msg;

	//ParseFromIstream(msg);
	ParseFromBuffer(msg);

	ListMsg(msg);

	return 0;
}

#include <fstream>
#include <sys/shm.h>
#include "common.h"
#include "hello.pb.h"

using namespace std;

// 序列化到文件
void SerializeToFile(const hello::Test &msg)
{
	// Write the new address book back to disk.
	fstream output("./log", ios::out | ios::trunc | ios::binary);

	if (!msg.SerializeToOstream(&output))
	{
		cerr << "Failed to write msg." << endl;
		exit(1);
	}
}

// 序列化到buffer
void SerializeToBuffer(const hello::Test &msg)
{
	int write_len = static_cast<int>(msg.ByteSizeLong());
	assert(write_len <= SHM_BLOCK_LEN);

	struct SharedBlock sb;
	memset(&sb, 0, sizeof(sb));
	if (!msg.SerializeToArray(sb.data, write_len))
	{
		cerr << "Failed to write msg to buffer." << endl;
		exit(1);
	}

	// 写入共享内存, 供reader读取测试
	{
		int shm_id;
		shm_id = shmget(SHM_KEY, sizeof(struct SharedBlock), 0666 | IPC_CREAT);
		if (shm_id == -1)
		{
			cerr << "shmget failed\n";
			exit(1);
		}

		void *shm_ptr;
		struct SharedBlock *sb_ptr;
		shm_ptr = shmat(shm_id, NULL, 0);
		if (shm_ptr == (void*)-1)
		{
			cerr << "shmat failed\n";
			exit(1);
		}
		sb_ptr = (struct SharedBlock*)shm_ptr;

		sb_ptr->len = write_len;
		memcpy(sb_ptr->data, sb.data, write_len);
	}
}

int main()
{
	hello::Test msg;
	msg.set_id(101);
	msg.set_str("Hello");

	{
		hello::Test_Person *p = new hello::Test_Person;	
		p->add_s(42);
		p->add_s(100);
		p->add_s(33);
		msg.set_allocated_p(p);	// after this, no need to delete
	}

	/*
	msg.set_opt(hello::Test::Add);
	msg.set_b(true);
	msg.set_d(3.14);
	msg.set_f(9.8);
	*/

	//SerializeToFile(msg);
	SerializeToBuffer(msg);

	return 0;
}

#include <cassert>
#include <iostream>
#include <cstdio>
#include <leveldb/db.h>
#include <leveldb/write_batch.h>

leveldb::DB* open_db()
{
	leveldb::DB* db;
	leveldb::Options options;
	options.create_if_missing = true;
	leveldb::Status status = leveldb::DB::Open(options, "./testdb", &db);
	assert(status.ok());

	return db;
}

void close_db(leveldb::DB *db)
{
	delete db;
}

// 写key-value
void Put_test(leveldb::DB *db)
{
	std::string key = "name";
	std::string value = "diwen";

	leveldb::Status s = db->Put(leveldb::WriteOptions(), key, value);
	if (!s.ok())
		std::cerr << "Put key-value failed\n";
}

// 读key-value
void Get_test(leveldb::DB *db)
{
	std::string key = "name";
	std::string value;

	leveldb::Status s = db->Get(leveldb::ReadOptions(), key, &value);
	if (!s.ok()) {
		std::cerr << "Get key-value failed\n";
		return;
	}

	printf("Get key-value: [%s]-[%s]\n", key.c_str(), value.c_str());
}

// 删除key-value
void Delete_test(leveldb::DB *db)
{
	std::string value;
	leveldb::Status s = db->Delete(leveldb::WriteOptions(), "name");
	if (s.ok())
		std::cout << "Delete key-value succ\n";
}

// 批量更新（原子操作，效率up）
void AtomicUpdates_test(leveldb::DB *db)
{
	std::string value;
	leveldb::Status s = db->Get(leveldb::ReadOptions(), "name", &value);
	if (s.ok())
	{
		leveldb::WriteBatch batch;
		batch.Delete("name");
		batch.Put("name", "miemie");
		s = db->Write(leveldb::WriteOptions(), &batch);
	}
}

// sync write
// 默认情况，写入操作是异步的，可以通过修改option将其改成同步
// 数据持久化，效率远低于异步
void SyncWrite_example(leveldb::DB *db)
{
	std::string key = "name";
	std::string value = "diwen";

	leveldb::WriteOptions wo;
	wo.sync = true;

	leveldb::Status s = db->Put(wo, key, value);
	if (!s.ok())
		std::cerr << "Sync Put key-value failed\n";
}

// Iteration
// 注意，文档中说这个操作非线程安全
void Iterator_example(leveldb::DB *db)
{
	std::cout << "Iterator_example: \n";

	leveldb::Iterator* it = db->NewIterator(leveldb::ReadOptions());

	for (it->SeekToFirst(); it->Valid(); it->Next())
	{
		std::cout << it->key().ToString() << ": " << it->value().ToString() << std::endl;
	}

	assert(it->status().ok());	// Check for any errors found during the scan
	delete it;
}

int main()
{
	leveldb::DB* db = open_db();

	//Put_test(db);
	SyncWrite_example(db);

	Get_test(db);

	//Delete_test(db); Get_test(db);

	AtomicUpdates_test(db); Get_test(db);

	Iterator_example(db);

	close_db(db);

	std::cout << "Done.\n";

	return 0;
}

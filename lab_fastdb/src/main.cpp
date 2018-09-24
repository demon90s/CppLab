#include <stdlib.h>
#include <iostream>
#include "fastdb/database.h"

static bool open_log = true;

static fastdb::dbDatabase db;
static fastdb::dbDatabase::OpenParameters open_params;
static std::string db_name = "test_fastdb";
static size_t db_init_sz_mb = 1;

#define Log(format, ...) \
if (open_log) printf(format "\n", ##__VA_ARGS__); fflush(stdout);

static bool OpenDB()
{
	if (db.isOpen())
	{
		Log("fastdb already open");
		return false;
	}

	open_params.databaseName = (db_name + ".dbs").c_str();
	open_params.initSize = db_init_sz_mb * 1024 * 1024;

	bool ret = db.open(open_params);
	if (ret)
	{
		Log("open fastdb succ");
	}
	else
	{
		Log("open fastdb failure");
	}

	return ret;
}

static void CloseDB()
{
	if (db.isOpen())
	{
		db.close();
		Log("fastdb closed");
	}
}

int main()
{
	OpenDB();

	CloseDB();

#ifdef _MSC_VER
	system("pause");
#endif

	return 0;
}
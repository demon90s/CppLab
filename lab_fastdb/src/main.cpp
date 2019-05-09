#include <stdlib.h>
#include <iostream>
#include "fastdb/database.h"
#include "tabledef.h"

USE_FASTDB_NAMESPACE

static bool open_log = true;

static dbDatabase db;
static dbDatabase::OpenParameters open_params;
static std::string db_name = "test_fastdb";
static size_t db_init_sz_mb = 1;

#define Log(format, ...) \
if (open_log) printf(format "\n", ##__VA_ARGS__); fflush(stdout);

// ���� fastdb
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

// �ر� fastdb
static void CloseDB()
{
	if (db.isOpen())
	{
		db.close();
		Log("fastdb closed");
	}
}

// ����һ����¼
static void InsertRecord()
{
	table_test table;
	{
		static int inc_id = 1;

		table.inc_id = inc_id++;
		table.name = "liudiwen";
		table.number_char = 127;
		table.number_int = 42;
		table.number_ll = 100000;
	}

	dbAnyReference ref;
	db.insertRecord(&table_test::dbDescriptor, &ref, &table);

	Log("Insert one record");
}

// ���Ҽ�¼
static void Find()
{
	dbQuery dbquery;
	{
		dbquery.And("name");
		dbquery.append(dbQueryElement::qExpression, "=");
		dbquery.add("liudiwen");
	}
	dbCursorType type = dbCursorViewOnly;

	dbCursor<table_test> cursor(&db);
	int n = cursor.select(dbquery, type);
	if (n > 0)
	{
		Log("Find result count : %d", n);

		for (int i = 0; i < n; ++i)
		{
			auto record = cursor.get();
            Log("record %d info: inc_id[%d], name[%s], number_char[%d], number_int[%d], number_ll[%ld]", i + 1,
				record->inc_id, record->name, record->number_char, record->number_int, record->number_ll);

			cursor.next();
		}
	}
	else
	{
		Log("Find no result");
	}
}

// ɾ����¼
static void Remove()
{
	dbQuery dbquery;
	{
		dbquery.And("name");
		dbquery.append(dbQueryElement::qExpression, "=");
		dbquery.add("liudiwen");
	}
	dbCursorType type = dbCursorForUpdate;

	dbCursor<table_test> cursor(&db);
	int n = cursor.select(dbquery, type);

	cursor.removeAllSelected();
	Log("Removed %d record", n);
}

// ���¼�¼
static void Update()
{
	dbQuery dbquery;
	{
		dbquery.And("name");
		dbquery.append(dbQueryElement::qExpression, "=");
		dbquery.add("liudiwen");
	}
	dbCursorType type = dbCursorForUpdate;

	dbCursor<table_test> cursor(&db);
	int n = cursor.select(dbquery, type);
	if (n == 0)
	{
		Log("No record to Update");
		return;
	}

	do 
	{
		auto record = cursor.get();
		record->number_char = 0;
		record->number_int = 0;
		record->number_ll = 0;

		cursor.update();

	} while (cursor.next());

	Log("Updated %d records", n);
}

int main()
{
    if (!OpenDB())
    {
        return 1;
    }

	InsertRecord();
	//InsertRecord();
	Find();
	Update();
	Find();
	Remove();

	CloseDB();

#ifdef _MSC_VER
	system("pause");
#endif

	return 0;
}

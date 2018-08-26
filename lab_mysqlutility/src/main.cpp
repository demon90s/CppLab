#include <iostream>
#include "mysqlutility.hpp"

TMysqlStatement mysql_st;
char error_msg[512] = {0};
int error_no = 0;

bool Connect()
{
	CMysqlUtility::Init(&mysql_st);

	const char* host = "127.0.0.1";
	const char* user_name = "root";
	const char* passwd = "123456";
	const char* dbname = "test_mysqlutility";

	int ret = CMysqlUtility::ConnectDB(&mysql_st, host, user_name, passwd, dbname, 3306, error_msg);
	if (ret != 0)
	{
		printf("[ERROR] ConnectDB failed: %s\n", error_msg);
		return false;
	}
	printf("[DEBUG] ConnectDB %s@%s succ\n", dbname, host);

	return true;
}

bool Select()
{
	enum field
	{
		number_char,
		number_int,
		number_ll,
		name,
		field_max,
	};
	const char* field_name[field_max] = {
		"number_char",
		"number_int",
		"number_ll",
		"name",
	};

	mysql_st.iQueryType = SQL_TYPE_SELECT;
	snprintf(mysql_st.szSQLString, sizeof(mysql_st.szSQLString),
		"SELECT `%s`, `%s`, `%s`, `%s` FROM `test`",
		field_name[number_char], field_name[number_int], field_name[number_ll], field_name[name]);

	int ret = CMysqlUtility::ExecSelect(&mysql_st, &error_no, error_msg);
	if (0 != ret)
	{
		CMysqlUtility::FreeResult(&mysql_st);

		printf("[ERROR] ExecSelect failed(%d): %s\n", error_no, error_msg);
		return false;
	}
	printf("[ERROR] ExecSelect succ\n");

	int fetch_rows = mysql_st.iResNum;

	for (int i = 0; i < fetch_rows; ++i)
	{
		ret = CMysqlUtility::FetchRow(&mysql_st, error_msg);
		if (0 != ret)
		{
			printf("[ERROR] FetchRow failed: %s", error_msg);
			break;
		}

		char v_number_char = 0;
		int v_number_int = 0;
		long long v_number_ll = 0;
		std::string v_name;

		if (mysql_st.stRow[number_char])
		{
			v_number_char = (char)atoi(mysql_st.stRow[number_char]);
		}

		if (mysql_st.stRow[number_int])
		{
			v_number_int = atoi(mysql_st.stRow[number_int]);
		}

		if (mysql_st.stRow[number_ll])
		{
			v_number_ll = atoll(mysql_st.stRow[number_ll]);
		}

		if (mysql_st.stRow[name] && mysql_st.alFieldsLength[name] > 0)
		{
			v_name = mysql_st.stRow[name];
		}

		printf("[DEBUG] row: %d, number_char: %d, number_int: %d, number_ll: %lld, name: %s\n",
			i, v_number_char, v_number_int, v_number_ll, v_name.c_str());
	}

	CMysqlUtility::FreeResult(&mysql_st);

	return true;
}

int main()
{
	Connect() && Select();

	CMysqlUtility::CloseDatabase(&mysql_st);
	system("pause");
	return 0;
}
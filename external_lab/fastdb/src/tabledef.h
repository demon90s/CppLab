#pragma once

#include "fastdb/fastdb.h"
USE_FASTDB_NAMESPACE

class table_test
{
public:
	int4 inc_id;
	const char* name;
	int1 number_char;
	int4 number_int;
	int8 number_ll;

	TYPE_DESCRIPTOR((
		KEY(inc_id, INDEXED),
		KEY(name, INDEXED),
		FIELD(number_char),
		FIELD(number_int),
		FIELD(number_ll)
		));
};
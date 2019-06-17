#include <json/json.h>
#include <iostream>
#include <string>
#include <memory>
#include <cassert>

void write_example()
{
	Json::Value json_obj;
	json_obj["name"] = Json::Value("diwen");
	json_obj["age"] = Json::Value(29);

	Json::Value json_root;
	json_root["key_string"] = Json::Value("value_string");
	json_root["key_number"] = Json::Value(12345);
	json_root["key_boolean"] = Json::Value(false);
	json_root["key_double"] = Json::Value(3.14);
	json_root["key_obj"] = Json::Value(json_obj);
	json_root["key_array"].append("array_string");
	json_root["key_array"].append(1234);

	Json::StreamWriterBuilder builder;
	Json::StreamWriter *writer = builder.newStreamWriter();
	writer->write(json_root, &std::cout);
	delete writer;
}

void read_example()
{
	std::string str_test = R"(
{
	"id": 1,
	"name": "diwen"
}
	)";

	Json::CharReaderBuilder builder;
	std::unique_ptr<Json::CharReader> reader(builder.newCharReader());

	Json::Value root;
	std::string err;
	if (!reader->parse(&str_test[0], &str_test.back(), &root, &err))
	{
		std::cerr << "Parse error: " << err;
		return;
	}

	assert(root["id"].isInt() && root["name"].isString());

	std::cout << "id: " << root["id"].asInt() << std::endl;
	std::cout << "name: " << root["name"].asString() << std::endl;
}

int main()
{
	//write_example();

	read_example();

	return 0;
}

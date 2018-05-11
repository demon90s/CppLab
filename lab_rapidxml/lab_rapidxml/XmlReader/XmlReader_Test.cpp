#include "XmlReader.h"
#include <iostream>

void Test_XmlReader_GetValue1()
{
	XmlReader xml_reader("test.xml");

	const char *value = xml_reader.GetValue("config/name");
	if (value)
	{
		std::cout << value << std::endl;
	}
	else
	{
		std::cerr << "GetValue failed" << std::endl;
	}
}

void Test_XmlReader_GetValue2()
{
	XmlReader xml_reader("test.xml");
	std::vector<const char*> value_list;

	if (xml_reader.GetValue("config/reading/data", value_list))
	{
		for (auto value : value_list)
		{
			std::cout << value << std::endl;
		}
	}
	else
	{
		std::cerr << "GetValue failed" << std::endl;
	}
}
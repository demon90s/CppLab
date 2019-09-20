/*
	#include <string>
	std::string_view

	一个仿char对象的序列。

	NOTE: 只保存外部指针，需要确保外部数据的生命周期正确。
*/

#include <iostream>
#include <string>
#include <cstring>

void bad()
{
	char *arr = new char[10];
	strcpy(arr, "hello");

	std::string_view view(arr, strlen(arr));

	delete []arr;

	// bad, string has been deleted
	std::cout << view << std::endl;
}

void travel()
{
	std::string_view view("hello");

	for (auto it = view.cbegin(); it != view.cend(); ++it)
	{
		std::cout << std::distance(view.cbegin(), it) << ": " << *it << std::endl;
	}
}

int main()
{
	// copy constructor
	std::string_view view("hello world");
	std::cout << view << std::endl;	// hello world

	//bad();

	// operator=
	view = view.substr(0, 5);
	std::cout << view << std::endl;	// hello

	// operator[] const
	std::cout << view[0] << std::endl;	// h
	//view[0] = 'w';	// compile error, can NOT modify view

	// travel
	travel();

	// other string-like opera, substr, find, etc...

	return 0;
}

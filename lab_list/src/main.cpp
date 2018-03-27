#include <iostream>

#include "list.h"

int main()
{
	list_t *mylist = list_new();

	list_rpush(mylist, list_node_new("my value"));

	list_node *node;
	list_iterator_t *it = list_iterator_new(mylist, LIST_HEAD);
	while ((node = list_iterator_next(it))) {
		std::cout << (char*)node->val << std::endl;
	}

	list_iterator_destroy(it);
	list_destroy(mylist);

	system("pause");
	return 0;
}
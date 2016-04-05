#include <stdio.h>

#include "list.h"

int main() {
	struct node *list = list_create("1 hello world", TYPE_STR, 0);

	struct node *list1 = list_add(list, "2 good morning", TYPE_STR, 0);

	list1 = list_add(list1, "3 good morning", TYPE_STR, 0);

	list_add(list1, "4 good morning", TYPE_STR, 0);

	list_traverse(list);

	list = list_reverse(list);

	list_traverse(list);

	list_destroy(list);
	return 0;
}

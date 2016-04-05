#include <stdio.h>

#include "list.h"

int main() {
	struct list *list = list_create();
	list_append(list, "1 hello world", TYPE_STR, 0);
	list_append(list, "2 good morning", TYPE_STR, 0);
	list_append(list, "3 good morning", TYPE_STR, 0);
	list_append(list, "4 good morning", TYPE_STR, 0);
	list_traverse(list);

	list_reverse(list);

	list_traverse(list);

	list_destroy(list);
	return 0;
}

/* output:
node 1: 1 hello world
node 2: 2 good morning
node 3: 3 good morning
node 4: 4 good morning
node 1: 4 good morning
node 2: 3 good morning
node 3: 2 good morning
node 4: 1 hello world
*/

// gcc -g3 -std=c99 -pedantic -Wall list_test.c list.c

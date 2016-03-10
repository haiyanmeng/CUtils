#include <stdio.h>

#include "type_conv.h"
#include "hash_table.h"

int main(void) {
	HashTable ht = hash_table_create(4);

	printf("hash_table info: %zd %zd\n", hash_table_size(ht), hash_table_n(ht));
	hash_table_insert(ht, "abc", "ABC");
	hash_table_insert(ht, "abc1", "ABC1");
	hash_table_insert(ht, "abc2", "ABC2");
	hash_table_insert(ht, "cde", "CDE");
	hash_table_insert(ht, "cde2", "CDE2");
	printf("%s %zd %zd\n", hash_table_search(ht, "cde"), hash_table_size(ht), hash_table_n(ht));
	hash_table_delete(ht, "cde");
	printf("new value: %s %zd %zd\n", hash_table_search(ht, "cde"), hash_table_size(ht), hash_table_n(ht));
	printf("hash_table info: %zd %zd\n", hash_table_size(ht), hash_table_n(ht));

	hash_table_insert(ht, "cde2", "CDE2");
	int i;
	for(i=0; i<1000; i++) {
		hash_table_insert(ht, int_to_str(i), int_to_str(i));
	}
	printf("hash_table info: %zd %zd\n", hash_table_size(ht), hash_table_n(ht));

	hash_table_destroy(ht);
	return 0;
}

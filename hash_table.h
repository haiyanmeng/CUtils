#ifndef HASH_TABLE_H
#define HASH_TABLE_H

typedef struct hash_table *HashTable;

HashTable hash_table_create(size_t n);

int hash_table_insert(HashTable h, const char *key, const void *value);

int hash_table_delete(HashTable h, const char *key);

int hash_table_search(HashTable h, const char *key);

int hash_table_destroy(HashTable h);

#endif

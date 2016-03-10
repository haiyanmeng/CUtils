#ifndef HASH_TABLE_H
#define HASH_TABLE_H

typedef struct hash_table *HashTable;

HashTable hash_table_create(size_t n);

int hash_table_insert(HashTable ht, const char *key, const char *value);

int hash_table_delete(HashTable ht, const char *key);

const char *hash_table_search(HashTable ht, const char *key);

int hash_table_destroy(HashTable ht);

size_t hash_table_n(HashTable ht);

size_t hash_table_size(HashTable ht);

#endif


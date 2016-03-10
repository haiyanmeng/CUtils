#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hash_table.h"

#define MULTIPLIER (97)
#define INIT_HT_SIZE (1024)
#define MAX_LOAD_FACTOR (1)
#define HT_GROWTH_FACTOR (2)

struct elem {
	char *key;
	char *value;
	struct elem *next;
};

struct hash_table {
	size_t size;
	size_t n;
	struct elem **table;
};
	
static unsigned long hash_func(const char *s) {
	unsigned long r = 0;
	unsigned char *p;
	for(p=(unsigned char *)s; *p; p++) {
		r = r*MULTIPLIER + *p;
	}
	return r;
}

HashTable hash_table_create(size_t n) {
	HashTable ht = malloc(sizeof(struct hash_table));
	if(!ht) {
		fprintf(stderr, "Fails to create hash table!");
		exit(EXIT_FAILURE);
	}

	ht->size = n;
	ht->n = 0;
	ht->table = malloc(sizeof(struct elem *) * ht->size);
	if(!ht->table) {
		free(ht);
		fprintf(stderr, "Fails to create hash table!");
		exit(EXIT_FAILURE);
	}
	
	return ht;
}

static int hash_table_grow(HashTable ht) {
	size_t new_size = ht->size * HT_GROWTH_FACTOR;
	struct elem **new_table = malloc(sizeof(struct elem *) * new_size);
	int i;
	size_t new_h;
	struct elem *e, *next;

	for(i = 0; i < ht->size; i++) {
		for(e=ht->table[i]; e; e=next) {
			next = e->next;
			struct elem *new_e = malloc(sizeof(struct elem));
			new_e->key = e->key;
			new_e->value = e->value;
			new_h = hash_func(e->key) % new_size;
			new_e->next = new_table[new_h];
			new_table[new_h] = new_e;
		}
	}

	/* delete the old table without */
	for(i = 0; i<ht->size; i++) {
		for(e=ht->table[i]; e; e=next) {
			next = e->next;
			free(e);
		}
	}
	free(ht->table);

	ht->size = new_size;
	ht->table = new_table;
	return 0;
}

int hash_table_insert(HashTable ht, const char *key, const char *value) {
	size_t i = hash_func(key) % (ht->size);

	struct elem *e = malloc(sizeof(struct elem));;
	assert(e);

	e->key = (char *)key;
	e->value = (char *)value;
	e->next = ht->table[i];
	ht->table[i] = e;

	ht->n++;

	if(ht->n == ht->size * MAX_LOAD_FACTOR)
		hash_table_grow(ht);
	return 0;
}

int hash_table_destroy(HashTable ht) {
	int i;
	struct elem *e, *next;

	for(i = 0; i < ht->size; i++) {
		for(e=ht->table[i]; e; e=next) {
			next = e->next;
			free(e);
		}
	}

	free(ht->table);
	free(ht);	
	return 0;
}

int hash_table_delete(HashTable ht, const char *key) {
	size_t i = hash_func(key) % (ht->size);

	struct elem *prev = ht->table[i];
	struct elem *cur;

	if(!prev)
		return 0;

	if(!strcmp(prev->key, key)) {
		ht->table[i] = prev->next;
		free(prev);
		ht->n--;
		return 0;
	}

	for(cur=prev->next; cur; prev=cur) {
		if(!strcmp(cur->key, key)) {
			prev->next = cur->next;
			free(cur);
			ht->n--;
			return 0;
		}
	}

	return 0;
}

const char *hash_table_search(HashTable ht, const char *key) {
	size_t i = hash_func(key) % (ht->size);

	struct elem *e, *next;
	for(e=ht->table[i]; e; e=next) {
		next = e->next;
		if(!strcmp(e->key, key)) {
			return e->value;
		}
	}

	return NULL;
}

size_t hash_table_n(HashTable ht) {
	return ht->n;
}

size_t hash_table_size(HashTable ht) {
	return ht->size;
}

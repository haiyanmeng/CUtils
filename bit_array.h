#ifndef BIT_ARRAY_H
#define BIT_ARRAY

#include <stdint.h>

typedef struct bit_array {
	uint64_t *arr;
	int x; // the length of arr
	int n; // the num of bits
} bit_array;

/* create a bit array which covers n bits. */
bit_array *bit_array_create(int n);

void bit_array_destroy(bit_array *a);

void set_bit(bit_array *a, int i);

int get_bit(bit_array *a, int i);

void clear_bit(bit_array *a, int i);

void set_bits(bit_array *a);

void clean_bits(bit_array *a);

#endif

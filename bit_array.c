#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>

#include "bit_array.h"

bit_array *bit_array_create(int n) {
	int x;
	struct bit_array *a = malloc(sizeof(bit_array));
	if(!a) {
		fprintf(stderr, "malloc failed: %s!\n", strerror(errno));
		return NULL;
	}

	a->n = n;

	x = (int) ceil((double)n/64);

	a->x = x;

	a->arr = malloc(8 * x);
	if(!a->arr) {
		free(a);
		fprintf(stderr, "malloc failed: %s!\n", strerror(errno));
		return NULL;
	}

	return a;
}

void bit_array_destroy(bit_array *a) {
	if(!a) return;

	if(a->arr) free(a->arr);
	free(a);
}

void set_bit(bit_array *a, int i) {
	if(i > a->n) {
		fprintf(stderr, "out of range: this bit array only includes %d bits!\n", a->n);
		return;
	}

	a->arr[i/64] ^= 0x01<<(i%64);
}

int get_bit(bit_array *a, int i) {
	if(i > a->n) {
		fprintf(stderr, "out of range: this bit array only includes %d bits!\n", a->n);
		return -1;
	}

	return (a->arr[i/64] >> (i%64)) & 0x01;
}

void clear_bit(bit_array *a, int i) {
	if(i > a->n) {
		fprintf(stderr, "out of range: this bit array only includes %d bits!\n", a->n);
		return;
	}

	a->arr[i/64] &= ~(0x01<<(i%64));
}

void set_bits(bit_array *a) {
	int i;
	for(i=0; i<a->x; i++) a->arr[i] = 0xFFFFFFFFFFFFFFFF;
}

void clean_bits(bit_array *a) {
	int i;
	for(i=0; i<a->x; i++) a->arr[i] = 0;
}


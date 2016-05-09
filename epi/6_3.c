#include <stdio.h>
#include <stdlib.h>
#include "arr_utils.h"

#define ARR_LEN(a) (sizeof(a)/sizeof(a[0]))

void arr_mul_dig(int *a, int na, int v, int *b, int nb) {
	int i, j;
	int extra = 0;
	for(i=na-1, j=nb-1; i>=0; i--, j--) {
		b[j] = (a[i] * v + extra) % 10;
		extra = (a[i] * v + extra) / 10;
	}
	b[j] = extra;
}

void arr_add(int *a, int na, int *b, int nb) {
	int i, j;
	int extra = 0;
	for(i=na-1, j=nb-1; j>=0; i--, j--) {
		int k = a[i];
		a[i] = (k + b[j] + extra) % 10;
		extra = (k + b[j] + extra) / 10;
	}
	a[i] = extra;
}

void arr_mul(int *a, int na, int *b, int nb, int *c, int nc) {
	int i, j;
	j = nc;
	for(i=0; i<na; i++) {
		int nd = nb+1;
		int d[nd];
		arr_init(d, nd, 0);
		arr_mul_dig(b, nb, a[na-i-1], d, nd);
		arr_add(c, j--, d, nd);
	}
}

int arr_prune(int *a, int na) {
	int i = 0, j = 0;
	while(a[j] == 0) j++;
	if(i == j) return na;
	while(j < na) {
		a[i++] = a[j++];
	}
	return i;
}

int main(void) {
	int a[] = {1, 9, 3, 7, 0, 7, 7, 2, 1};
	int b[] = {-7, 6, 1, 8, 3, 8, 2, 5, 7, 2, 8, 7};
	//int a[] = {2, 3, 4};
	//int b[] = {3, 5};

	int r_sign = (a[0]*b[0] > 0) ? 1 : -1;
	int na = ARR_LEN(a);
	int nb = ARR_LEN(b);
	int nc = na + nb;
	int c[nc];

	arr_init(c, nc, 0);

	arr_print(a, na);
	arr_print(b, nb);

	a[0] = abs(a[0]);
	b[0] = abs(b[0]);

	if(na < nb) {
		arr_mul(a, na, b, nb, c, nc);	
	} else {
		arr_mul(b, nb, a, na, c, nc);	
	}

	nc = arr_prune(c, nc);

	c[0] *= r_sign;

	arr_print(c, nc);

	return 0;
}

/*
gcc -g3 -std=c99 -pedantic -Wall -iquote ../ 6_3.c ../arr_utils.c

1 9 3 7 0 7 7 2 1
-7 6 1 8 3 8 2 5 7 2 8 7
-1 4 7 5 7 3 9 5 2 5 8 9 6 7 6 4 1 2 9 2 7
*/

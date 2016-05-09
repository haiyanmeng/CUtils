#include <stdio.h>
#include "arr_utils.h"

void arr_init(int *a, int n, int v) {
	int i;
	for(i=0; i<n; i++) {
		a[i] = v;
	}
}

void arr_swap(int *a, int i, int j) {
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void arr_print(int *a, int n) {
	int i;
	for(i=0; i<n; i++) {
		fprintf(stdout, "%d ", a[i]);
	}
	fprintf(stdout, "\n");
}


#include <stdio.h>

int dedup_arr(int *a, int n) {
	int r = 1;
	int i;

	if(n == 1) return 1;

	for(i=1; i<n; i++) {
		if(a[i] > a[r-1]) {
			a[r++] = a[i];
		}
	}

	return r;
}

int main(void) {
	int a[] = {2, 3, 5, 5, 7, 11, 11, 11, 13};
	int n = dedup_arr(a, sizeof(a)/sizeof(a[0]));
	int i = 0;
	for(i=0; i<n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

// gcc -g3 -std=c99 -pedantic -Wall 6_5.c

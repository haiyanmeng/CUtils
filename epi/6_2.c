#include <stdio.h>
#include <stdlib.h>

int *inc_arr(int *a, int n, int *m) {
	int i = 0, j = 0;
	int *r;
	int extra = 1;

	while(a[i] == 9) i++;
	if(i < n) *m = n;
	else *m = n+1;
	
	r = malloc(sizeof(int) * *m);
	if(!r) {
		return NULL;
	}

	for(i=*m-1, j=n-1; j>=0; j--, i--) {
		if(a[j] + extra > 9) {
			r[i] = (a[j] + extra)%10;
			extra = 1;
		} else {
			r[i] = a[j] + extra;
			extra = 0;
		}
	}

	if(extra) {
		r[0] = 1;	
	}
	return r;
}

int main(void) {
	//int a[] = {3, 9, 9};
	//int a[] = {9, 9, 9, 9, 9};
	int a[] = {8, 9, 9, 9, 7};
	int n;
	int i;
	int *b = inc_arr(a, sizeof(a)/sizeof(a[0]), &n); 
	for(i=0; i<n; i++) {
		printf("%d ", *(b++));
	}
	printf("\n");
	return 0;
}

// gcc -g3 -std=c99 -pedantic -Wall 6_2.c

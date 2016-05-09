#include <stdio.h>
#include "arr_utils.h"

void partition(int *a, int n, int k) {
	int i = 0, j = n-1;
	int pivot = a[k];
	
	while(i<j) {
		while(a[i] < pivot) i++;
		while(a[j] >= pivot) j--;
		if(i<j) {
			arr_swap(a, i, j);
			i++, j--;
		}
	}

	i = 0, j = n-1;
	while(a[i] < pivot) i++;	
	while(i < j) {
		while(a[i] == pivot) i++;
		while(a[j] > pivot) j--;
		if(i<j) {
			arr_swap(a, i, j);
			i++, j--;
		}
	}
}

int main(void) {
	int a[] = {4, 9, 3, 1, 2};
    int b[] = {4, 9, 3, 4, -1, 8, 4, 5, 0, 1, 2};

	arr_print(a, sizeof(a)/sizeof(a[0]));
    partition(a, sizeof(a)/sizeof(a[0]), 0);
	arr_print(a, sizeof(a)/sizeof(a[0]));

	arr_print(b, sizeof(b)/sizeof(b[0]));
    partition(b, sizeof(b)/sizeof(b[0]), 0);
	arr_print(b, sizeof(b)/sizeof(b[0]));
	return 0;
}

/*
gcc -g3 -std=c99 -pedantic -Wall -iquote ../ 6_1.c ../arr_utils.c

Output:
4 9 3 1 2 
2 1 3 4 9 
4 9 3 4 -1 8 4 5 0 1 2 
2 1 3 0 -1 4 4 4 5 9 8 
*/

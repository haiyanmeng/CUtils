#include <stdio.h>


void swap(int *a, int i, int j) {
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void print_arr(int *a, int n) {
	int i;
	for(i=0; i<n; i++) {
		fprintf(stdout, "%d ", a[i]);
	}
	fprintf(stdout, "\n");
}

void partition(int *a, int n, int k) {
	int i = 0, j = n-1;
	int pivot = a[k];
	
	while(i<j) {
		while(a[i] < pivot) i++;
		while(a[j] >= pivot) j--;
		if(i<j) {
			swap(a, i, j);
			i++, j--;
		}
	}

	i = 0, j = n-1;
	while(a[i] < pivot) i++;	
	while(i < j) {
		while(a[i] == pivot) i++;
		while(a[j] > pivot) j--;
		if(i<j) {
			swap(a, i, j);
			i++, j--;
		}
	}
}

int main(void) {
	int a[] = {4, 9, 3, 1, 2};
    int b[] = {4, 9, 3, 4, -1, 8, 4, 5, 0, 1, 2};

	print_arr(a, sizeof(a)/sizeof(a[0]));
    partition(a, sizeof(a)/sizeof(a[0]), 0);
	print_arr(a, sizeof(a)/sizeof(a[0]));

	print_arr(b, sizeof(b)/sizeof(b[0]));
    partition(b, sizeof(b)/sizeof(b[0]), 0);
	print_arr(b, sizeof(b)/sizeof(b[0]));
	return 0;
}

/*
gcc -g3 -std=c99 -pedantic -Wall 6_1.c 

Output:
4 9 3 1 2 
2 1 3 4 9 
4 9 3 4 -1 8 4 5 0 1 2 
2 1 3 0 -1 4 4 4 5 9 8 
*/

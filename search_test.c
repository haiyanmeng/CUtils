#include <stdio.h>
#include "search.h"

void test(int *a, int n) {
	int i;

	printf("\n*****Testing the array: ");
	for(i=0; i<n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	for(i=0; i<n; i++) {
		printf("search %d: %d\n", a[i], binary_search(a, n, a[i]));
	}

	printf("search %d: %d\n", a[0]-1, binary_search(a, n, a[0]-1));
	printf("search %d: %d\n", a[n-1]+1, binary_search(a, n, a[n-1]+1));
}

int main() {
	int a[8] = {1,3,5,9,15,21,33,40};
	int n1 = 8;

	int b[11] = {-3,-2,1,3,5,9,13,15,21,33,40};
	int n2 = 11;

	test(a, n1);
	test(b, n2);


	
	return 0;
}

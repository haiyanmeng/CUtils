#include <stdio.h>

int max_profit(int *a, int n) {
	int profit = 0;
	int i = 0;
	int min = 0;

	if(n <= 1) return 0;

	min = a[0];

	for(i=1; i<n; i++) {
		if(a[i] - min >	profit) {
			profit = a[i] - min;
		}
		if(a[i] < min) {
			min = a[i];
		}
	}
	return profit;
}

int main(void) {
	int a[10] = {310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
	int n = sizeof(a)/sizeof(a[0]);

	fprintf(stdout, "max_profit(a) = %d\n", max_profit(a, n));
	return 0;
}

/*
gcc -g3 -std=c99 -pedantic -Wall 6_6.c

Output:
max_profit(a) = 30
*/


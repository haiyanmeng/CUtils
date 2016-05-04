#include <stdio.h>

int max_profit(int *a, int n) {
	int t1 = 0, t2 = 0;
	int i = 0;
	int min = 0;
	int profit = 0;

	if(n <= 1) return 0;

	min = a[0];

	for(i=1; i<n; i++) {
		if(a[i] - min >	profit) {
			profit = a[i] - min;
		}
		if(a[i] < min) {
			min = a[i];

			if(profit > t2) {
				if(profit > t1) {
					t2 = t1; t1 = profit;
				} else {
					t2 = profit;
				}
			}
			profit = 0;
		}
	}
	return t1+t2;
}

int main(void) {
	int a[10] = {310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
	int n = sizeof(a)/sizeof(a[0]);

	//int b[] = {310};
	int b[] = {310, 305, 32};
	fprintf(stdout, "max_profit(a) = %d\n", max_profit(a, n));

	fprintf(stdout, "max_profit(b) = %d\n", max_profit(b, sizeof(b)/sizeof(b[0])));
	return 0;
}

/*
gcc -g3 -std=c99 -pedantic -Wall 6_7.c 

Output:
max_profit(a) = 50
*/

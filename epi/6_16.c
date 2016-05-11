#include <stdio.h>
#include <math.h>

#include "arr_utils.h"

/*
 * @param n: the number of rows of a 
 * @param m: the width of the sub-grid in a
 */
int verify_sudoku(int (*a)[9], int n, int m) {
	int h[n+1];
	int i, j;

	// check each row
	for(i=0; i<n; i++) {
		arr_init(h, n+1, 0);	
		for(j=0; j<n; j++) {
			if(a[i][j] < 1 || a[i][j] > 9) return 0;

			if(h[a[i][j]] == 1) return 0;
			else h[a[i][j]] = 1;
		}
	}

	// check each colomn
	for(i=0; i<n; i++) {
		arr_init(h, n+1, 0);	
		for(j=0; j<n; j++) {
			if(a[j][i] < 1 || a[j][i] > 9) return 0;

			if(h[a[j][i]] == 1) return 0;
			else h[a[j][i]] = 1;
		}
	}

	// check each mxm sub-grid
	for(i=0; i<n; i+=m) {
		for(j=0; j<n; j+=m) {
			int s, t;
			arr_init(h, n+1, 0);	
			for(s=0; s<m; s++) {
				for(t=0; t<m; t++) {
					if(a[i+s][j+t] < 1 || a[i+s][j+t] > 9) return 0;
					if(h[a[i+s][j+t]] == 1) return 0;
					else h[a[i+s][j+t]] = 1;
				}
			}
		}
	}

	return 1;
}

int main(void) {
	int a[][9] = {
		{5, 3, 4, 6, 7, 8, 9, 1, 2},
		{6, 7, 2, 1, 9, 5, 3, 4, 8},
		{1, 9, 8, 3, 4, 2, 5, 6, 7},
		{8, 5, 9, 7, 6, 1, 4, 2, 3},
		{4, 2, 6, 8, 5, 3, 7, 9, 1},
		{7, 1, 3, 9, 2, 4, 8, 5, 6},
		{9, 6, 1, 5, 3, 7, 2, 8, 4},
		{2, 8, 7, 4, 1, 9, 6, 3, 5},
		{3, 4, 5, 2, 8, 6, 1, 7, 9},
	};
	int n = sizeof(a)/sizeof(*a);
	fprintf(stdout, "verify_sudoku = %d\n", verify_sudoku(a, n, (int)sqrt(n)));
	return 0;
}

/*
gcc -g3 -Wall -pedantic -std=c99 -lm -iquote ../ 6_16.c  ../arr_utils.c

Output:
verify_sudoku = 1
*/

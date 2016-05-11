#include <stdio.h>
#include <math.h>

#include "arr_utils.h"
#include "bit_array.h"

/*
 * @param n: the number of rows of a 
 * @param m: the width of the sub-grid in a
 */
int verify_sudoku(int (*a)[9], int n, int m) {
	int i, j;
	bit_array *h = bit_array_create(n+1);

	// check each row
	for(i=0; i<n; i++) {
		clean_bits(h);
		for(j=0; j<n; j++) {
			if(a[i][j] < 1 || a[i][j] > 9) {
				bit_array_destroy(h);
				return 0;
			}

			if(get_bit(h, a[i][j]) == 1) {
				bit_array_destroy(h);
				return 0;
			} else set_bit(h, a[i][j]);
		}
	}

	// check each colomn
	for(i=0; i<n; i++) {
		clean_bits(h);
		for(j=0; j<n; j++) {
			if(a[j][i] < 1 || a[j][i] > 9) {
				bit_array_destroy(h);
				return 0;
			}

			if(get_bit(h, a[j][i]) == 1) {
				bit_array_destroy(h);
				return 0;
			} else set_bit(h, a[j][i]);
		}
	}

	// check each mxm sub-grid
	for(i=0; i<n; i+=m) {
		for(j=0; j<n; j+=m) {
			int s, t;
			clean_bits(h);
			for(s=0; s<m; s++) {
				for(t=0; t<m; t++) {
					if(a[i+s][j+t] < 1 || a[i+s][j+t] > 9) {
						bit_array_destroy(h);
						return 0;
					}
					if(get_bit(h, a[i+s][j+t]) == 1) {
						bit_array_destroy(h);
						return 0;
					} else set_bit(h, a[i+s][j+t]);
				}
			}
		}
	}

	bit_array_destroy(h);
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
gcc -g3 -Wall -pedantic -std=c99 -lm -iquote ../ 6_16.c  ../arr_utils.c ../bit_array.c

Output:
verify_sudoku = 1
*/

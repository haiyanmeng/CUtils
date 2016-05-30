#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "str_arr.h"

/*
 * @param set: a char set
 * @param setn: the length of the char set
 * @param n: the length of each char sequence
 * @param loc: the index of the newly number in the phone number
 * @param c: the address of an integer which represents the total count of char sequence
*/
int add_digit(str_arr *t, const char *set, int setn, int n, int loc, int *c) {
	if(!loc) {
		int i;

		for(i=0; i < setn; i++) {
			int j;
			char *s = malloc(sizeof(char) * n);

			/* initialize s to guarantee the first (n-1) bytes are non-terminating char */
			for(j=0; j<n-1; j++) s[j] = 'a';
			s[n-1] = '\0';

			s[loc] = set[i];
			str_arr_insert(t, s);
			free(s);
		}
		*c *= setn;
		return 0;
	} else {
		/* copy all the string in t (setn) times, and then append chars inside (set) to each string. */
		int i, j;

		for(i=0; i<setn-1; i++) {
			for(j=0; j < *c; j++) {
				str_arr_insert(t, t->a[j]);
			}
		}

		for(i=0; i<setn; i++) {
			for(j=0; j < *c; j++) {
				int k = (*c) * i + j;
				t->a[k][loc] = set[i];
			}
		}
		
		*c *= setn;
		return 0;
	}
}

str_arr *get_str_set(const char *s, int *c) {
	static char *map[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	size_t n = strlen(s);
	int i;
	str_arr *arr = str_arr_create(n);
	if(!arr) return NULL;

	for(i=0; i<n; i++) {
		int d = s[i] - '0';
		char *set = map[d];
		size_t a = strlen(set);
		add_digit(arr, set, a, n+1, i, c);
	}
	return arr;
}

int main(void) {
	int c = 1;
	str_arr *arr;
	//arr = get_str_set("23", &c);	
	arr = get_str_set("2276696", &c);	
	str_arr_print(arr);
	str_arr_destroy(arr);
	return 0;
}

/*
gcc -g3 -pedantic -Wall -iquote ../ 7_7.c ../str_arr.c
the total string num: 3888
*/

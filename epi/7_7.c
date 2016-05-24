#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void free_strarr(char **t, int c) {
	int j;
	for(j=0; j < c; j++) {
		free(t[j]);
	}
	free(t);
}

/*
 * @param set: a char set
 * @param setn: the length of the char set
 * @param n: the length of each char sequence
 * @param loc: the index of the newly number in the phone number
 * @param c: the address of an integer which represents the total count of char sequence
*/
char **add_digit(char **t, const char *set, int setn, int n, int loc, int *c) {
	if(!t) {
		int i;
		t = malloc(sizeof(char *) * setn);

		for(i=0; i < setn; i++) {
			int j;
			char *s = malloc(sizeof(char) * n);

			/* initialize s to guarantee the first (n-1) bytes are non-terminating char */
			for(j=0; j<n-1; j++) s[j] = 'a';
			s[n-1] = '\0';

			s[loc] = set[i];
			t[i] = s;
		}
		*c *= setn;
		return t;
	} else {
		/* copy all the string in t (setn) times, and then append chars inside (set) to each string. */
		int i, j;
		char **m = malloc(sizeof(char *) * (*c * setn));

		for(i=0; i<setn; i++) {
			for(j=0; j < *c; j++) {
				int k = (*c) * i + j;
				m[k] = strndup(t[j], n);
			}
		}

		for(i=0; i<setn; i++) {
			for(j=0; j < *c; j++) {
				int k = (*c) * i + j;
				m[k][loc] = set[i];
			}
		}
		
		/* free t */
		free_strarr(t, *c);

		*c *= setn;
		return m;
	}
}

char **get_str_set(const char *s, char **t, int *c) {
	static char *map[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	size_t n = strlen(s);
	int i;
	for(i=0; i<n; i++) {
		int d = s[i] - '0';
		char *set = map[d];
		size_t a = strlen(set);
		t = add_digit(t, set, a, n+1, i, c);
	}
	return t;
}

int main(void) {
	char **t = NULL;
	int c = 1;
	int i;
	//t = get_str_set("23", t, &c);	
	t = get_str_set("2276696", t, &c);	
	for(i=0; i<c; i++) {
		fprintf(stdout, "%s\n", t[i]);
	}	
	fprintf(stdout, "the total string num: %d\n", c);

	free_strarr(t, c);
	return 0;
}

/*
gcc -g3 -pedantic -Wall 7_7.c
the total string num: 3888
*/

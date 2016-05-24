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
 * @param loc: the index of the newly number in the phone number
 * @param c: the address of an integer which represents the total count of char sequence
*/
char **get_str_set(int width, int loc, const char *s, char **t, int *c) {
	static char *map[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	int d, i, j;
	char *set;
	size_t setn;
	char **m;

	if(!s || !*s) {
		*c = 0;
		return NULL;
	}

	d = s[loc] - '0';
	set = map[d];
	setn = strlen(set);

	if(loc == 0) {
		t = malloc(sizeof(char *) * setn);

		for(i=0; i < setn; i++) {
			char *s = malloc(sizeof(char) * width); // width is one more than the length of s to hold the terminating null char.

			/* initialize s to guarantee the first (n-1) bytes are non-terminating char */
			for(j=0; j<width-1; j++) s[j] = 'a';
			s[width-1] = '\0';

			s[loc] = set[i];
			t[i] = s;
		}
		*c *= setn;
		return t;
	}

	/* copy all the string in t (setn) times, and then append chars inside (set) to each string. */
	
	t = get_str_set(width, loc-1, s, t, c);

	m = malloc(sizeof(char *) * (*c * setn));

	for(i=0; i<setn; i++) {
		for(j=0; j < *c; j++) {
			int k = (*c) * i + j;
			m[k] = strndup(t[j], width);
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

int main(void) {
	char **t = NULL;
	int c = 1;
	int i;
	//t = get_str_set("23", t, &c);	
	char *s = "2276696";
	size_t n = strlen(s);
	t = get_str_set(n+1, n-1, s, t, &c);	
	for(i=0; i<c; i++) {
		fprintf(stdout, "%s\n", t[i]);
	}	
	fprintf(stdout, "Recursive solution, the total string num: %d\n", c);

	free_strarr(t, c);
	return 0;
}

/*
gcc -g3 -pedantic -Wall 7_7_recursive.c
Recursive solution, the total string num: 3888
*/

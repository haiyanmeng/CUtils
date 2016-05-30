#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "str_arr.h"

str_arr *str_arr_create(int n) {
	str_arr *s;

	if(n<=0) return NULL;

	s = malloc(sizeof(str_arr));
	if(!s) {
		fprintf(stderr, "malloc failed: %s!\n", strerror(errno));
		return NULL;
	}

	s->n = n;
	s->c = 0;

	s->a = malloc(sizeof(char *) * n);
	if(!s->a) {
		fprintf(stderr, "malloc failed: %s!\n", strerror(errno));
		return NULL;
	}

	return s;
}

void str_arr_destroy(str_arr *s) {
	int i;
	if(!s) return;

	for(i=0; i < s->c; i++) free(s->a[i]);
	free(s->a);
	free(s);
}

int str_arr_expand(str_arr *s) {
	int i;
	char **a1;

	s->n = s->n * 2;

	a1 = malloc(sizeof(char *) * s->n);
	if(!a1) {
		return -1;
	}

	/* copy the old s->a to a1 */
	for(i=0; i<s->c; i++) {
		char *p = strdup(s->a[i]);
		if(!p) {
			fprintf(stderr, "strdup failed: %s!\n", strerror(errno));
			return -1;
		}

		a1[i] = p;
	}

	/* free the memory space allocated for s->a */
	for(i=0; i<s->c; i++) free(s->a[i]);
	free(s->a);	

	s->a = a1;
	return 0;
}

int str_arr_insert(str_arr *s, const char *t) {
	char *p;

	if(!s) return -1;

	if(s->c == s->n) {
		t = strdup(t);	
		if(!t) return -1;
		if(str_arr_expand(s)) return -1;
	}

	s->a[s->c] = NULL;
	p = strdup(t);
	if(!p) {
		fprintf(stderr, "strdup failed: %s!\n", strerror(errno));
		return -1;
	}
	s->a[s->c] = p;
	s->c ++;
	return 0;
}

void str_arr_print(str_arr *s) {
	int i;

	if(!s) return;

	fprintf(stdout, "the arr has %d elements:\n", s->c);
	for(i=0; i<s->c; i++)
		fprintf(stdout, "%s\n", s->a[i]);
	return;
}


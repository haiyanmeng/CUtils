#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define print_bool(a) (a) ? "true" : "false"

bool is_insert_one(const char *a, const char *b) {
	char *p, *q;
	for(p=(char *)a,q=(char *)b; *q; p++,q++) {
		if(!*p) return true;
		if(*p != *q) return strcmp(p, q+1) ? false : true;
	}
	return true;
}

bool is_one_away(const char *a, const char *b) {
	size_t sa, sb;
	sa = strlen(a);
	sb = strlen(b);
	if(sa == sb) {
		size_t i;
		bool diff = false;
		for(i=0; i<sa; i++) {
			if(a[i] != b[i]) {
				if(diff) return false;
				diff = true;
			}
		}
		return true;
	} else if(sa == sb - 1) {
		return is_insert_one(a, b);
	} else if(sa == sb + 1) {
		return is_insert_one(b, a);
	} else {
		return false;
	}
}

// the readability of this solution is low.
bool is_one_away_1(const char *a, const char *b) {
	char *p, *q;
	for(p=(char *)a,q=(char *)b; *p || *q; p++,q++) {
		if((!*p && !*(q+1)) || (!*q && !*(p+1))) return true;
		if(!*p || !*q) return false;
		if(*p != *q)
			return (strcmp(p+1, q+1) ? false : true) ||
				(strcmp(p, q+1) ? false : true) || 
				(strcmp(p+1, q) ? false : true);
	}
	return true;
}

int main() {
	printf("Testing is_one_away:\n");
	printf("%s %s %s\n", "pale", "ple", print_bool(is_one_away("pale", "ple")));
	printf("%s %s %s\n", "pale", "pales", print_bool(is_one_away("pale", "pales")));
	printf("%s %s %s\n", "pale", "pale", print_bool(is_one_away("pale", "pale")));
	printf("%s %s %s\n", "pale", "bale", print_bool(is_one_away("pale", "bale")));
	printf("%s %s %s\n", "pale", "bake", print_bool(is_one_away("pale", "bake")));
	printf("%s %s %s\n", "pale", "", print_bool(is_one_away("pale", "")));

	printf("Testing is_one_away_1:\n");
	printf("%s %s %s\n", "pale", "ple", print_bool(is_one_away_1("pale", "ple")));
	printf("%s %s %s\n", "pale", "pales", print_bool(is_one_away_1("pale", "pales")));
	printf("%s %s %s\n", "pale", "pale", print_bool(is_one_away_1("pale", "pale")));
	printf("%s %s %s\n", "pale", "bale", print_bool(is_one_away_1("pale", "bale")));
	printf("%s %s %s\n", "pale", "bake", print_bool(is_one_away_1("pale", "bake")));
	printf("%s %s %s\n", "pale", "", print_bool(is_one_away_1("pale", "")));
	/* output:
		Testing is_one_away:
		pale ple true
		pale pales true
		pale pale true
		pale bale true
		pale bake false
		pale  false
		Testing is_one_away_1:
		pale ple true
		pale pales true
		pale pale true
		pale bale true
		pale bake false
		pale  false 
	*/
	return 0;
}

// gcc -g3 -std=c99 -pedantic -Wall 1_5.c

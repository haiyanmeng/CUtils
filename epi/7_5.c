#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool equalnocase(int a, int b) {
	if(isdigit(a) && isdigit(b)) {
		return a == b;
	} else if(isalpha(a) && isalpha(b)) {
		return tolower(a) == tolower(b);
	} else {
		return false;
	}
}

bool is_palindromic(const char *s) {
	size_t n = strlen(s);
	int i = 0, j = n-1;
	while(i < j) {
		while(i < n && !isalnum(s[i])) i++;
		while(j >= 0 && !isalnum(s[j])) j--;

		if(i < j) {
			if(!equalnocase(s[i], s[j])) {
				return false;
			} else { i++; j--; }
		}
	}
	return true;
}

int main(void) {
	char *s = "A man,  a plan, a caNAl, Pana ma.";
	fprintf(stdout, "ispalindromic(%s) == %d!\n", s, is_palindromic(s));
	s = "Able was I, ere I saw elba!";
	fprintf(stdout, "ispalindromic(%s) == %d!\n", s, is_palindromic(s));
	s = "ray a ray";
	fprintf(stdout, "ispalindromic(%s) == %d!\n", s, is_palindromic(s));
	return 0;
}

/*
gcc -g3 -std=c99 -pedantic -Wall 7_5.c

Output:
ispalindromic(A man,  a plan, a caNAl, Pana ma.) == 1!
ispalindromic(Able was I, ere I saw elba!) == 1!
ispalindromic(ray a ray) == 0!
*/

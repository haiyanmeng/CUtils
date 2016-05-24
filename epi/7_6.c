#include <stdio.h>
#include <string.h>

void reverse_str(char *s, int start, int end) {
	int i, j;
	for(i=start, j=end; i<j; i++, j--) {
		char t = s[i];
		s[i] = s[j];
		s[j] = t;
	}
}

void reverse_sent(char *s) {
	size_t n = strlen(s);
	char *p = s;

	reverse_str(s, 0, n-1);

	while(*p) {
		size_t a = strcspn(p, " ");	
		reverse_str(p, 0, a-1);
		p += a;

		if(!*p) return;

		a = strspn(p, " ");
		p += a;
	}
}

int main(void) {
	char s[] = "I love you bear";
	char t[] = "I love abcd you bear";

	fprintf(stdout, "s = %s\n", s);
	reverse_sent(s);	
	fprintf(stdout, "reverse_sent(s) = %s\n", s);

	fprintf(stdout, "t = %s\n", t);
	reverse_sent(t);	
	fprintf(stdout, "reverse_sent(t) = %s\n", t);

	return 0;
}

/*
gcc -g3 -std=c99 -pedantic -Wall 7_6.c

Output:
s = I love you bear
reverse_sent(s) = bear you love I
t = I love abcd you bear
reverse_sent(t) = bear you abcd love I
*/

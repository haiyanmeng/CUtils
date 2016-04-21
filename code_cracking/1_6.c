#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "type_conv.h"

char *str_compress(char *s) {
	char *t, *q, *p = s;
	size_t ss, remain;
	char last;
	int r = 0;
	if(!s || !(*s)) return s;

	ss = remain = strlen(s);
	last = *s;

	t = malloc((ss+1) * sizeof(char));

	if(!t) return NULL;

	q = t;

	while(*p) {
		if(*p == last) {
			r++;	
		} else {
			size_t k = snprintf(NULL, 0, "%d", r);

			// the compressed version is longer
			if(k+1 > remain) {
				free(t);
				return s;
			}

			snprintf(q, k+2, "%c%d", last, r);
			q += (k+1);
			remain -= (k+1);

			last = *p;
			r = 1;
		}
		p++;
	}

	{
		size_t k = snprintf(NULL, 0, "%d", r);

		// the compressed version is longer
		if(k+1 > remain) {
			free(t);
			return s;
		}

		snprintf(q, k+2, "%c%d", last, r);
		q += (k+1);
	}

	*q = '\0';
	return t;
	
}

void str_compress_test(char *s) {
	char *t = str_compress(s);
	if(!t) return;
	printf("str_compress(%s at %p) = %s at %p\n", s, (void *)s, t, (void *)t);
	if(t != s) free(t);
}

int main(void) {
	str_compress_test("aabbbcccccd");	
	str_compress_test("aabbbcccccddddddddddd");	
	str_compress_test("aabbccdd");	
	str_compress_test("abcd");	
	return 0;
}

/* output:
str_compress(aabbbcccccd at 0x400b03) = a2b3c5d1 at 0x51d7040
str_compress(aabbbcccccddddddddddd at 0x400b0f) = a2b3c5d11 at 0x51d74d0
str_compress(aabbccdd at 0x400b25) = a2b2c2d2 at 0x51d7530
str_compress(abcd at 0x400b2e) = abcd at 0x400b2e
*/

// gcc -g3 -std=c99 -pedantic -Wall -iquote .. 1_6.c ../type_conv.c


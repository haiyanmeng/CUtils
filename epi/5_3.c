#include <stdio.h>
#include "bit_utils.h"

long reverse_bits(long x) {
	int w = sizeof(x) * 8;
	int i;
	for(i=0; i<w/2; i++) {
		x = swap_bits(x, i, w-i-1);
	}
	return x;
}

void reverse_bits_test(long x) {
	print_bits(x);
	printf("\n");
	printf("reverse_bits(%lx) = %lx\n", x, reverse_bits(x));
	print_bits(reverse_bits(x));
	printf("\n");
}

int main(void) {
	long x;
	x = 0xFF;
	reverse_bits_test(x);
	x = 0xFF343576;
	reverse_bits_test(x);
	return 0;
}

// gcc -g3 -std=c99 -pedantic -Wall -iquote .. ../bit_utils.h 5_3.c  ../bit_utils.c

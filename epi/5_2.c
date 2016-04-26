#include <stdio.h>
#include "bit_utils.h"

void swap_bits_test(unsigned long x, int a, int b) {
	print_bits(x);
	printf("\n");
	printf("swap_bits(0x%lx, %d, %d) = 0x%lx\n", x, a, b, swap_bits(x, a, b));
	print_bits(swap_bits(x,a,b));
	printf("\n");
}

int main(void) {
	unsigned long x;
	int a, b;
	x = 0x78;
	a = 63;
	b = 3;
	swap_bits_test(x, a, b);
	return 0;
}

// gcc -g3 -std=c99 -pedantic -Wall -iquote .. ../bit_utils.h 5_2.c  ../bit_utils.c

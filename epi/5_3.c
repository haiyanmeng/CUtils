#include <stdio.h>
#include "bit_utils.h"

unsigned long reverse_bits(unsigned long x) {
	int w = sizeof(x) * 8;
	int i;
	for(i=0; i<w/2; i++) {
		x = swap_bits(x, i, w-i-1);
	}
	return x;
}

void reverse_bits_test(unsigned long x) {
	print_bits(x);
	printf("\n");
	printf("reverse_bits(%lx) = %lx\n", x, reverse_bits(x));
	print_bits(reverse_bits(x));
	printf("\n");
}

int main(void) {
	unsigned long x;
	x = 0xFF;
	reverse_bits_test(x);
	x = 0xFF343576;
	reverse_bits_test(x);
	return 0;
}

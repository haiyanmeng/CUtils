#include <stdio.h>

unsigned long swap_bits(unsigned long x, int a, int b) {
	if((x & (0x01UL<<a)) != (x & (0x01UL<<b))) {
		x ^= 0x01UL<<a;
		x ^= 0x01UL<<b;
	}
	return x;
}

void swap_bits_test(unsigned long x, int a, int b) {
	printf("swap_bits(0x%lx, %d, %d) = 0x%lx\n", x, a, b, swap_bits(x, a, b));
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

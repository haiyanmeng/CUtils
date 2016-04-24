#include <stdio.h>
#include <assert.h>

unsigned long add(unsigned long a, unsigned long b) {
	unsigned long result = 0;
	unsigned long k = 0x01UL; //the current bit which is under calculation
	int extra = 0;
	while(a || b) {
		if((a & 0x01UL) ^ (b & 0x01UL) ^ extra)
			result |= k;

		if(extra && !(a & 0x01UL) && !(b & 0x01UL)) extra = 0;

		if(!extra && (a & 0x01UL) && (b & 0x01UL)) extra = 1;

		k <<= 1;
		a >>= 1;
		b >>= 1;
	}

	if(extra) result |= k;
	return result;
}

unsigned long mul(unsigned long a, unsigned long b) {
	unsigned long result = 0;
	while(a) {
		if(a & 0x01UL) result = add(result, b);
		b <<= 1;
		a >>= 1;
	}
	return result;
}

void mul_test(unsigned long a, unsigned long b) {
	printf("%lu * %lu = %lu\n", a, b, mul(a, b));
	assert((a*b) == mul(a,b));
}

int main(void) {
	unsigned long a, b;
	a = 38;
	b = 34;
	mul_test(a, b);
	a = 38888;
	b = 334355;
	mul_test(a, b);
	return 0;
}

// gcc -g3 -std=c99 -pedantic -Wall 5_5.c 

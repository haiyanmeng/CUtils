#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

#include "bit_utils.h"

// if the binary format of a includes even number of 1, return 0;
// if the binary format of a includes odd number of 1, return 1.
bool parity(unsigned long a) {
	bool result = false;
	while(a) {
		if(a & 0x01UL) result ^= 1;
		a >>= 1;
	}
	return result;
}

bool parity_16(uint16_t a) {
	bool result = false;
	while(a) {
		if(a & 0x01) result ^= 1;
		a >>= 1;
	}
	return result;
}

bool parity_64(unsigned long a) {
	assert(sizeof(a) == 8);
	return parity_16(a & 0xFFFF) 
		^ parity_16((a>>16) & 0xFFFF) 
		^ parity_16((a>>32) & 0xFFFF) 
		^ parity_16((a>>48) & 0xFFFF);
}

void parity_test(unsigned long a) {
	printf("parity(%lu) = %d; parity_64(%lu) = %d; count_one(%lu) = %d\n", a, parity(a), a, parity_64(a), a, count_one(a));
	assert(parity(a) == parity_64(a));
	assert(parity(a) == count_one(a)%2);
}

int main(void) {
	unsigned long a;
	a = 3435;
	parity_test(a);
	a = 0x0F;
	parity_test(a);
	a = 0x7F;
	parity_test(a);
	a = 0x7FFFFFFFFFFFFFFF;
	parity_test(a);
	a = 0xFFFFFFFFFFFFFFFF;
	parity_test(a);
	return 0;
}

// gcc -g3 -std=c99 -pedantic -Wall -iquote ../ 5_1.c ../bit_utils.c
/* output:
parity(3435) = 0; count_one(3435) = 8
parity(15) = 0; count_one(15) = 4
parity(127) = 1; count_one(127) = 7
parity(9223372036854775807) = 1; count_one(9223372036854775807) = 63
parity(18446744073709551615) = 0; count_one(18446744073709551615) = 64
*/

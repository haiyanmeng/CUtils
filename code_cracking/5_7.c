#include <stdio.h>
#include <stdint.h>

uint64_t pairwise_swap(uint64_t a) {
	return ((a & 0xaaaaaaaaaaaaaaaa) >> 1) | ((a & 0x5555555555555555) << 1);
}

uint64_t pairwise_swap_1(uint64_t a) {
	uint8_t i;
	//uint64_t s = 0x03;
	for(i=0; i<64; i+=2) {
		if(((a>>i)&0x01UL) != ((a>>(i+1))&0x01UL)) {
			// here can not use: a ^= 0x03<<i
			// 0x03<<i can not create a 64-bit int, it will overflow.
			//a ^= s<<i; //correct
			a ^= 0x03UL<<i; //correct
		}
	}
	return a;
}

int main() {
	uint64_t a = 0x0123456789abcdef;
	printf("%lX ==> %lX\n", a, pairwise_swap(a));
	printf("%lX ==> %lX\n", a, pairwise_swap_1(a));
	a = 0x123456789abcdef9;
	printf("%lX ==> %lX\n", a, pairwise_swap(a));
	printf("%lX ==> %lX\n", a, pairwise_swap_1(a));
	return 0;
}

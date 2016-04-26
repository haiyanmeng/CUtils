#include <stdio.h>

#include "bit_utils.h"

long find_friend(long x) {
	int w = sizeof(x) * 8;
	int i = 0;

	while(i<(w-1) && ((x>>i & 0x01L) == (x>>(i+1) &0x01L))) i++;
	
	if(i == (w-1)) return x;

	x ^= 0x01L<<i;
	x ^= 0x01L<<(i+1);
	return x;
}

void find_friend_test(long x) {
	print_bits(x);
	printf("\n");
	print_bits(find_friend(x));
	printf("\n");
}

int main(void) {
	long x;
	x = 0x73959;
	find_friend_test(x);
	x = 0x73959FFF;
	find_friend_test(x);
	x = 0;
	find_friend_test(x);
	x = 0xFFFFFFFFFFFFFFFF;
	find_friend_test(x);
	return 0;
}
// gcc -g3 -std=c99 -pedantic -Wall -iquote .. ../bit_utils.h 5_4.c  ../bit_utils.c

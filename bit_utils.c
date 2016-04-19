#include "bit_utils.h"

int neg_value(int a) {
	return ~a + 1;
}

int count_one(unsigned int a) {
	int n = 0;
	while(a) {
		if(a & 0x01) n++;
		a >>= 1;
	}
	return n;
}


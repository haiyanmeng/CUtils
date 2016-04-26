#include <stdio.h>

unsigned long divide_1(unsigned long x, unsigned long y) {
	unsigned long result = 0;

	int i = 0;
	while(y<<i <= x) {
		i++; 
	}

	while(i >= 0) {
		if(y<<i <= x) {
			result += 0x01UL << i;
			x -= y<<i;
		}
		i--;
	}

	return result;
}

// based-on subtraction
unsigned long divide(unsigned long x, unsigned long y) {
	unsigned long result = 0;	
	while(x >= y) {
		result += 1;
		x -= y;
	}
	return result;
}

void divide_test(unsigned long x, unsigned long y) {
	printf("divide(%lu, %lu) = %lu; %lu/%lu = %lu;\n", x, y, divide(x, y), x, y, x/y);
	printf("divide_1(%lu, %lu) = %lu; %lu/%lu = %lu;\n", x, y, divide_1(x, y), x, y, x/y);
}

int main(void) {
	unsigned long x, y;
	x = 10, y = 3;
	divide_test(x, y);
	x = 3435; y = 17;
	divide_test(x, y);
	return 0;
}

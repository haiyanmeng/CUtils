#include <stdio.h>
#include <stdlib.h>

int mul_shift(int a, int b) {
	int i = 0, result = 0;	

	if(a < 0 || b < 0) {
		printf("Only support the multiplication of two non-negative integers\n");
		exit(1);
	}

	if(a == 0 || b == 0) return 0;

	if(a == 1) return b;
	
	if(b == 1) return a;

	while(a) {
		if(a & 0x01) {
			result += b<<i;
		}
		a >>= 1;
		i += 1;
	}
	return result;
}

int mul_rec_shift1(int a, int b, int i) {
	if(a < 0 || b < 0) {
		printf("Only support the multiplication of two non-negative integers\n");
		exit(1);
	}

	if(a == 0 || b == 0) return 0;

	if(a & 0x01)
		return mul_rec_shift1(a>>1, b, i+1) + (b<<i);
	else
		return mul_rec_shift1(a>>1, b, i+1);
}

int mul_rec_shift(int a, int b) {
	int extra = 0;	

	if(a < 0 || b < 0) {
		printf("Only support the multiplication of two non-negative integers\n");
		exit(1);
	}

	if(a == 0 || b == 0) return 0;

	if(a == 1) return b;
	
	if(b == 1) return a;

	if(a & 0x01) extra = b;

	return mul_rec_shift(a>>1, b) + mul_rec_shift(a>>1, b) + extra;
}

int mul_rec(int a, int b) {
	int min, max;

	if(a < 0 || b < 0) {
		printf("Only support the multiplication of two non-negative integers\n");
		exit(1);
	}

	if(a == 0 || b == 0) return 0;

	if(a == 1) return b;
	
	if(b == 1) return a;

	min = a <= b ? a : b;
	max = a > b ? a : b;

	return max + mul_rec(min-1, max);
}

int mul(int a, int b) {
	int min, max, result = 0;
	int i;

	if(a < 0 || b < 0) {
		printf("Only support the multiplication of two non-negative integers\n");
		exit(1);
	}

	if(a == 0 || b == 0) return 0;

	if(a == 1) return b;
	
	if(b == 1) return a;

	min = a <= b ? a : b;
	max = a > b ? a : b;

	for(i=0; i<min; i++)
		result += max;

	return result;
}

void mul_test(int a, int b) {
	printf("mul_test: %d * %d = %d\n", a, b, mul(a, b));
	printf("mul_rec_test: %d * %d = %d\n", a, b, mul_rec(a, b));
	printf("mul_rec_shift_test: %d * %d = %d\n", a, b, mul_rec_shift(a, b));
	printf("mul_rec_shift1_test: %d * %d = %d\n", a, b, mul_rec_shift1(a, b, 0));
	printf("mul_shift_test: %d * %d = %d\n", a, b, mul_shift(a, b));
}

int main(void) {
	mul_test(8, 9);
	mul_test(18, 229);
	return 0;
}

/* output:
mul_test: 8 * 9 = 72
mul_rec_test: 8 * 9 = 72
mul_rec_shift_test: 8 * 9 = 72
mul_rec_shift1_test: 8 * 9 = 72
mul_shift_test: 8 * 9 = 72
mul_test: 18 * 229 = 4122
mul_rec_test: 18 * 229 = 4122
mul_rec_shift_test: 18 * 229 = 4122
mul_rec_shift1_test: 18 * 229 = 4122
mul_shift_test: 18 * 229 = 4122
*/

// gcc --std=c99 -pedantic -Wall 8_5.c 

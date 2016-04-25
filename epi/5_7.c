#include <stdio.h>
#include <math.h>

double power_1(double x, int y) {
	double result = 1.0;

	if(y < 0) {
		x = 1/x;
		y = -y;
	}

	while(y) {
		if(y & 0x01) {
			result *= x;
		}
		x *= x;
		y >>= 1;
	}
	return result;
}

double power(double x, int y) {
	double result = 1.0;

	if(y < 0) {
		x = 1/x;
		y = -y;
	}

	while(y) {
		result *= x;
		y--;
	}

	return result;
}

void power_test(double x, int y) {
	printf("power(%f, %d) = %f, pow(%f, %d) = %f\n", x, y, power(x, y), x, y, pow(x, y));
	printf("power_1(%f, %d) = %f, pow(%f, %d) = %f\n", x, y, power_1(x, y), x, y, pow(x, y));
}

int main(void) {
	double x;
	int y;
	x = 3.0;
	y = 4;
	power_test(x, y);
	x = 3.0;
	y = -4;
	power_test(x, y);
	return 0;
}

// gcc -g3 -std=c99 -pedantic -Wall -lm 5_7.c

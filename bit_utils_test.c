#include <stdio.h>
#include <assert.h>

#include "bit_utils.h"

void neg_value_test(int a) {
	printf("neg_value(%d) = %d\n", a, neg_value(a));
	assert(-a == neg_value(a));
}

void count_one_test(int a) {
	printf("count_one(%d) = %d\n", a, count_one(a));
}

int main(void) {
	neg_value_test(233);
	count_one_test(33);
	count_one_test(63);
	count_one_test(-1);

	return 0;
}

// gcc --std=c99 -pedantic -Wall bit_utils_test.c bit_utils.c

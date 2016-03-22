#include <stdio.h>
#include <assert.h>
#include "stack.h"

int main() {
	int i, n = 1000;
	struct stack *s = stack_create();
	for(i=0; i<n; i++) {
		printf("Pushing %d\n", i);
		push(s, i);
	}

	for(i=0; i<n; i++) {
		printf("Poping %d\n", n-i-1);
		assert(top(s) == (n-i-1));
		pop(s);
	}

	stack_destroy(s);
	return 0;
}

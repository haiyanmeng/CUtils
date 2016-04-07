#include <stdio.h>
#include <assert.h>

#include "stack.h"

int sort_stack_1(struct stack *s) {
	struct stack *t = stack_create();

	while(!is_empty(s)) {
		int cur = pop(s);

		if(is_empty(t) || cur >= top(t)) {
			push(t, cur);
			continue;
		}

		// cur < top(t)
		while(!is_empty(t) && cur < top(t)) {
			push(s, pop(t));
		}
		push(t, cur);
	}

	while(!is_empty(t)) {
		push(s, pop(t));
	}
	stack_destroy(t);
	return 0;
}


int sort_stack(struct stack *s) {
	struct stack *t = stack_create();

	while(!is_empty(s)) {
		int min = top(s), n = 0;
		int i;
		int c = 0;
		while(!is_empty(s)) {
			int k = pop(s);
			if(k < min) min = k;
			push(t, k);
			c++;
		}

		for(i=0; i<c; i++) {
			int k = pop(t);
			if(k == min) n++;
			else push(s, k);
		}

		for(i=0; i<n; i++) push(t, min);
	}

	while(!is_empty(t)) {
		push(s, pop(t));
	}
	stack_destroy(t);
	return 0;
}

int main() {
	struct stack *s = stack_create();
	assert(is_empty(s));
	push(s, 5);
	push(s, 20);
	push(s, 1);
	push(s, 20);
	push(s, 12);
	push(s, 12);
	push(s, 12);
	push(s, 39);
	push(s, 20);

	//sort_stack(s);
	sort_stack_1(s);

	fprintf(stdout, "the sorted stack are:\n");
	while(!is_empty(s)) {
		fprintf(stdout, "%d\n", pop(s));
	}

	assert(is_empty(s));
	stack_destroy(s);
	return 0;
}

// gcc -g3 -std=c99 -pedantic -Wall 3_5.c stack.c

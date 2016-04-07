#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "stack.h"

struct node {
	int data;
	struct node *next;
};

struct stack {
	int n;
	struct node *top;
};

struct stack *stack_create() {
	struct stack *s = malloc(sizeof(struct stack));
	if(!s) {
		fprintf(stderr, "Fails to create a stack!(errno %d: %s)\n", errno, strerror(errno));
		return NULL;
	}

	s->n = 0;
	s->top = NULL;	
	return s;
}

void stack_destroy(struct stack *s) {
	struct node *node, *next;
	for(node=s->top; node; node=next) {
		next = node->next;
		free(node);
	}
	free(s);
}

int push(struct stack *s, int data) {
	struct node *node = malloc(sizeof(struct node));
	if(!node) {
		fprintf(stderr, "Fails to create a stack element!(errno %d: %s)\n", errno, strerror(errno));
		return -errno;
	}

	node->data = data;
	node->next = s->top;
	s->top = node;
	s->n++;
	return 0;
}

int pop(struct stack *s) {
	struct node *node;
	int result;

	if(!s->top) {
		fprintf(stderr, "The stack is empty already, and can not be popped any more! (error %d: %s)\n", errno, strerror(errno));
		exit(EXIT_FAILURE);
	}

	node = s->top;
	result = node->data;
	s->top = node->next;
	s->n--;
	free(node);

	return result;
}

int top(struct stack *s) {
	if(!s->top) {
		fprintf(stderr, "The stack is empty already, and can not be popped any more! (error %d: %s)\n", errno, strerror(errno));
		exit(EXIT_FAILURE);
	}
	return s->top->data;
}

int is_empty(struct stack *s) {
	return !s->n;
}

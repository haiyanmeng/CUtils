#ifndef STACK_H
#define STACK_H

struct stack *s;

/* create an empty stack */
struct stack *stack_create();

/* destroy a stack */
void stack_destroy(struct stack *s);
	
/* push one element onto the stack */
void push(struct stack *s, int data);

/* pop one element from the stack */
int pop(struct stack *s);

/* peek the top of the stack */
int top(struct stack *s);

#endif

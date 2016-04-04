#ifndef LIST_H
#define LIST_H

struct node {
	int data;
	struct node *next;
};

/* create a list */
struct node *list_create(int data);

/* insert at the beginning of a list */
struct node *list_add(struct node *list, int data);

/* destroy a list */
void list_destroy(struct node *list);

void list_traverse(struct node *list);

struct node *list_reverse(struct node *list);

#endif

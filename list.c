#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"

struct node *list_create(void *data, type_t type, int int_data) {
	struct node *node = malloc(sizeof(struct node));
	if(!node) {
		fprintf(stderr, "malloc failed: %s!\n", strerror(errno));
		return NULL;
	}
	node->data = data;
	node->type = type;
	node->int_data = int_data;
	node->next = NULL;
	return node;
}

struct node *list_add(struct node *list, void *data, type_t type, int int_data) {
	struct node *node = list_create(data, type, int_data);
	if(!node) {
		fprintf(stderr, "list_create failed: %s!\n", strerror(errno));
		return NULL;
	}
	list->next = node;
	return node;
}

void list_destroy(struct node *list) {
	while(list) {
		struct node *node = list->next;
		free(list);
		list = node;	
	}
}

void list_traverse(struct node *list) {
	size_t s = 0;
	while(list) {
		s++;
		switch(list->type) {
		case TYPE_INT:
			fprintf(stdout, "node %zu: %d\n", s, list->int_data);
			break;
		case TYPE_STRING:
			fprintf(stdout, "node %zu: %s\n", s, (char *)(list->data));
			break;
		default:
			break;
		}
		list = list->next;	
	}
}

struct node *list_reverse(struct node *list) {
	struct node *q, *s;

	if(!list || !(list->next)) return list;

	q = list->next;
	if(!(q->next)) {
		q->next = list;
		list->next = NULL;
		return q;
	}

	s = q->next;
	list->next = NULL;
	while(s) {
		q->next = list;
		list = q;
		q = s;
		s = s->next;
	}
	q->next = list;
	return q;
}

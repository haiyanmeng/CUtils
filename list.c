#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"

struct node *node_create(void *data, type_t type, int int_data) {
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

struct list *list_create(void) {
	struct list *list = malloc(sizeof(struct list));
	if(!list) {
		fprintf(stderr, "malloc failed: %s!\n", strerror(errno));
		return NULL;
	}
	list->head = list->tail = NULL;
	return list;
}

int list_insert_front(struct list*list, void *data, type_t type, int int_data) {
	struct node *node = node_create(data, type, int_data);
	if(!node) {
		fprintf(stderr, "node_create failed: %s!\n", strerror(errno));
		return -errno;
	}

	if(!list->head) {
		list->head = list->tail = node;
	} else {
		node->next = list->head;
		list->head = node;
	}

	return 0;
}

struct list *list_attach(struct list *a, struct list *b) {
	if(!b) return a;
	if(!a->tail) {
		a->head = b->head;
		a->tail = b->tail;
	} else {
		a->tail->next = b->head;
		a->tail = b->tail;
	}
	free(b);
	return a;
}

int list_append(struct list*list, void *data, type_t type, int int_data) {
	struct node *node = node_create(data, type, int_data);
	if(!node) {
		fprintf(stderr, "node_create failed: %s!\n", strerror(errno));
		return -errno;
	}

	if(!list->head) {
		list->head = list->tail = node;
	} else {
		list->tail->next = node;
		list->tail = node;
	}

	return 0;
}

void list_destroy(struct list *list) {
	struct node *node = list->head;
	while(node) {
		struct node *tmp = node->next;
		free(node);
		node = tmp;
	}
	free(list);
}

void list_traverse(struct list *list) {
	size_t s = 0;
	struct node *node = list->head;
	while(node) {
		s++;
		switch(node->type) {
		case TYPE_INT:
			fprintf(stdout, "node %zu: %d\n", s, node->int_data);
			break;
		case TYPE_STR:
			fprintf(stdout, "node %zu: %s\n", s, (char *)(node->data));
			break;
		default:
			break;
		}
		node = node->next;
	}
}

int list_reverse(struct list *list) {
	struct node *q, *s, *p;
	p = list->head;

	if(!p || !(p->next)) return 0;

	q = p->next;
	if(!(q->next)) {
		q->next = list->head;
		list->head->next = NULL;
		list->tail = list->head;
		list->head = q;
		return 0;
	}

	s = q->next;
	p->next = NULL;
	list->tail = p;
	while(s) {
		q->next = p;
		p = q;
		q = s;
		s = s->next;
	}
	q->next = p;
	list->head = q;
	return 0;
}

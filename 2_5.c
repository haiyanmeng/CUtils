#include <stdio.h>

#include "list.h"

struct node *int_to_list(int n) {
	struct node *r = NULL, *t = NULL;
	while(n) {
		int a;
		a = n%10;
		if(!r) t = r = list_create(NULL, TYPE_INT, a);
		else  t = list_add(t, NULL, TYPE_INT, a);
		n = n/10;
	}
	return r;
}

struct node *sum_lists(struct node *p, struct node *q) {
	struct node *r = NULL, *t = NULL;
	int flag = 0;

	while(p || q) {
		int a = 0, b = 0;
		struct node *k;

		if((p && p->type != TYPE_INT) || (q && q->type != TYPE_INT)) {
			fprintf(stderr, "%s:%s:%d: the elements should be integer!\n", __func__, __FILE__, __LINE__);
			return NULL;
		}

		if(p) a = p->int_data;
		if(q) b = q->int_data;

		k = list_create(NULL, TYPE_INT, (a+b+flag)%10);
		if(!k) return NULL;

		flag = (a+b+flag)/10;

		if(!r) t = r = k;
		else {
			t->next = k;
			t = k;
		}

		if(p) p = p->next;
		if(q) q = q->next;
	}

	if(flag) {
		struct node *k = list_create(NULL, TYPE_INT, 1);
		t->next = k;
		t = k;
	}
	return r;
}

void sum_list_test(int a, int b) {
	struct node *list = int_to_list(a);
	struct node *list1 = int_to_list(b);
	struct node *l3 = sum_lists(list, list1);
	fprintf(stdout, "traverse %d:\n", a);
	list_traverse(list);
	fprintf(stdout, "traverse %d:\n", b);
	list_traverse(list1);
	fprintf(stdout, "traverse %d + %d = %d:\n", a, b, a+b);
	list_traverse(l3);
	list_destroy(list);
	list_destroy(list1);
	list_destroy(l3);
}

void list_traverse_test(int a) {
	struct node *list = int_to_list(a);
	fprintf(stdout, "traverse %d:\n", a);
	list_traverse(list);
	struct node *list1 = list_reverse(list);
	fprintf(stdout, "traverse reverse(%d):\n", a);
	list_traverse(list1);
	list_destroy(list1);
}

int main() {
	list_traverse_test(123456789);
	sum_list_test(612, 234738);
	sum_list_test(6123434, 234738);

	return 0;
}

// gcc -g3 -std=c99 -pedantic -Wall 2_5.c list.c

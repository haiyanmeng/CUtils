#include <stdio.h>

#include "list.h"

struct list *int_to_list(int n) {
	struct list *r = list_create();
	while(n) {
		int a;
		a = n%10;
		list_append(r, NULL, TYPE_INT, a);
		n = n/10;
	}
	return r;
}

struct list*sum_lists(struct list *list1, struct list *list2) {
	int flag = 0;

	struct list *k = list_create();
	struct node *p, *q;
	p = list1->head;
	q = list2->head;

	while(p || q) {
		int a = 0, b = 0;

		if((p && p->type != TYPE_INT) || (q && q->type != TYPE_INT)) {
			fprintf(stderr, "%s:%s:%d: the elements should be integer!\n", __func__, __FILE__, __LINE__);
			return NULL;
		}

		if(p) a = p->int_data;
		if(q) b = q->int_data;

		if(list_append(k, NULL, TYPE_INT, (a+b+flag)%10)) return NULL;

		flag = (a+b+flag)/10;

		if(p) p = p->next;
		if(q) q = q->next;
	}

	if(flag) list_append(k, NULL, TYPE_INT, 1);
	return k;
}

void sum_list_test(int a, int b) {
	struct list *list = int_to_list(a);
	struct list *list1 = int_to_list(b);
	struct list *l3 = sum_lists(list, list1);
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
	struct list *list = int_to_list(a);
	fprintf(stdout, "traverse %d:\n", a);
	list_traverse(list);
	list_reverse(list);
	fprintf(stdout, "traverse reverse(%d):\n", a);
	list_traverse(list);
	list_destroy(list);
}

int main() {
	list_traverse_test(123456789);
	sum_list_test(612, 234738);
	sum_list_test(6123434, 234738);

	return 0;
}

// gcc -g3 -std=c99 -pedantic -Wall -iquote ../ 2_5.c ../list.c

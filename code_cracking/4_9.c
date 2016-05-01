#include <stdio.h>

#include "bst.h"
#include "list.h"

/*
	int arr[] = {5, 3, 2, 4, 7, 6};
root: 5
left: 2
3
left: 2 
right: 4

left = []; right = [4]
r=[];
m = 

*/

struct list *merge_seq(struct node *left_seq, struct node *right_seq) {
	struct list *r = NULL;
	struct node *p = NULL;

	if(!left_seq && !right_seq) return NULL;

	r = list_create();

	if(left_seq) {
		struct list *m = merge_seq(left_seq->next, right_seq);
		if(!m) {
			struct list *k = list_create();
			list_insert_front(k, (void *)(left_seq->data), TYPE_VOID_POINTER, 0);
			m = list_create();
			list_insert_front(m, (void *) k, TYPE_VOID_POINTER, 0);
		} else {
			p = m->head;
			while(p) {
				list_insert_front((struct list *)(p->data), (void *)(left_seq->data), TYPE_VOID_POINTER, 0);
				p = p->next;
			}
		}
		list_attach(r, m);
	}

	if(right_seq) {
		struct list *m = merge_seq(left_seq, right_seq->next);
		if(!m) {
			struct list *k = list_create();
			list_insert_front(k, (void *)(right_seq->data), TYPE_VOID_POINTER, 0);
			m = list_create();
			list_insert_front(m, (void *) k, TYPE_VOID_POINTER, 0);
		} else {
			p = m->head;
			while(p) {
				list_insert_front((struct list *)(p->data), (void *)(right_seq->data), TYPE_VOID_POINTER, 0);
				p = p->next;
			}
		}
	
		list_attach(r, m);
	}

	return r;
}

struct list *merge_seqs(struct list *left_seqs, struct list *right_seqs) {
	struct list *r = NULL;
	struct node *p = NULL, *q = NULL;
	if(!left_seqs) return right_seqs;
	if(!right_seqs) return left_seqs;

	r = list_create();
	p = left_seqs->head;
	while(p) {
		q = right_seqs->head;
		while(q) {
			list_attach(r, merge_seq(((struct list *)(p->data))->head, ((struct list *)(q->data))->head));
			q = q->next;
		}
		p = p->next;
	}
	return r;
}

struct list *bst_seqs(struct bst *root) {
	struct list *r = NULL;	
	struct list *left_seqs = NULL, *right_seqs = NULL;
	struct node *p = NULL;
	if(!root) return r;

	if(root->left) {
		left_seqs = bst_seqs(root->left);
	}

	if(root->right) {
		right_seqs = bst_seqs(root->right);
	}

	r = merge_seqs(left_seqs, right_seqs);

	if(!r) {
		struct list *item;
		r = list_create();
		item = list_create();
		list_append(item, (void *)root, TYPE_VOID_POINTER, 0);
		list_append(r, (void *)item, TYPE_VOID_POINTER, 0);
		return r;
	}

	p = r->head;
	while(p) {
		list_insert_front((struct list *)(p->data), (void *) root, TYPE_VOID_POINTER, 0);
		p = p->next;
	}
	return r;
}

void print_seqs(struct list *r) {
	struct node *p;
	if(!r || !(r->head)) return;

	fprintf(stdout, "outer list %p\n", (void *)r);

	p = r->head;
	while(p) {
		struct node *n;
		struct list *k = (struct list *)(p->data);
		if(!k || !(k->head)) continue;
		fprintf(stdout, "inner list %p ", (void *)p);
		n = k->head;
		while(n) {
			fprintf(stdout, "item%p:", (void *)n);
			struct bst *b = (struct bst *)(n->data);
			if(!b) break;
			fprintf(stdout, "%d(%p) ", b->data, (void *)b);
			n = n->next;
		}
		fprintf(stdout, "\n");
		list_destroy(k);
		p = p->next;
	}
	list_destroy(r);
}

/*
left: 3 2 4
	  3 4 2
right 7 6
3 
7
*/

int main(void) {
	//int arr[] = {5, 3, 2, 4, 7, 6};
	int arr[] = {3, 2, 4};
	struct bst *root = bst_build(arr, sizeof(arr)/sizeof(int));
	struct list *r;
	if(!root) return 0;
	bst_print_inorder(root);
	fprintf(stdout, "\n");

	r = bst_seqs(root);
	print_seqs(r);

	bst_destroy(root);
	return 0;
}


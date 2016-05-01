#include <stdlib.h>
#include <stdio.h>

#include "bst.h"

struct bst *bst_create(int data) {
	struct bst *p = malloc(sizeof(struct bst));
	if(!p) {
		fprintf(stderr, "malloc failed!\n");
		return NULL;
	}
	p->data = data;
	p->left = p->right = NULL;
	return p;
}

void bst_destroy(struct bst *root) {
	if(!root) return;
	if(root->left) bst_destroy(root->left);
	if(root->right) bst_destroy(root->right);
	free(root);
}

int bst_insert(struct bst *root, int data) {
	struct bst *p = root;	
	while(p) {
		if(p->data == data) {
			return 0;
		} else if(p->data > data) {
			if(p->left) {
				p = p->left;
			} else {
				struct bst *q = bst_create(data);
				if(!q) {
					return -1;
				}
				p->left = q;
				return 0;
			}
		} else {
			if(p->right) {
				p = p->right;
			} else {
				struct bst *q = bst_create(data);
				if(!q) {
					return -1;
				}
				p->right = q;
				return 0;
			}
		}
	}
	return -1;
}

/*
delete a node
*/
int bst_remove(struct bst *root, int data) {
	return 0;
}

int bst_search(struct bst *root, int data) {
	struct bst *p = root;	
	while(p) {
		if(p->data == data) {
			return 0;
		} else if(p->data > data) {
			if(p->left) p = p->left;
			else return -1;
		} else {
			if(p->right) p = p->right;
			else return -1;
		}
	}
	return -1;
}

void bst_print_inorder(struct bst *root) {
	if(!root) return;
	if(root->left) bst_print_inorder(root->left);
	printf("%d ", root->data);
	if(root->right) bst_print_inorder(root->right);
}


struct bst *bst_build(int *x, int n) {
	struct bst *root;
	if(n == 0) return NULL;
	root = bst_create(*x);
	if(!root) return NULL;

	x++;
	n--;
	while(n>0) {
		if(bst_insert(root, *x)) {
			bst_destroy(root);
			return NULL;
		}
		x++;
		n--;
	}

	return root;
}

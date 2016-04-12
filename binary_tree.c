#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "binary_tree.h"

struct btree *btree_create(void *data, type_t type, int int_data) {
	struct btree *node = malloc(sizeof(struct btree));
	if(!node) {
		fprintf(stderr, "malloc failed: %s!\n", strerror(errno));
		return NULL;
	}

	node->data = data;
	node->type = type;
	node->int_data = int_data;
	node->left = node->right = NULL;
	return node;
}

void btree_setleft(struct btree *parent, struct btree *left) {
	assert(parent);
	parent->left = left;
}

void btree_setright(struct btree *parent, struct btree *right) {
	assert(parent);
	parent->right = right;
}

static void print_data(struct btree *node) {
	switch(node->type) {
	case TYPE_INT:
		fprintf(stdout, "%d\n", node->int_data);
		break;
	case TYPE_STR:	
		fprintf(stdout, "%s\n", (char *)(node->data));
		break;
	default:
		break;
	}
	return;
}

void btree_preorder(struct btree *root) {
	if(!root) return;
	print_data(root);
	btree_preorder(root->left);		
	btree_preorder(root->right);		
}

void btree_postorder(struct btree *root) {
	if(!root) return;
	btree_postorder(root->left);		
	btree_postorder(root->right);		
	print_data(root);
}

void btree_inorder(struct btree *root) {
	if(!root) return;
	btree_inorder(root->left);		
	print_data(root);
	btree_inorder(root->right);		
}


void btree_destroy(struct btree *root) {
	if(!root) return;
	btree_destroy(root->left);	
	btree_destroy(root->right);	
	free(root);
}

int btree_search(struct btree *root, struct btree *target) {
	if(!root || !target) return 0;

	if(root == target) return 1;

	return btree_search(root->left, target) || btree_search(root->right, target);
}

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

struct btree_p *btree_p_create(void *data, type_t type, int int_data) {
	struct btree_p *node = malloc(sizeof(struct btree_p));
	if(!node) {
		fprintf(stderr, "malloc failed: %s!\n", strerror(errno));
		return NULL;
	}

	node->data = data;
	node->type = type;
	node->int_data = int_data;
	node->left = node->right = node->parent = NULL;
	return node;
}

void btree_setleft(struct btree *parent, struct btree *left) {
	assert(parent);
	parent->left = left;
}

void btree_p_setleft(struct btree_p *parent, struct btree_p *left) {
	assert(parent);
	assert(left);
	parent->left = left;
	left->parent = parent;
}

void btree_setright(struct btree *parent, struct btree *right) {
	assert(parent);
	parent->right = right;
}

void btree_p_setright(struct btree_p *parent, struct btree_p *right) {
	assert(parent);
	assert(right);
	parent->right = right;
	right->parent = parent;
}

static void print_data_btree(struct btree *node) {
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

static void print_data_btree_p(struct btree_p *node) {
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
	print_data_btree(root);
	btree_preorder(root->left);		
	btree_preorder(root->right);		
}

void btree_p_preorder(struct btree_p *root) {
	if(!root) return;
	print_data_btree_p(root);
	btree_p_preorder(root->left);		
	btree_p_preorder(root->right);		
}

void btree_postorder(struct btree *root) {
	if(!root) return;
	btree_postorder(root->left);		
	btree_postorder(root->right);		
	print_data_btree(root);
}

void btree_p_postorder(struct btree_p *root) {
	if(!root) return;
	btree_p_postorder(root->left);		
	btree_p_postorder(root->right);		
	print_data_btree_p(root);
}

void btree_inorder(struct btree *root) {
	if(!root) return;
	btree_inorder(root->left);		
	print_data_btree(root);
	btree_inorder(root->right);		
}

void btree_p_inorder(struct btree_p *root) {
	if(!root) return;
	btree_p_inorder(root->left);		
	print_data_btree_p(root);
	btree_p_inorder(root->right);		
}

void btree_destroy(struct btree *root) {
	if(!root) return;
	btree_destroy(root->left);	
	btree_destroy(root->right);	
	free(root);
}

void btree_p_destroy(struct btree_p *root) {
	if(!root) return;
	btree_p_destroy(root->left);	
	btree_p_destroy(root->right);	
	free(root);
}

int btree_search(struct btree *root, struct btree *target) {
	if(!root || !target) return 0;

	if(root == target) return 1;

	return btree_search(root->left, target) || btree_search(root->right, target);
}

int btree_p_search(struct btree_p *root, struct btree_p *target) {
	if(!root || !target) return 0;

	if(root == target) return 1;

	return btree_p_search(root->left, target) || btree_p_search(root->right, target);
}

#include <stdio.h>

#include "binary_tree.h"

/*
 * return the command ancestor if found, otherwise return NULL.
 */
struct btree *common_ancestor(struct btree *root, struct btree *node1, struct btree *node2) {
	int r1, r2;

	if(!node1 || !node2) return NULL;

	if(!btree_search(root, node1) || !btree_search(root, node2)) return NULL;

	if(root == node1 || root == node2) return root;

	r1 = btree_search(root->left, node1);
	r2 = btree_search(root->left, node2);
	
	if(r1 == 1 && r2 == 1) 
		return common_ancestor(root->left, node1, node2);
	else if(r1 == 0 && r2 == 0) 
		return common_ancestor(root->right, node1, node2);
	else 
		return root;
}

int main() {
	struct btree *node1 = btree_create(NULL, TYPE_INT, 1);
	struct btree *node2 = btree_create(NULL, TYPE_INT, 2);
	struct btree *node3 = btree_create(NULL, TYPE_INT, 3);
	struct btree *node4 = btree_create(NULL, TYPE_INT, 4);
	struct btree *node5 = btree_create(NULL, TYPE_INT, 5);
	struct btree *node6 = btree_create(NULL, TYPE_INT, 6);
	struct btree *node7 = btree_create(NULL, TYPE_INT, 7);
	struct btree *node8 = btree_create(NULL, TYPE_INT, 8);
	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node5;
	node3->left = node6;
	node3->right = node7;
	node4->left = node8;

	fprintf(stdout, "preorder:\n");
	btree_preorder(node1);

	fprintf(stdout, "postorder:\n");
	btree_postorder(node1);

	fprintf(stdout, "inorder:\n");
	btree_inorder(node1);
	
	fprintf(stdout, "btree_search(node5, node8) = %d\n", btree_search(node5, node8));	
	fprintf(stdout, "btree_search(node4, node8) = %d\n", btree_search(node4, node8));	


	fprintf(stdout, "common_ancestor(node1, node1, node8) = %d\n", common_ancestor(node1, node1, node8)->int_data);
	fprintf(stdout, "common_ancestor(node1, node4, node8) = %d\n", common_ancestor(node1, node4, node8)->int_data);
	fprintf(stdout, "common_ancestor(node1, node5, node8) = %d\n", common_ancestor(node1, node5, node8)->int_data);
	fprintf(stdout, "common_ancestor(node1, node7, node8) = %d\n", common_ancestor(node1, node7, node8)->int_data);
	fprintf(stdout, "common_ancestor(node1, node7, node6) = %d\n", common_ancestor(node1, node7, node6)->int_data);
	fprintf(stdout, "common_ancestor(node1, node2, node6) = %d\n", common_ancestor(node1, node2, node6)->int_data);
	btree_destroy(node1);
}

// gcc --std=c99 -pedantic -Wall -iquote ../ 4_8.c ../binary_tree.c

#include <stdio.h>

#include "binary_tree.h"

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

	btree_destroy(node1);
}

#include <stdio.h>

#include "binary_tree.h"

void btree_test() {
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

	btree_destroy(node1);
}

void btree_p_test() {
	struct btree_p *node1 = btree_p_create(NULL, TYPE_INT, 1);
	struct btree_p *node2 = btree_p_create(NULL, TYPE_INT, 2);
	struct btree_p *node3 = btree_p_create(NULL, TYPE_INT, 3);
	struct btree_p *node4 = btree_p_create(NULL, TYPE_INT, 4);
	struct btree_p *node5 = btree_p_create(NULL, TYPE_INT, 5);
	struct btree_p *node6 = btree_p_create(NULL, TYPE_INT, 6);
	struct btree_p *node7 = btree_p_create(NULL, TYPE_INT, 7);
	struct btree_p *node8 = btree_p_create(NULL, TYPE_INT, 8);
	btree_p_setleft(node1, node2);
	btree_p_setright(node1, node3);
	btree_p_setleft(node2, node4);
	btree_p_setright(node2, node5);
	btree_p_setleft(node3, node6);
	btree_p_setright(node3, node7);
	btree_p_setleft(node4, node8);

	fprintf(stdout, "preorder:\n");
	btree_p_preorder(node1);

	fprintf(stdout, "postorder:\n");
	btree_p_postorder(node1);

	fprintf(stdout, "inorder:\n");
	btree_p_inorder(node1);
	
	fprintf(stdout, "btree_p_search(node5, node8) = %d\n", btree_p_search(node5, node8));	
	fprintf(stdout, "btree_p_search(node4, node8) = %d\n", btree_p_search(node4, node8));	

	btree_p_destroy(node1);
}

int main() {
	btree_test();
	btree_p_test();
}
// gcc --std=c99 -pedantic -Wall binary_tree_test.c binary_tree.c

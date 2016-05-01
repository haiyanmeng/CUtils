#ifndef BST_H
#define BST_H

struct bst {
	int data;
	struct bst *left, *right;
};

struct bst *bst_create(int data);

void bst_destroy(struct bst *root);

int bst_insert(struct bst *root, int data);

int bst_remove(struct bst *root, int data);

/* bst_search checks whether data is in the bst.
 * return 0 if data is in the bst; return non-zero if data is not in the bst.
 */
int bst_search(struct bst *root, int data);

void bst_print_inorder(struct bst *root);

struct bst *bst_build(int *x, int n);
#endif

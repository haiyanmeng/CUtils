#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef enum {TYPE_INT, TYPE_STR} type_t;

struct btree {
	type_t type;
	void *data;
	int int_data;
	struct btree *left;
	struct btree *right;
};

struct btree *btree_create(void *data, type_t type, int int_data);

void btree_setleft(struct btree *parent, struct btree *left);

void btree_setright(struct btree *parent, struct btree *right);

void btree_preorder(struct btree *root);

void btree_postorder(struct btree *root);

void btree_inorder(struct btree *root);

void btree_destroy(struct btree *root);

#endif

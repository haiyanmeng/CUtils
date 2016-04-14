#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef enum {TYPE_INT, TYPE_STR} type_t;
typedef enum {BTREE_NODE, BTREE_P_NODE} node_t;

struct btree {
	type_t type;
	void *data;
	int int_data;
	struct btree *left;
	struct btree *right;
};

/* btree_p maintains a pointer to its parent node */
struct btree_p {
	type_t type;
	void *data;
	int int_data;
	struct btree_p *left;
	struct btree_p *right;
	struct btree_p *parent;
};

struct btree *btree_create(void *data, type_t type, int int_data);

struct btree_p *btree_p_create(void *data, type_t type, int int_data);

void btree_setleft(struct btree *parent, struct btree *left);

void btree_p_setleft(struct btree_p *parent, struct btree_p *left);

void btree_setright(struct btree *parent, struct btree *right);

void btree_p_setright(struct btree_p *parent, struct btree_p *right);

void btree_preorder(struct btree *root);

void btree_p_preorder(struct btree_p *root);

void btree_postorder(struct btree *root);

void btree_p_postorder(struct btree_p *root);

void btree_inorder(struct btree *root);

void btree_p_inorder(struct btree_p *root);

void btree_destroy(struct btree *root);

void btree_p_destroy(struct btree_p *root);

/* btree_search searches target in the root btree.
 * return 1 if target is found, return 0 if not found.
 */
int btree_search(struct btree *root, struct btree *target);

int btree_p_search(struct btree_p *root, struct btree_p *target);

#endif

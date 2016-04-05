#ifndef LIST_H
#define LIST_H

enum data_type {TYPE_INT, TYPE_STR};
typedef enum data_type type_t;

struct node {
	type_t type;
	int int_data;
	void *data;
	struct node *next;
};

/* create a list
 * @param data: a pointer to the real data
 * @param type: the type of the data pointed by the data param
 * @param int_data: the integer data value
 * return the newly added node on success, return NULL on failure.
 */
struct node *list_create(void *data, type_t type, int int_data);

/* insert at the end of a list
 * @param list: the tail node of a list
 * @param data: a pointer to the real data
 * @param type: the type of the data pointed by the data param
 * @param int_data: the integer data value
 * return the new tail node (i.e., the newly added node) on success, return NULL on failure.
 */
struct node *list_add(struct node *list, void *data, type_t type, int int_data);

/* destroy a list */
void list_destroy(struct node *list);

void list_traverse(struct node *list);

struct node *list_reverse(struct node *list);

#endif

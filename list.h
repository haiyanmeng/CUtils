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

struct list {
	struct node *head;
	struct node *tail;
};

/* create a list
 * return a new list on success, return NULL on failure.
 */
struct list *list_create(void);

/* insert at the end of a list
 * @param list: the tail node of a list
 * @param data: a pointer to the real data
 * @param type: the type of the data pointed by the data param
 * @param int_data: the integer data value
 * return 0 on success, return non-zero on failure.
 */
int list_append(struct list*list, void *data, type_t type, int int_data);

/* destroy a list */
void list_destroy(struct list*list);

void list_traverse(struct list*list);

int list_reverse(struct list*list);

#endif

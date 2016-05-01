#include <stdio.h>
#include "bst.h"

int main(void) {
	int arr[] = {10, 5, 15, 3, 1, 4, 7, 9, 13, 11, 14, 19, 18};
	struct bst *root = bst_build(arr, sizeof(arr)/sizeof(int));
	if(!root) return 0;
	bst_print_inorder(root);
	bst_destroy(root);
	return 0;
}

/* output:
1 3 4 5 7 9 10 11 13 14 15 18 19
*/

// gcc -g3 -std=c99 -pedantic -Wall bst_test.c bst.c

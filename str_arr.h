#ifndef STR_ARR_H
#define STR_ARR_H

typedef struct str_arr {
	int n; // the number of elements the arr can hold 
	int c; // the current number of elements in the arr
	char **a; // a pointer to the array elements
} str_arr;

str_arr *str_arr_create(int n);

void str_arr_destroy(str_arr *s);

int str_arr_insert(str_arr *s, const char *t);

void str_arr_print(str_arr *s);

#endif

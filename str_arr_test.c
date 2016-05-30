#include <stdio.h>
#include "str_arr.h"

int main(void) {
	str_arr *s = str_arr_create(3);
	str_arr_insert(s, "hello");	
	str_arr_insert(s, "world");	
	str_arr_insert(s, "Haiyan Meng");	
	str_arr_insert(s, "extra");	
	str_arr_print(s);
	str_arr_destroy(s);
	return 0;
}

/* 
gcc -g3 -Wall -pedantic str_arr.c str_arr_test.c
*/

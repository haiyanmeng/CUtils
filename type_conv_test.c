#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "type_conv.h"

int main(void) {
	char arr[5];
	char *s = int_to_str(-123);
	snprintf(arr, 5, "%s", s);
	assert(!strcmp(arr, "-123"));
	free(s);
	return 0;
}

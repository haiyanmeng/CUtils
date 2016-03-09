#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "type_conv.h"

int main(void) {
	char arr[5];
	snprintf(arr, 5, "%s", int_to_str(-123));
	assert(!strcmp(arr, "-123"));
	return 0;
}

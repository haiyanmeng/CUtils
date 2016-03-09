#include <stdio.h>
#include <stdlib.h>
#include "type_conv.h"

char *int_to_str(int n) {
	int len = snprintf(NULL, 0, "%d", n);
	char *s = malloc(len + 1);
	snprintf(s, len+1, "%d", n);
	return s;
}

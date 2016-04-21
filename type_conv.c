#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "type_conv.h"

char *int_to_str(int n) {
	int len = snprintf(NULL, 0, "%d", n);
	char *s = malloc(len + 1);
	if(!s) {
		fprintf(stderr, "malloc failed: %s!", strerror(errno));
		return NULL;
	}
	snprintf(s, len+1, "%d", n);
	return s;
}

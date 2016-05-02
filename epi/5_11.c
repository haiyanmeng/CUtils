#include <stdio.h>

typedef struct rect {
	int x, y;
	int w, h;
} rect;


void intersect(rect *r1, rect *r2, rect *r3) {
	int t;
	if(r2->x > r1->x + r1->w || r2->x + r2->w < r1->x || r2->y > r1->y + r1->h || r2->y + r2->h < r1->y) {
		r3->x = r3->y = r3->w = r3->h = 0;
		return;
	}

	r3->x = r2->x > r1->x ? r2->x : r1->x;
	r3->y = r2->y > r1->y ? r2->y : r1->y;

	t = (r2->x + r2->w) < (r1->x + r1->w) ? (r2->x + r2->w) : (r1->x + r1->w);
	r3->w = t - r3->x;

	t = (r2->y + r2->h) < (r1->y + r1->h) ? (r2->y + r2->h) : (r1->y + r1->h);
	r3->h = t - r3->y;
}

void print_rect(rect *r) {
	fprintf(stdout, "rect->x = %d; rect->y = %d; rect->w = %d; rect->h = %d\n", r->x, r->y, r->w, r->h);
}

void rect_init(rect *r, int x, int y, int w, int h) {
	r->x = x; r->y = y; r->w = w; r->h = h;
}

void intersect_test(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {
	rect r1, r2, r3;
	rect_init(&r1, x1, y1, w1, h1);
	rect_init(&r2, x2, y2, w2, h2);
	intersect(&r1, &r2, &r3);
	print_rect(&r3);
}

int main(void) {
	intersect_test(3, 5, 3, 3, 7, 8, 3, 5);
	intersect_test(7, 8, 3, 5, 3, 5, 3, 3);
	intersect_test(2, 4, 3, 5, 3, 5, 3, 3);
	intersect_test(3, 5, 3, 3, 2, 4, 3, 5);
	intersect_test(4, 0, 4, 10, 2, 2, 10, 2);
	intersect_test(2, 2, 10, 2, 4, 0, 4, 10);
	
	return 0;
}

/* output:
rect->x = 0; rect->y = 0; rect->w = 0; rect->h = 0
rect->x = 0; rect->y = 0; rect->w = 0; rect->h = 0
rect->x = 3; rect->y = 5; rect->w = 2; rect->h = 3
rect->x = 3; rect->y = 5; rect->w = 2; rect->h = 3
rect->x = 4; rect->y = 2; rect->w = 4; rect->h = 2
rect->x = 4; rect->y = 2; rect->w = 4; rect->h = 2
*/

// gcc -g3 -Wall -std=c99 -pedantic 5_11.c

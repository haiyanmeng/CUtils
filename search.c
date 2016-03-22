#include "search.h"

int binary_search_rec(int *a, int l, int r, int target) {
	int m;

	if(target < a[l] || target > a[r]) return -1;
	
	while(l <= r) {
		m = (l+r)/2;	
		if(a[m] == target) 
			return m;
		else if(a[m] > target) {
			return binary_search_rec(a, l, m-1, target);
		} else {
			return binary_search_rec(a, m+1, r, target);
		}
	}

	return -1;
}

int binary_search_iter(int *a, int n, int target) {
	int l, r, m;
	l = 0; 
	r = n - 1; 

	if(target < a[0] || target > a[n-1]) return -1;
	
	while(l <= r) {
		m = (l+r)/2;	
		if(a[m] == target) 
			return m;
		else if(a[m] > target) {
			r = m - 1;
		} else {
			l = m + 1;
		}
	}

	return -1;
}

int binary_search(int *a, int n, int target) {
	//return binary_search_iter(a, n, target);
	return binary_search_rec(a, 0, n-1, target);
}


#include <stdlib.h>
#include <stdio.h>
#include "aint_array.h"
#include "algorithm.h"
#include "build_tree.h"

#define left_child (nod * 2)
#define right_child (left_child | 1)

int query_and_update_tree(int nod, int left, int right, int nr) {
	if (left == right) {
		aint[nod] = 0;
		return left;
	}

	int mid = (left + right) / 2;

	int pos = 0;

	if (nr <= aint[left_child]) 
		pos = query_and_update_tree(left_child, left, mid, nr);
	else 
		pos = query_and_update_tree(right_child, mid + 1, right, nr - aint[left_child]);

	aint[nod] = aint[left_child] + aint[right_child];

	return pos;
}

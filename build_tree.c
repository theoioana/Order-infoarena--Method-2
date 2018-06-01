#include <stdlib.h>
#include <stdio.h>
#include "aint_array.h"
#include "algorithm.h"
#include "query_and_update_tree.h"

#define left_child (nod * 2)
#define right_child (left_child | 1)

void build_tree(int nod, int left, int right) {
	if (left == right) {
		aint[nod] = 1;
		return 0;
	}

	int mid;
	mid = (left + right) / 2;

	build_tree(left_child, left, mid);
	build_tree(right_child, mid + 1, right);

	aint[nod] = aint[left_child] + aint[right_child];
}
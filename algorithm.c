#include <stdlib.h>
#include <stdio.h>
#include "aint_array.h"
#include "build_tree.h"
#include "query_and_update_tree.h"

#define left_child (nod * 2)
#define right_child (left_child | 1)

void function(int ith_child, int remaining_children, int n) {
	int i;
	for (i = 1; i <= n; ++i) {
		ith_child = (ith_child + i) % remaining_children;
		if (ith_child == 0) ith_child = remaining_children;
		--remaining_children;

		printf( " %d", query_and_update_tree(1, 1, n, ith_child) );
		--ith_child;
	}
}
#include <stdlib.h>
#include <stdio.h>
#include "aint_array.h"
#include "algorithm.h"
#include "build_tree.h"
#include "query_and_update_tree.h"

int aint[30005 * 4];
int vec[30005];

int main(){

	int n;

	n = 6;

	build_tree(1, 1, n); 

	int ith_child = 1;
	int remaining_children = n;

	function(ith_child, remaining_children, n);

	//system("pause");
	return 0;
}

/**
* @file main.c
* @brief C library implementation that solves the problem Order (Infoarena) using Segment Trees
* @author Theodora Danciulescu
* @date 06/05/18.
*/

#include <stdlib.h>
#include <stdio.h> /// > printf()
#include "aint_array.h" /// > aint[30005 * 4], vec[30005]
#include "algorithm.h" /// > function()
#include "build_tree.h" /// > build_tree()
#include "query_and_update_tree.h" /// query_and_update_tree()

int aint[30005 * 4];
int vec[30005];

/**
* @fn int main()
* @author Theodora Danciulescu
* @brief Main function.
* @Function calls of build_tree and function imported from build+_tree.h and respectively from algorithm.h and initializes some variables
*/

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

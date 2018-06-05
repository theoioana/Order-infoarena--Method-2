/**
* @file algorithm.c
* @brief C library implementation that solves the problem on the support of the data generated in the segment tree 
* @author Theodora Danciulescu
* @date 06/05/18.
*/
#include <stdlib.h>
#include <stdio.h> /// > printf()
#include "aint_array.h" /// > aint[30005 * 4] , vec[300005]
#include "build_tree.h" /// > build_tree()
#include "query_and_update_tree.h" /// > query_and_update_tree()

#define left_child (nod * 2)
#define right_child (left_child | 1)

/**
* @left_child formula for accesing the left child of the node
* @right_child formula for accesing the right child of the node
* @author Theodora Danciulescu
* @date 06/05/18.
*/

/**
* This function calculates the initial position of the child to be eliminated at a certain step
* @param ith_child will represent the child where we start the counting from
* @param remaining_children will represent the number of children that still are in the game
* @param n will represent the initial number of children and also the number of steps in the game
* @author Theodora Danciulescu
* @date 06/05/18.
*/

void function(int ith_child, int remaining_children, int n) {
	int i;
	for (i = 1; i <= n; ++i) {
		/// since the counting is circular we use modulo the get rid of dirt
		ith_child = (ith_child + i) % remaining_children;
		if (ith_child == 0)
			ith_child = remaining_children;
		/// decrease the number of remaining children
		--remaining_children;
		
		/// printing the position returned by the function query_and_update_tree
		printf( " %d", query_and_update_tree(1, 1, n, ith_child) );
		--ith_child;
	}
}
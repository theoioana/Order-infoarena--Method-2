/**
* @file build_tree.c
* @brief C library implementation that initializes the segment tree
* @author Theodora Danciulescu
* @date 06/05/18.
*/

#include <stdlib.h>
#include <stdio.h>
#include "aint_array.h"
#include "algorithm.h"
#include "query_and_update_tree.h"

#define left_child (nod * 2)
#define right_child (left_child | 1)

/**
* @left_child formula for accesing the left child of the node
* @right_child formula for accesing the right child of the node
* @author Theodora Danciulescu
* @date 06/05/18.
*/

/**
* This function builds a segment tree in  which  a  node’s  information  represents  how  many  children  from  
that  node’s  interval  are  still  in  the  circle
* @param nod will represent the node we start from
* @param left will represent the left bound of the interval to be initialized
* @param right will represent he right bound of the interval to be initialized
* @author Theodora Danciulescu
* @date 06/05/18.
*/

void build_tree(int nod, int left, int right) {
	if (left == right) {
		aint[nod] = 1;
		return 0;
	}

	int mid;
	mid = (left + right) / 2;

	/// recursive calls of the function build_tree for updating the left and right intervals 
	build_tree(left_child, left, mid);
	build_tree(right_child, mid + 1, right);

	aint[nod] = aint[left_child] + aint[right_child];
}
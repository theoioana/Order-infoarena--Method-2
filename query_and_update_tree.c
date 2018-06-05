/**
* @file query_and_update_tree.c
* @brief C library implementation that solves the problem on the support of the data generated in the segment tree
* @author Theodora Danciulescu
* @date 06/05/18.
*/

#include <stdlib.h>
#include <stdio.h> /// > printf()
#include "aint_array.h" /// > aint[30005 * 4], vec[30005]
#include "algorithm.h" /// > function()
#include "build_tree.h" /// > build_tree()

#define left_child (nod * 2)
#define right_child (left_child | 1)

/**
* @param left_child formula for accesing the left child of the node
* @param right_child formula for accesing the right child of the node
* @author Theodora Danciulescu
* @date 06/05/18.
*/

/**
* This function calculates returns initial position of the child to be eliminated at a certain step and accordingly
updates and queries the segment tree
* @param nod will represent the node we start to make the two operations of update and query
* @param left will represent the left bound of the interval to be querried and updated
* @param right will represent the right bound of the interval to be querried and updated
* @param position will represent the position of the searched child 
* @author Theodora Danciulescu
* @date 06/05/18.
*/

int query_and_update_tree(int nod, int left, int right, int position) {
	/// the case we have an interval of length 1
	if (left == right) {
		aint[nod] = 0;
		return left;
	}

	int mid = (left + right) / 2;

	int pos = 0;

	/// if there are enough children in the left half go look for the searched child in this half
	if (nr <= aint[left_child]) {
		pos = query_and_update_tree(left_child, left, mid, position);

	}
	else {
		/// otherwise go look for the searched child in the remaining right half 
		pos = query_and_update_tree(right_child, mid + 1, right, position - aint[left_child]);
	}

	/// do the correspondent update at the node
	aint[nod] = aint[left_child] + aint[right_child];

	/// return the initial position of the child that is eliminated at a certain step
	return pos;
}

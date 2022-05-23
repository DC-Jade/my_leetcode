#ifndef INCLUDE_TREE_NODE_H
#define INCLUDE_TREE_NODE_H

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : var(0), left(nullptr), right(nullptr) {}
	TreeNode(int i) : var(i), left(nullptr), right(nullptr) {}
	TreeNode(int i, TreeNode *left, TreeNode *right) :
		var(i), left(left), right(right) {}
};	/* class TreeNode */

#endif

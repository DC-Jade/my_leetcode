#include <stdio.h>

#include <vector>
#include <ctime>

#include "../include/TreeNode.hpp"

using std::vector;

int RangeSumBST(TreeNode *root, int low, int high);

int SolutionOne(TreeNode *root, int low, int high) {
	if (root == nullptr) return 0;
	if (root->val < low)	return SolutionOne(root->right, low, high);
	if (root->val > high)	return SolutionOne(root->left, low, high);
	return ( root->val + SolutionOne(root->left, low, high) +
		SolutionOne(root->right, low, high) );
}

int Solution(TreeNode *node, int low, int high) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1: return SolutionOne(node, low, high);
	}
	return -1;
}

void Test00938() {
	vector<int> iv = {10, 5, 15, 3, 7, nullptr, 18};
}


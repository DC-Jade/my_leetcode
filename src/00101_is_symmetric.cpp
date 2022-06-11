#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "../include/TreeNode.hpp"  
#include "../include/BinTree.hpp"

using mydatastructure::BinTree;
using mydatastructure::TreeNode;

#define TreeNode TreeNode<int>

bool SolutionOne(TreeNode *p, TreeNode *q);
bool Solution(TreeNode *p, TreeNode *q);

bool SolutionOne(TreeNode *p, TreeNode *q) {
	if (!p && !q) return true;
	else if (!p || !q) return false;
	else if (p->val != q->val) return false;
	return SolutionOne(p->left, q->right) && SolutionOne(p->right, q->left);
}

bool Solution(TreeNode *p, TreeNode *q) {
	switch (rand() % 1) {
		// case 1: printf("SolutionTwo\n"); return SolutionTwo(p, q); break;
		// case 2: printf("SolutionThree\n"); return SolutionThree(p, q); break;
		default: printf("\nSolutionOne"); return SolutionOne(p, q); break;
	}
}

void Test00100() {
	srand(time(nullptr));
	BinTree<int> bt_one;
	bt_one.InsertAsRoot(1);
	bt_one.InsertAsRC(bt_one.Root(), 2);
	bt_one.InsertAsLC(bt_one.Root(), 2);
	// iv = Solution(bt_two.Root());
	bool res = Solution(bt_one.Root(), bt_one.Root());
	res ? printf("\nsymmetric") : printf("\nnot symmetric");
	printf("\nend of Test00100");
}

int main() {
	Test00100();
}

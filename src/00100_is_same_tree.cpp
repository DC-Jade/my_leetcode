#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <stack>

#include "../include/TreeNode.hpp"  
#include "../include/BinTree.hpp"

using std::vector;
using std::stack;
using mydatastructure::BinTree;
using mydatastructure::TreeNode;

#define TreeNode TreeNode<int>

bool SolutionOne(TreeNode *p, TreeNode *q);
/* pass iv by function */
// vector<int> SolutionTwo(TreeNode *p, TreeNode *q);
/* traversal by iteration */
// vector<int> SolutionThree(TreeNode *p, TreeNode *q);
bool Solution(TreeNode *p, TreeNode *q);

bool SolutionOne(TreeNode *p, TreeNode *q) {
	if (p == nullptr && q == nullptr) return true;
	else if (p == nullptr || q == nullptr) return false;
	else if (p->val != q->val) return false;
	return SolutionOne(p->left, q->left) && SolutionOne(p->right, q->right);
}

bool Solution(TreeNode *p, TreeNode *q) {
	switch (rand() % 2 + 1) {
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
	bt_one.InsertAsLC(bt_one.Root()->right, 3);
	// vector<int> iv;
	BinTree<int> bt_two;
	bt_two.InsertAsRoot(1);
	bt_two.InsertAsRC(bt_two.Root(), 2);
	bt_two.InsertAsLC(bt_two.Root()->right, 3);
	bt_two.InsertAsLC(bt_two.Root()->right->left, 4);
	// iv = Solution(bt_two.Root());
	bool res = Solution(bt_one.Root(), bt_two.Root());
	res ? printf("\nequal") : printf("\nnot equal");
	printf("\nend of Test00100");
}

int main() {
	Test00100();
}

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

vector<int> InorderTraversal(TreeNode* root);
vector<int> SolutionOne(TreeNode *root);
/* pass iv by function */
vector<int> SolutionTwo(TreeNode *root);
/* traversal by iteration */
vector<int> SolutionThree(TreeNode *root);
vector<int> Solution(TreeNode *root);

vector<int> iv;
vector<int> SolutionOne(TreeNode *root) {
	if (!root) return {};
	SolutionOne(root->left);
	iv.push_back(root->val);
	SolutionOne(root->right);
	return iv;
}

static void TraversalInRecursion(TreeNode *pbn, vector<int> &iv) {
	if (!pbn) return;
	TraversalInRecursion(pbn->left, iv);
	iv.push_back(pbn->val);
	TraversalInRecursion(pbn->right, iv);
}

vector<int> SolutionTwo(TreeNode *root) {
	vector<int> res;
	TraversalInRecursion(root, res);
	return res;
}

static void GoAlongLeftBranch(TreeNode *pbn, stack<TreeNode*> &s_pbn) {
	if (!pbn) return;
	while (pbn) {
		s_pbn.emplace(pbn);
		pbn = pbn->left;
	}
}

vector<int> SolutionThree(TreeNode *root) {
	vector<int> iv;
	TreeNode *pbn = root;
	stack<TreeNode*> s_pbn;
	while (1) {
		GoAlongLeftBranch(pbn, s_pbn);
		if (s_pbn.empty()) break;
		pbn = s_pbn.top();
		iv.push_back(pbn->val);
		s_pbn.pop();
		pbn = pbn->right;
	}
	return iv;
}

vector<int> Solution(TreeNode *root) {
	switch (rand() % 2 + 1) {
		case 1: printf("SolutionTwo\n"); return SolutionTwo(root); break;
		case 2: printf("SolutionThree\n"); return SolutionThree(root); break;
		default: printf("SolutionOne\n"); return SolutionOne(root); break;
	}
}

void Test00094() {
	srand(time(nullptr));
	BinTree<int> bt;
	bt.InsertAsRoot(1);
	bt.InsertAsRC(bt.Root(), 2);
	bt.InsertAsLC(bt.Root()->right, 3);
	vector<int> iv;
	iv = Solution(bt.Root());
	for (auto &i : iv) printf("%d ", i);
	printf("\nend of Test00094");
	// Solution()
}

int main() {
	Test00094();
}

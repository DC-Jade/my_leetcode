#include <cstdio>
#include <ctime>
#include <algorithm>

#include <vector>
#include <string>

#include "../include/TreeNode.hpp"
#include "../include/BinTree.hpp"

using std::vector;
using std::string;
using mydatastructure::TreeNode;
using mydatastructure::BinTree;

#define TreeNode TreeNode<int>

vector<string> BinaryTreePaths(TreeNode *root);
vector<string> SolutionOne(TreeNode *root);
vector<string> Solution(TreeNode *root);

void TraversalRecursion(TreeNode *root, string path, vector<string> &vstr) {
	// if (!root) return;
	// vstr.push_back(std::to_string(root->val) + "->");
	// return TraversalRecursion(root->left, vstr);
	// if (!root->right) vstr.push_back(std::to_string(root->val) + "->");
	// return TraversalRecursion(root->right, vstr);
	
	// string path = "";
	if (root) {
		path += std::to_string(root->val);
		/* leaf node */
		if (!root->left && !root->right) {
			vstr.push_back(path);
		} else {
		path += "->";
			TraversalRecursion(root->left, path, vstr);
			TraversalRecursion(root->right, path, vstr);
		}
	}
}

vector<string> SolutionOne(TreeNode *root) {
	vector<string> vstr;
	string path = "";
	TraversalRecursion(root, path, vstr);
	return vstr;
}

vector<string> Solution(TreeNode *root) {
	switch (rand() % 1) {
		default: printf("SolutionOne\n"); return SolutionOne(root);
	}
}
	
void Test00257() {
	BinTree<int> bt;
	bt.InsertAsRoot(1);
	bt.InsertAsLC(bt.Root(), 2);
	bt.InsertAsRC(bt.Root(), 3);
	bt.InsertAsRC(bt.Root()->left, 5);
	vector<string> vstr;
	vstr = Solution(bt.Root());
	for (auto &str : vstr) printf("%s\n", str.c_str());
}

int main() {
	Test00257();
}

#ifndef INCLUDE_BINNODE_H
#define INCLUDE_BINNODE_H

#include "../include/Queue.hpp"
#include "../include/Stack.hpp"

namespace mydatastructure {
#define TreeNodePosi(T) TreeNode<T>*

typedef enum { RB_RED, RB_BLACK } RBColor;

template <typename T>
class TreeNode {
public:
	/* constructor */
	TreeNode();
	TreeNode(T e, TreeNodePosi(T) parent = nullptr, TreeNodePosi(T) lc = nullptr,
		TreeNodePosi(T) rc = nullptr, int height = 0, int npl = 1,
		RBColor color = RB_RED);

	/* interface */
	int Size();	/* the number of whole child nodes  */
	TreeNodePosi(T) InsertAsLC(const T &e);
	TreeNodePosi(T) InsertAsRC(const T &e);
	TreeNodePosi(T) Succ();
	template <typename VST>
	void TravelLevel(VST &visit);
	template <typename VST>
	void TravelPre(VST &visit);
	template <typename VST>
	void TravelIn(VST &visit);
	template <typename VST>
	void TravelPost(VST &visit);

	bool operator==(const TreeNode &bin_node);
	bool operator<(const TreeNode &bin_node);
	bool operator>(const TreeNode &bin_node);

	/* data member */
	T val;
	TreeNodePosi(T) _parent; TreeNodePosi(T) left; TreeNodePosi(T) right;
	int _height;
	int _npl;	/* null path length, similar to _height */
	RBColor _color; 

};	/* class TreeNode<T> */

/* function member */
template <typename T>
TreeNode<T>::TreeNode() :
	val(T()), _parent(nullptr), left(nullptr), right(nullptr),
	_height(0), _npl(0), _color(RB_RED) { }

// template <typename T>
// TreeNode<T>::TreeNode(T e, TreeNodePosi(T) parent = nullptr,
//   TreeNodePosi(T) lc = nullptr, TreeNodePosi(T) rc = nullptr,
//   int height = 0, int npl = 1, RBColor color = RB_RED) : val(e) { }

template <typename T>
TreeNode<T>::TreeNode(T data, TreeNodePosi(T) parent, TreeNodePosi(T) lc,
	TreeNodePosi(T) rc, int height, int npl, RBColor color) :
	val(data), _parent(parent), left(lc), right(rc), _height(height),
	_npl(npl), _color(color) { } 

template <typename T>
TreeNodePosi(T) TreeNode<T>::InsertAsLC(const T &e) {
	return left = new TreeNode<T>(e, this);
} 

template <typename T>
TreeNodePosi(T) TreeNode<T>::InsertAsRC(const T &e) {
	return right = new TreeNode<T>(e, this);
} 

template <typename T>
TreeNodePosi(T) TreeNode<T>::Succ() {
	TreeNodePosi(T) successor = this;
	if (right) { 
		successor = right;
		while (HasLChild(*successor)) { successor = successor->left; }
	} else {
		while (IsRChild(*successor)) { successor = successor->_parent; }
		successor = successor->_parent;
	}
	return successor;
}

template <typename T> template <typename VST>
void TreeNode<T>::TravelLevel(VST &visit) {
	Queue<TreeNodePosi(T)> q_pbn;
	q_pbn.Enqueue(this);
	TreeNodePosi(T) pbn;
	while (!q_pbn.Empty()) {
		pbn = q_pbn.Dequeue();
		visit(pbn->val);
		if (HasLChild(*pbn)) { q_pbn.Enqueue(pbn->left); }
		if (HasRChild(*pbn)) { q_pbn.Enqueue(pbn->right); }
	}
}

template <typename T> template <typename VST>
void TreeNode<T>::TravelPre(VST &visit) {
	switch (rand() % 2) {
		case 1:
			printf("TravelPreIteration\n"); TravelPreIteration(this, visit); break;
		default:
			printf("TravelPreRecursion\n"); TravelPreRecursion(this, visit); break;
	}
	printf("\n");
}

template <typename T> template <typename VST>
void TreeNode<T>::TravelIn(VST &visit) {
	switch (rand() % 1 + 3) {
		case 1:
			printf("TravelInItreationOne\n");
			TravelInIterationOne(this, visit); break;
		case 2:
			printf("TravelInItreationTwo\n");
			TravelInIterationTwo(this, visit); break;
		case 3:
			/* no stack S(1) */
			printf("TravelInItreationThree\n");
			TravelInIterationThree(this, visit); break;
		default: 
			printf("TravelInRecursion\n"); TravelInRecursion(this, visit); break;
	}
	printf("\n");
}

template <typename T> template <typename VST>
void TreeNode<T>::TravelPost(VST &visit) {
	switch (rand() % 2) {
		case 1: 
			printf("TravelPostIteration\n"); TravelPostIteration(this, visit); break;
		default: 
			printf("TravelPostRecursion\n"); TravelPostRecursion(this, visit); break;
	}
	printf("\n");
}

// template <typename T>
// int TreeNode<T>::Size() {}

/* non function member */
template <typename T>
inline int Sature(const TreeNodePosi(T) p) {
	return (p) ? p->_height : -1;
}

template <typename T> 
bool IsRoot(const TreeNode<T> &rbin_node) {
	/* rbin_node reference to a bin_node */
	return !(rbin_node._parent);
}

template <typename T>
bool IsLChild(const TreeNode<T> &rbin_node) {
	return rbin_node._parent && rbin_node._parent->left == &rbin_node;
}

template <typename T>
bool IsRChild(const TreeNode<T> &rbin_node) {
	return rbin_node._parent && rbin_node._parent->right == &rbin_node; 
}

template <typename T>
bool IsChild(const TreeNode<T> &rbin_node) {
	return IsLChild(rbin_node) || IsRChild(rbin_node);
}

template <typename T>
bool HasLChild(const TreeNode<T> &rbin_node) {
	return rbin_node.left;
}

template <typename T>
bool HasRChild(const TreeNode<T> &rbin_node) {
	return rbin_node.right;
}

template <typename T>
bool HasChild(const TreeNode<T> &rbin_node) {
	return HasLChild(rbin_node) || HasRChild(rbin_node);
}

template <typename T>
bool HasBothChild(const TreeNode<T> &rbin_node) {
	return HasLChild(rbin_node) && HasRChild(rbin_node);
}

template <typename T>
bool IsLeaf(const TreeNode<T> &rbin_node) {
	/* cannot use height == 0, due to InsertAsLC do not update height */
	// return (bool) !(rbin_node._height);
	/* another method */
	return !HasChild(rbin_node);
}

template <typename T>
TreeNodePosi(T) Sibling(const TreeNode<T> &rbin_node) {
	return IsLChild(rbin_node) ? rbin_node._parent->right : rbin_node._parent->left;
}

template <typename T>
TreeNodePosi(T) Uncle(const TreeNode<T> &rbin_node) {
	Sibling(*(rbin_node._parent));
}

template <typename T, typename VST>
static void TravelPreRecursion(TreeNodePosi(T) pbin_node, VST &visit) {
	if (!pbin_node) return;
	visit(pbin_node->val);
	TravelPreRecursion(pbin_node->left, visit);
	TravelPreRecursion(pbin_node->right, visit);
}

template <typename T, typename VST>
static void VisitAlongLeftBranch(TreeNodePosi(T) pbin_node, VST &visit,
	Stack<TreeNodePosi(T)> &s_pbn) {
	while (pbin_node) {
		visit(pbin_node->val);
		s_pbn.Push(pbin_node->right);
		pbin_node = pbin_node->left;
	}
}

template <typename T, typename VST>
static void TravelPreIteration(TreeNodePosi(T) pbin_node, VST &visit) {
	Stack<TreeNodePosi(T)> s_pbn;
	while (1) {
		VisitAlongLeftBranch(pbin_node, visit, s_pbn);
		if (s_pbn.Empty()) break;
		pbin_node = s_pbn.Pop();
	}
}

template <typename T, typename VST>
static void TravelInRecursion(TreeNodePosi(T) pbin_node, VST &visit) {
	if (!pbin_node) return;
	TravelInRecursion(pbin_node->left, visit);
	visit(pbin_node->val);
	TravelInRecursion(pbin_node->right, visit);
}

template <typename T>
// void GoAlongLeftBranch(TreeNodePosi(T) pbin_node, Stack<TreeNodePosi(T)> &s_pbn) {
static void GoAlongLeftBranch(
	TreeNodePosi(T) pbin_node, Stack<TreeNodePosi(T)> &s_pbn) {
	while (pbin_node) {
		s_pbn.Push(pbin_node);
		pbin_node = pbin_node->left;
	}
}

template <typename T, typename VST>
static void TravelInIterationOne(TreeNodePosi(T) pbin_node, VST &visit) {
	Stack<TreeNodePosi(T)> s_pbn;
	while (1) {
		GoAlongLeftBranch(pbin_node, s_pbn);
		if (s_pbn.Empty()) break;
		pbin_node = s_pbn.Pop();
		visit(pbin_node->val);
		pbin_node = pbin_node->right;
	}
}

template <typename T, typename VST>
static void TravelInIterationTwo(TreeNodePosi(T) pbin_node, VST &visit) {
	Stack<TreeNodePosi(T)> s_pbn;
	while (1) {
		if (pbin_node) {
			s_pbn.Push(pbin_node);
			pbin_node = pbin_node->left;
		} else if (!s_pbn.Empty()) {
			pbin_node = s_pbn.Pop();
			visit(pbin_node->val);
			pbin_node = pbin_node->right;
		} else  { break; }
	}
}

template <typename T, typename VST>
static void TravelInIterationThree(TreeNodePosi(T) pbin_node, VST &visit) {
	bool backtrack = false;
	while (true) {
		if (!backtrack && HasLChild(*pbin_node)) { pbin_node = pbin_node->left; }
		else {
			visit(pbin_node->val);
			if (HasRChild(*pbin_node)) {
				pbin_node = pbin_node->right;
				backtrack = false;
			} else {
				if (!(pbin_node = pbin_node->Succ())) break;
				backtrack = true;
			}
		}
	}
}

template <typename T, typename VST>
static void TravelPostRecursion(TreeNodePosi(T) pbin_node, VST &visit) {
	if (!pbin_node) return;
	TravelPostRecursion(pbin_node->left, visit);
	TravelPostRecursion(pbin_node->right, visit);
	visit(pbin_node->val);
}

template <typename T>
/* HVLL refers to highest visible left leaf */
static void GoToHVLL (Stack<TreeNodePosi(T)> &s_pbn) {
	TreeNodePosi(T) pbin_node;
	while ((pbin_node = s_pbn.Top())) {
		if (HasLChild(*pbin_node)) {
			if (HasRChild(*pbin_node)) { s_pbn.Push(pbin_node->right); }
			s_pbn.Push(pbin_node->left);
		} else { s_pbn.Push(pbin_node->right); }
	} 
	s_pbn.Pop();
}

template <typename T, typename VST>
static void TravelPostIteration(TreeNodePosi(T) pbin_node, VST &visit) {
	Stack<TreeNodePosi(T)> s_pbn;
	if (pbin_node) s_pbn.Push(pbin_node);
	while (!s_pbn.Empty()) {
		if (s_pbn.Top() != pbin_node->_parent) GoToHVLL(s_pbn);
		pbin_node = s_pbn.Pop();
		visit(pbin_node->val);
	}
}



// template <typename T>
// TreeNodePosi(T) FromParentTo(const TreeNode<T> &rbin_node) {
//   return IsRoot(rbin_node) ? _root :
//     (IsLChild(rbin_node) ? rbin_node._parent->left : rbin_node._parent->right);
// }

}	/* namespace mydatastructure */

#endif 

#ifndef INCLUDE_BINTREE_H
#define INCLUDE_BINTREE_H

#include <assert.h>

#include <cstdio>
#include <iostream>

#include "../include/TreeNode.hpp"

/* non member function */
// template <typename T>
// TreeNodePosi(T) FromParentTo(TreeNode<T> &rbin_node) {
//   return IsRoot(rbin_node) ? _root :
//     (IsLChild(rbin_node) ? rbin_node._parent->right : rbin_node._parent->right)
// }
#define FromParentTo(rbin_node) \
	(IsRoot(rbin_node) ? _root : \
	(IsLChild(rbin_node) ? (rbin_node)._parent->left : (rbin_node)._parent->right))

namespace mydatastructure {

template <typename T>
class VST; /* class VST */

template <typename T>
class BinTree {
public: 
	/* constructor */
	BinTree();
	~BinTree();

	/* interface */
	virtual int UpdateHeight(TreeNode<T> *pbin_node);
	void UpdateHeightAbove(TreeNode<T> *pbin_node);
	int Size() const;
	bool Empty() const;
	TreeNodePosi(T) Root() const;
	TreeNodePosi(T) InsertAsRoot(const T &e);
	/* rbin_node - the position needed to be insert */
	TreeNodePosi(T) InsertAsLC(TreeNode<T> *pbin_node, const T &e);
	TreeNodePosi(T) InsertAsRC(TreeNode<T> *pbin_node, const T &e);
	TreeNodePosi(T) AttachAsLC(TreeNode<T> *pbin_node, BinTree<T>* *pptree);
	TreeNodePosi(T) AttachAsRC(TreeNode<T> *pbin_node, BinTree<T>* *pptree);
	int Remove(TreeNode<T> *pbin_node);	/* remove a subtree */
	BinTree<T>* Secede(TreeNode<T> *pbin_node);
	template <typename VST>
	void TravelLevel(VST &visit);
	template <typename VST>
	void TravelPre(VST &visit);
	template <typename VST>
	void TravelIn(VST &visit);
	template <typename VST>
	void TravelPost(VST &visit);
	bool operator<(const TreeNode<T> *pbin_node) const;
	bool operator==(const TreeNode<T> *pbin_node) const;
	// friend TreeNodePosi(T) FromParentTo(TreeNode<T> *pbin_node);
	
protected:
	int _size;
	TreeNodePosi(T) _root;
};	/* class BinTree */

template <typename T>
int BinTree<T>::UpdateHeight(TreeNode<T> *pbin_node) {
	return pbin_node->_height =  1 + 
		std::max(Sature(pbin_node->left), Sature(pbin_node->right));
}

template <typename T>
void BinTree<T>::UpdateHeightAbove(TreeNode<T> *pbin_node) {
	while (pbin_node) {
		UpdateHeight(pbin_node);
		pbin_node = pbin_node->_parent;
	}
}

template <typename T>
BinTree<T>::BinTree() : _size(0), _root(nullptr) { }

template <typename T>
BinTree<T>::~BinTree() { if (_size > 0) Remove(_root); printf("\n~BinTree()"); }

template <typename T>
int BinTree<T>::Remove(TreeNode<T> *pbin_node) {
	FromParentTo(*pbin_node) = nullptr;
	UpdateHeightAbove(pbin_node->_parent);
	int n = RemoveAt(pbin_node);
	_size -= n;
	return n;
}

/* parameter is pointer to check whether exist but reference cannot */
template <typename T>
static int RemoveAt(TreeNode<T> *pbin_node) {
	if (!pbin_node) return 0;
	int n = 1 + RemoveAt(pbin_node->left) + RemoveAt(pbin_node->right);
	delete pbin_node;
	return n;
}

template <typename T>
int BinTree<T>::Size() const { return _size; }

template <typename T>
bool BinTree<T>::Empty() const { return (bool) !_root; }

template <typename T>
TreeNodePosi(T) BinTree<T>::Root() const { return _root; }

template <typename T>
TreeNodePosi(T) BinTree<T>::InsertAsRoot(const T &e) {
	_size = 1;
	return _root = new TreeNode<T>(e);
}

template <typename T>
TreeNodePosi(T) BinTree<T>::InsertAsLC(TreeNode<T> *pbin_node, const T &e) {
	++_size;
	pbin_node->InsertAsLC(e);
	UpdateHeightAbove(pbin_node);
	return pbin_node->left;
}

template <typename T>
TreeNodePosi(T) BinTree<T>::InsertAsRC(TreeNode<T> *pbin_node, const T &e) {
	++_size;
	pbin_node->InsertAsRC(e);
	UpdateHeightAbove(pbin_node);
	return pbin_node->right;
}

template <typename T>
TreeNodePosi(T) BinTree<T>::AttachAsLC(TreeNode<T> *pbin_node,
	BinTree<T>* *pptree){
	/* pbin_node->left == nullptr */
	assert(pbin_node->left == nullptr);

	/* change node status */
	pbin_node->left = (*pptree)->_root;
	(*pptree)->_root->_parent = pbin_node;
	UpdateHeightAbove(pbin_node);
	_size += (*pptree)->_size;

	/* initialize (*pptree) */
	(*pptree)->_size = 0;
	(*pptree)->_root = nullptr;
	(*pptree) = nullptr;
	return pbin_node;
}

template <typename T>
TreeNodePosi(T) BinTree<T>::AttachAsRC(TreeNode<T> *pbin_node,
	BinTree<T>* *pptree){
	/* pbin_node->right == nullptr */
	assert(pbin_node->right == nullptr);

	/* change node status */
	pbin_node->right = (*pptree)->_root;
	// pbin_node->right->_parent = pbin_node;
	(*pptree)->_root->_parent = pbin_node;
	UpdateHeightAbove(pbin_node);
	_size += (*pptree)->_size;
	
	/* initialize (*pptree) */
	(*pptree)->_root = nullptr;
	(*pptree)->_size = 0;
	// Remove((*pptree)->Root());
	(*pptree) = nullptr;
	return pbin_node;
}

template <typename T> template <typename VST>
void BinTree<T>::TravelLevel(VST &visit) {
	if (_root) { _root->TravelLevel(visit); }
}

template <typename T> template <typename VST>
void BinTree<T>::TravelPre(VST &visit) {
	if (_root) { _root->TravelPre(visit); }
}

template <typename T> template <typename VST>
void BinTree<T>::TravelIn(VST &visit) {
	if (_root) { _root->TravelIn(visit); }
}

template <typename T> template <typename VST>
void BinTree<T>::TravelPost(VST &visit) {
	if (_root) { _root->TravelPost(visit); }
}

template <typename T>
class VST {
public:
	void operator()(T &e) { std::cout << e << '\t'; }
};	/* class VST */

/* non function member  */

};	/* namespace mydatastructure */

#endif 




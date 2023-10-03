#pragma once
#include "../eNode.h"
#include "../Tree/BinaryTree/eBinaryTree.h"

template <typename T>
class eStack
{
protected:
	_node<T>* Head;

	_node<_treeNode<T>*>* TreeHead;
public:
	eStack();
	~eStack();

	int Length = 0;

	void push(T t);
	T pop();
	T peek();

	// template 특수화.. 적용
	int treeLength = 0;
	void treePush(_treeNode<T>* treeNodePtr);
	_treeNode<T>* treePop();
};


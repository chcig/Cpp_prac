#pragma once
#include "../eNode.h"
#include <functional>
#include <iostream>

enum class Order
{
	PREORDER,
	INORDER,
	POSTORDER
};

template <typename T>
class eBinaryTree
{
protected:
	_treeNode<T>* root;
	int height = 0;
	//std::function<void(T)> VisitFunc;

	//typedef void (eBinaryTree<T>::*VisitFunc)(T);	// 행동을 결정하는 함수포인터
public:
	eBinaryTree() : root(nullptr) { }
	~eBinaryTree() { Clear(); }

	void Add(T value);
	void Clear();
	void printOrder(Order order);

private:
	_treeNode<T>* add(_treeNode<T>* curNode, T t);
	void Clear(_treeNode<T>* curNode);
	void PreOrderTraverse(_treeNode<T>* curNode, std::function<void(T)> action);
	void InOrderTraverse(_treeNode<T>* curNode, std::function<void(T)> action);
	void PostOrderTraverse(_treeNode<T>* curNode, std::function<void(T)> action);
	void SimpleShowData(T value);
};


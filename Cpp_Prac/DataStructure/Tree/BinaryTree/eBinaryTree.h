#pragma once
#include "../../eNode.h"
#include <functional>
#include <iostream>
#include <string>

/// Full Binary Tree	 : All Level Tree Is Full
///       ¡Ü
///    ¡Ü     ¡Ü
///  ¡Ü  ¡Ü   ¡Ü  ¡Ü
/// ¡Ü¡Ü  ¡Ü¡Ü ¡Ü¡Ü  ¡Ü¡Ü

/// Complete Binary Tree : Stack Tree No Empty (Like Array)
///       ¡Ü
///    ¡Ü     ¡Ü
///  ¡Ü  ¡Ü   ¡Ü  ¡Ü
/// ¡Ü¡Ü  ¡Ü¡Ü

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

public:
	eBinaryTree() : root(nullptr), rootTree(nullptr) { }
	~eBinaryTree() { Clear(); }

	void Add(T value);
	void Clear();
	void printOrder(Order order);

	_treeNode<T>* getRoot() { return root; };

private:
	_treeNode<T>* add(_treeNode<T>* curNode, T t);
	_treeNode<T>* MakeBTree(T t) { return new _treeNode<T>(t); };
	void Clear(_treeNode<T>* curNode);
	void PreOrderTraverse(_treeNode<T>* curNode, std::function<void(T)> action);
	void InOrderTraverse(_treeNode<T>* curNode, std::function<void(T)> action);
	void PostOrderTraverse(_treeNode<T>* curNode, std::function<void(T)> action);
	void SimpleShowData(T value);

/// <summary>
/// Expresstion Tree
/// </summary>
protected:
	_treeNode<T>* rootTree;

public:
	_treeNode<T>* MakeBTree() { return new _treeNode<T>; };
	_treeNode<T>* MakeBTree(_treeNode<T>* t) { return new _treeNode<T>(t); };
	void MakeExpresstionTree(std::string strExpresstion);
	void ShowExpresstionOrder(Order order);
	void SimpleShowNodeData(T value);

	T CalcExpresstion();
	T CalcExpresstion(_treeNode<T>* curNode);


private:

};


#pragma once
#include "../BinaryTree/eBinaryTree.h"
#include "../../Stack/eStack.h"
#include <string>

template <typename T>
class eExpressionTree
{
private:
	eExpressionTree();
	~eExpressionTree();
public:
	eBinaryTree<T>* MakeExpressTree(std::string Exp);

};


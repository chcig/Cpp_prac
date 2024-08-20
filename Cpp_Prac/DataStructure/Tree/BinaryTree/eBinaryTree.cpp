#include "eBinaryTree.h"
#include "../../Stack/eStack.h"
#include"../../../Algorithm/ExpresstionNotation.h"

template <typename T>
void eBinaryTree<T>::Add(T value)
{
	root = add(root, value);
}

template <typename T>
void eBinaryTree<T>::Clear()
{
	Clear(root);
	root = nullptr;

	Clear(rootTree);
	rootTree = nullptr;
}

template <typename T>
void eBinaryTree<T>::printOrder(Order order)
{
	switch (order)
	{
	case Order::PREORDER:
		PreOrderTraverse(root, std::bind(&eBinaryTree<T>::SimpleShowData,this, std::placeholders::_1));
		break;
	case Order::INORDER:
		InOrderTraverse(root, std::bind(&eBinaryTree<T>::SimpleShowData, this, std::placeholders::_1));
		break;
	case Order::POSTORDER:
		PostOrderTraverse(root, std::bind(&eBinaryTree<T>::SimpleShowData, this, std::placeholders::_1));
		break;
	}
	std::cout << std::endl;
}

template <typename T>
_treeNode<T>* eBinaryTree<T>::add(_treeNode<T>* curNode, T t)
{
	static int level = 0;
	level++;

	if (curNode == nullptr)
		return MakeBTree(t);

	if (curNode->value > t)
		curNode->left = add(curNode->left, t);
	if (t > curNode->value)
		curNode->right = add(curNode->right, t);


	return curNode;
}

template <typename T>
void eBinaryTree<T>::Clear(_treeNode<T>* curNode)
{
	if (curNode == nullptr) return;

	Clear(curNode->left);
	Clear(curNode->right);

	delete curNode;
}

template <typename T>
void eBinaryTree<T>::PreOrderTraverse(_treeNode<T>* curNode, std::function<void(T)> action)
{
	if (curNode != nullptr)
	{
		action(curNode->value);
		PreOrderTraverse(curNode->left, action);
		PreOrderTraverse(curNode->right, action);
	}
}

template <typename T>
void eBinaryTree<T>::InOrderTraverse(_treeNode<T>* curNode, std::function<void(T)> action)
{
	if (curNode != nullptr)
	{
		InOrderTraverse(curNode->left, action);
		action(curNode->value);
		InOrderTraverse(curNode->right, action);
	}
}

template <typename T>
void eBinaryTree<T>::PostOrderTraverse(_treeNode<T>* curNode, std::function<void(T)> action)
{
	if (curNode != nullptr)
	{
		PostOrderTraverse(curNode->left, action);
		PostOrderTraverse(curNode->right, action);
		action(curNode->value);
	}
}

template <typename T>
void eBinaryTree<T>::SimpleShowData(T value)
{
	std::cout << value << " ";
}

// Expresstion Calculator
template<typename T>
void eBinaryTree<T>::MakeExpresstionTree(std::string strExpresstion)
{
	eStack<T> stack;
	_treeNode<T>* pNode = nullptr;

	for (int i = 0; i < strExpresstion.size(); i++)
	{
		pNode = MakeBTree();

		if (isdigit(strExpresstion[i]))
			pNode->value = ((T)strExpresstion[i])-'0';
		else
		{
			pNode->right = stack.treePop();
			pNode->left = stack.treePop();
			pNode->value = strExpresstion[i];
		}

		stack.treePush(pNode);
	}
	rootTree = stack.treePop();
}

template <typename T>
void eBinaryTree<T>::ShowExpresstionOrder(Order order)
{
	switch (order)
	{
	case Order::PREORDER:
		PreOrderTraverse(rootTree, std::bind(&eBinaryTree<T>::SimpleShowNodeData, this, std::placeholders::_1));
		break;
	case Order::INORDER:
		InOrderTraverse(rootTree, std::bind(&eBinaryTree<T>::SimpleShowNodeData, this, std::placeholders::_1));
		break;
	case Order::POSTORDER:
		PostOrderTraverse(rootTree, std::bind(&eBinaryTree<T>::SimpleShowNodeData, this, std::placeholders::_1));
		break;
	}
	std::cout << std::endl;
}

template <typename T>
void eBinaryTree<T>::SimpleShowNodeData(T value)
{
	if(0 <= value && value <= 9)
		std::cout << value;
	else
		std::cout << (char)value;
}

template <typename T>
T eBinaryTree<T>::CalcExpresstion()
{
	if (rootTree->left == nullptr && rootTree->right == nullptr)
		return rootTree->value;

	T op1, op2;
	op1 = CalcExpresstion(rootTree->left);
	op2 = CalcExpresstion(rootTree->right);

	switch ((char)rootTree->value)
	{
	case MUL_CHAR: return op1 * op2;
	case DIV_CHAR: return op1 / op2;
	case ADD_CHAR: return op1 + op2;
	case SUB_CHAR: return op1 - op2;
	}

	return rootTree->value;
}

template<typename T>
T eBinaryTree<T>::CalcExpresstion(_treeNode<T>* curNode)
{
	if (curNode->left == nullptr && curNode->right == nullptr)
		return curNode->value;

	T op1, op2;
	op1 = CalcExpresstion(curNode->left);
	op2 = CalcExpresstion(curNode->right);

	switch ((char)curNode->value)
	{
	case MUL_CHAR: return op1 * op2;
	case DIV_CHAR: return op1 / op2;
	case ADD_CHAR: return op1 + op2;
	case SUB_CHAR: return op1 - op2;
	}

	return curNode->value;
}

template class eBinaryTree<char>;
template class eBinaryTree<int>;
template class eBinaryTree<double>;
template class eBinaryTree<float>;
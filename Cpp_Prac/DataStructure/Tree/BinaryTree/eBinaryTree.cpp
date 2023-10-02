#include "eBinaryTree.h"

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
	{
		_treeNode<T>* newNode = new _treeNode<T>(t);
		newNode->level = level;
		level = 0;
		return newNode;
	}
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

template class eBinaryTree<char>;
template class eBinaryTree<int>;
template class eBinaryTree<double>;
template class eBinaryTree<float>;
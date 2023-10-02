#include "eExpressionTree.h"

template<typename T>
eExpressionTree<T>::eExpressionTree()
{
}

template<typename T>
eExpressionTree<T>::~eExpressionTree()
{
}

template<typename T>
eBinaryTree<T>* eExpressionTree<T>::MakeExpressTree(std::string Exp)
{
	eStack<T> stack;
	eBinaryTree<T>* pNode;

	for (int i = 0; i < Exp.size(); i++)
	{
		if (isdigit(Exp[i]))
			stack.push(Exp[i]);
		else
		{
			
		}
	}
	return nullptr;
}

template class eExpressionTree<char>;
template class eExpressionTree<int>;
template class eExpressionTree<float>;
template class eExpressionTree<double>;
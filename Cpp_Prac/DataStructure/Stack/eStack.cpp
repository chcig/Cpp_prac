#include "eStack.h"
#include <string>

template<typename T>
eStack<T>::eStack()
{
	Head = nullptr;
}

template<typename T>
eStack<T>::~eStack()
{
	while (Head != nullptr)
	{
		_node<T>* delNode = Head;
		Head = Head->next;
		delete delNode;
	}
}

template <typename T>
void eStack<T>::push(T t)
{
	_node<T>* newNode = new _node<T>(t);
	newNode->next = Head;
	Head = newNode;
	Length++;
}

template <typename T>
T eStack<T>::pop()
{
	if (Length == 0) return T();

	_node<T>* ret = Head;
	Head = Head->next;

	T res = ret->value;
	delete ret;
	Length--;
	return res;
}

template <typename T>
T eStack<T>::peek()
{
	if (Length == 0) return T();
	T res = Head->value;
	return res;
}

template class eStack<int>;
template class eStack<double>;
template class eStack<float>;
template class eStack<char>;
template class eStack<std::string>;
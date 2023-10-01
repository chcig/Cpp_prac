#include "eLinkedList.h"
#include <cassert>

template<typename T>
eLinkedList<T>::eLinkedList()
{
}

template<typename T>
eLinkedList<T>::~eLinkedList()
{
	while (Head != nullptr)
	{
		_node<T>* delNode = Head;
		Head = Head->next;
		delete delNode;
	}
}

template <typename T>
void eLinkedList<T>::add(T t)
{
	if (Head == nullptr)
	{
		Head = new _node<T>(t);
	}
	else
	{
		point = Head;
		while (point != nullptr)
		{
			temp = point;
			point = point->next;
		}

		point = new _node<T>(t);
		point->pre = temp;
		temp->next = point;
	}
	Length++;
}

template <typename T>
void eLinkedList<T>::insert(T t, int nPos)
{
	if (Head == nullptr)
	{
		Head = new _node<T>(t);
	}
	else
	{
		point = Head;
		while (--nPos > 0)
			point = point->next;

		temp = point->pre;

		_node<T>* newNode = new _node<T>(t);
		newNode->pre = temp;
		newNode->next = point;

		temp->next = newNode;
		point->pre = newNode;
	}
	Length++;
}

template <typename T>
bool eLinkedList<T>::remove(int n)
{
	if (n > Length) return false;
	point = Head;
	while (--n > 0)
	{
		if (point == nullptr) return false;
		point = point->next;
	}
	temp = point->pre;
	temp->next = point->next;

	temp = point->next;
	temp->pre = point->pre;

	delete point;

	Length--;

	return true;
}

template<typename T>
T& eLinkedList<T>::operator[](int idx)
{
	return GetAt(idx);
}

template <typename T>
T& eLinkedList<T>::GetAt(int n)
{
	assert(0 <= n || n < Length);
	int count = 0;
	point = Head;
	while (point != nullptr)
	{
		if (count == n)
			return point->value;
		point = point->next;
		count++;
	}
	throw T();
}

template class eLinkedList<int>;
template class eLinkedList<double>;
template class eLinkedList<float>;
template class eLinkedList<char>;

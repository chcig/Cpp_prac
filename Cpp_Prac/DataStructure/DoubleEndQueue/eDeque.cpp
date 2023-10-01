#include "eDeque.h"

template <typename T>
eDeque<T>::eDeque()
{
	InitQueue();
}

template <typename T>
eDeque<T>::~eDeque()
{

}

template <typename T>
void eDeque<T>::InitQueue()
{
	m_front = m_rear = nullptr;
	m_nLen = 0;
}

template <typename T>
void eDeque<T>::AddFirst(T value)
{
	_node<T>* newNode = new	_node<T>(value);
	if (IsEmpty())
	{
		m_front = m_rear = newNode;
	}
	else
	{
		m_front->pre = newNode;
		newNode->next = m_front; // Double Linked Data.. 에서만 필요.. 사실 불필요함.
		m_front = newNode;
	}
	m_nLen++;
}

template <typename T>
void eDeque<T>::AddLast(T value)
{
	_node<T>* newNode = new	_node<T>(value);
	if (IsEmpty())
	{
		m_front = m_rear = newNode;
	}
	else
	{
		m_rear->next = newNode;
		newNode->pre = m_rear; // Double Linked Data.. 에서만 필요.. 사실 불필요함.
		m_rear = newNode;
	}
	m_nLen++;
}

template <typename T>
T eDeque<T>::RemoveFirst()
{
	if (IsEmpty())
		return -1;

	_node<T>* deleteNode;
	deleteNode = m_front;
	T ret = deleteNode->value;
	m_front = m_front->next;
	if(m_front != nullptr)
		m_front->pre = nullptr;  // Double Linked Data.. 에서만 필요.. 사실 불필요함.
	delete deleteNode;
	m_nLen--;
	return ret;
}

template <typename T>
T eDeque<T>::RemoveLast()
{
	if (IsEmpty())
		return -1;

	_node<T>* deleteNode;
	deleteNode = m_rear;
	T ret = deleteNode->value;
	m_rear = m_rear->pre;
	if (m_rear != nullptr)
		m_rear->next = nullptr;  // Double Linked Data.. 에서만 필요.. 사실 불필요함.
	delete deleteNode;
	m_nLen--;
	return ret;
}

template <typename T>
bool eDeque<T>::IsEmpty()
{
	return (nullptr == m_front) && (nullptr == m_rear);
}

template <typename T>
int eDeque<T>::GetLength()
{
	return m_nLen;
}

template class eDeque<char>;
template class eDeque<int>;
template class eDeque<double>;
template class eDeque<float>;
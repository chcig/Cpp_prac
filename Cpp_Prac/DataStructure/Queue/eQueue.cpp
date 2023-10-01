#include "eQueue.h"

template <typename T>
void eQueue<T>::Enque(T t)
{
	_node<T>* newNode = new _node<T>(t);

	if (Head == nullptr)
	{
		Head = newNode;
	}
	else
	{
		Tail = Head;
		while (Tail != nullptr)
		{
			temp = Tail;
			Tail = Tail->next;
		}
		Tail = newNode;
		temp->next = Tail;
	}
	Length++;
}

template <typename T>
T eQueue<T>::Deque()
{
	if (Length < 0) return -1;

	_node<T>* target = Head;
	T res = target->value;
	Head = Head->next;
	delete target;

	Length--;
	return res;
}

template class eQueue<int>;
template class eQueue<double>;
template class eQueue<float>;
#include "eQueue.h"


template<typename T>
eQueue<T>::eQueue()
{
	initQue();
}

template<typename T>
eQueue<T>::~eQueue()
{
}

template<typename T>
void eQueue<T>::initQue()
{
	Front = nullptr;
	Rear = nullptr;
}

template <typename T>
void eQueue<T>::Enque(T t)
{
	_node<T>* newNode = new _node<T>(t);

	if (Front == nullptr)
	{
		Front = newNode;
		Rear = newNode;
	}
	else
	{
		Rear->next = newNode;
		Rear = newNode;
	}
	Length++;
}

template <typename T>
T eQueue<T>::Deque()
{
	if (Length <= 0) return -1;

	_node<T>* target = Front;
	T res = target->value;
	Front = Front->next;
	delete target;

	Length--;
	return res;
}

template<typename T>
T eQueue<T>::Peek()
{
	if (Length <= 0) return -1;

	T ret = Front->value;
	return ret;
}

template class eQueue<int>;
template class eQueue<double>;
template class eQueue<float>;
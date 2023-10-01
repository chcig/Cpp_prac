#pragma once
#include "../eNode.h"

template <typename T>
class eQueue
{
protected:
	_node<T>* Head;
	_node<T>* Tail;
	_node<T>* temp;

public:
	int Length = 0;

	void Enque(T t);
	T Deque();
};


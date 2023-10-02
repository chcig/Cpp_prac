#pragma once
#include "../eNode.h"

template <typename T>
class eQueue
{
protected:
	_node<T>* Front;
	_node<T>* Rear;

private:
	eQueue();
	~eQueue();

	void initQue();
public:
	int Length = 0;

	void Enque(T t);
	T Deque();
	T Peek();
};


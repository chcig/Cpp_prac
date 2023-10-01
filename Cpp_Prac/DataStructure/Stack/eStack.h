#pragma once
#include "../eNode.h"

template <typename T>
class eStack
{
protected:
	_node<T>* Head;

public:
	eStack();
	~eStack();

	int Length = 0;

	void push(T t);
	T pop();
	T peek();
};


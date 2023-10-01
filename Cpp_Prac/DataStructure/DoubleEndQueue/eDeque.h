#pragma once
#include "../eNode.h"

// Double End Queue
template <typename T>
class eDeque
{
private:
	_node<T>* m_front;
	_node<T>* m_rear;
	int m_nLen;

public:
	eDeque();
	~eDeque();

	void InitQueue();
	void AddFirst(T value);
	void AddLast(T value);
	T RemoveFirst();
	T RemoveLast();

	bool IsEmpty();
	int GetLength();
};
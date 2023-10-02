#pragma once
#include "../eNode.h"

#define DEFAULT_COUNT 512

template <typename T>
class eArrayQueue
{
protected:
	_node<T>** m_Queue;
	int m_nFront;
	int m_nRear;
	int m_nAssignCount;

private:
	int GetNext(int pos);

public:
	eArrayQueue(int cnt = DEFAULT_COUNT);
	~eArrayQueue();

	void assign(int cnt);
	void Enque(T value);
	T Deque();
	T Peek();

	bool IsEmpty();
	bool IsFull();
	int GetLength();
};


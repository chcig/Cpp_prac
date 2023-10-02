#include "eArrayQueue.h"

template <typename T>
eArrayQueue<T>::eArrayQueue(int cnt)
{
	m_nFront = 0;
	m_nRear = 0;
	m_nAssignCount = cnt + 1;  // Queue 특성상... Empty와 Full이 구분하기 위해서
	m_Queue = new _node<T>* [m_nAssignCount];
	for (int i = 0; i < m_nAssignCount; i++)
		m_Queue[i] = new _node<T>;
}

template <typename T>
eArrayQueue<T>::~eArrayQueue()
{
	if (m_nAssignCount > 0)
	{
		for (int i = 0; i < m_nAssignCount; i++)
			delete m_Queue[i];
		delete m_Queue;
	}
}

template <typename T>
void eArrayQueue<T>::assign(int cnt)
{
	return;
}

template <typename T>
void eArrayQueue<T>::Enque(T value)
{
	if (IsFull()) 
		return;

	m_nRear = GetNext(m_nRear);
	if (m_nRear == 0)		// 원형큐에서 덮어 쓸수 있도록...
	{
		m_nFront = 0;
		m_nRear = GetNext(m_nRear);
	}
	((_node<T>*)m_Queue[m_nRear])->value = value;
	return;
}

template <typename T>
T eArrayQueue<T>::Deque()
{
	if (IsEmpty()) 
		throw -1;

	m_nFront = GetNext(m_nFront);
	T ret = ((_node<T>*)m_Queue[m_nFront])->value;
	return ret;
}

template<typename T>
T eArrayQueue<T>::Peek()
{
	if (IsEmpty())
		throw - 1;
	return ((_node<T>*)m_Queue[m_nFront])->value;
}

template <typename T>
int eArrayQueue<T>::GetNext(int pos)
{ 
	if (m_nAssignCount - 1 == pos)	// 마지막 공간의 이면
		return 0;
	return ++pos;
}

template <typename T>
bool eArrayQueue<T>::IsEmpty() 
{ 
	return m_nFront == m_nRear; 
}

template <typename T>
bool eArrayQueue<T>::IsFull()
{
	int nNext = GetNext(m_nRear);
	if (nNext == m_nFront)
		return true;
	return false;
}

template <typename T>
int eArrayQueue<T>::GetLength()
{
	return m_nRear - m_nFront;
}

template class eArrayQueue<int>;
template class eArrayQueue<double>;
template class eArrayQueue<float>;
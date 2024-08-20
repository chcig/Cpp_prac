#include "eHeap.h"
#include <tuple>

template<typename T>
eHeap<T>::eHeap()
{
}

template<typename T>
eHeap<T>::~eHeap()
{
}

template<typename T>
void eHeap<T>::Insert(T value, Priority pr)
{
	// 1�� �ε������� ����
	int idx = m_nCount + 1;
	_heapElement<T> elem = std::make_tuple(pr,value);

	while (idx != 1)
	{
		if (pr < heapArr[GetParentNodeIdx(idx).pr])
		{
			heapArr[idx] = heapArr[GetParentNodeIdx(idx)];
			idx = GetParentNodeIdx(idx);
		}
		else
			break;
	}

	heapArr[idx] = elem;
	m_nCount++;
}

template<typename T>
T eHeap<T>::Delete()
{
	T ret = heapArr[1].value;
	_heapElement<T> lastElem = heapArr[m_nCount];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHighPriorityChildIdx(parentIdx))
	{
		if (lastElem.pr <= heapArr[childIdx].pr)
			break;
		heapArr[parentIdx] = heapArr[childIdx];
		parentIdx = childIdx;
	}

	heapArr[parentIdx] = lastElem;
	m_nCount--;
	return ret;
}

template<typename T>
int eHeap<T>::GetParentNodeIdx(int curIdx)
{
	return curIdx / 2;
}

template<typename T>
int eHeap<T>::GetLeftChildIdx(int curIdx)
{
	return curIdx * 2;
}

template<typename T>
int eHeap<T>::GetRightChildIdx(int curIdx)
{
	return GetLeftChildIdx(curIdx) + 1;
}

template<typename T>
int eHeap<T>::GetHighPriorityChildIdx(int curIdx)
{
	// �ڽ� ��尡 �������� ����
	if (GetLeftChildIdx(curIdx) > m_nCount)
		return 0;
	// �ڽ� ��尡 ���� �ڽ� �ϳ��� ����
	else if((GetLeftChildIdx(curIdx) == m_nCount))
		return GetLeftChildIdx(curIdx);
	// �ڽ� ��尡 �� ������
	else
	{
		// ������ �ڽ� ����� �켱������ �� ����
		if (heapArr[GetLeftChildIdx(curIdx)].pr > heapArr[GetRightChildIdx(curIdx)].pr)
			return GetRightChildIdx(curIdx);
		// ���� �ڽ� ����� �켱������ �� ����
		else
			return GetLeftChildIdx(curIdx);
	}
}

template<typename T>
bool eHeap<T>::IsEmpty()
{
	return m_nCount;
}

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
	// 1번 인덱스부터 시작
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
	// 자식 노드가 존재하지 않음
	if (GetLeftChildIdx(curIdx) > m_nCount)
		return 0;
	// 자식 노드가 왼쪽 자식 하나만 존재
	else if((GetLeftChildIdx(curIdx) == m_nCount))
		return GetLeftChildIdx(curIdx);
	// 자식 노드가 다 있을때
	else
	{
		// 오른쪽 자식 노드의 우선순위가 더 높음
		if (heapArr[GetLeftChildIdx(curIdx)].pr > heapArr[GetRightChildIdx(curIdx)].pr)
			return GetRightChildIdx(curIdx);
		// 왼쪽 자식 노드의 우선순위가 더 높음
		else
			return GetLeftChildIdx(curIdx);
	}
}

template<typename T>
bool eHeap<T>::IsEmpty()
{
	return m_nCount;
}

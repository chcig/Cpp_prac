#pragma once
#include "../eNode.h"

/// <summary>
/// Heap 조건
/// 1. 완전 이진 트리
/// 2. Max Heap - 모든 노드에 저장된 값은 자식노드에 저장된 값보다 크거나 같다. (root node가 제일 큰 값)
/// 3. Min Heap - 모든 노드에 저장된 값은 자식노드에 저장된 값보다 작거나 같다. (root node가 제일 작은 값)
/// 
/// Add Node
/// 1. 가장 낮은 레벨의 위치에 배치 후, 부모와 비교하여 위치를 찾아간다.
/// 
/// Delete Node
/// 1. 삭제한 노드의 위치에 마지막 노트를 대입 후 자식과 비교하여 위치를 찾아간다.
/// 
/// 특이사항
/// 1. 배열기반으로 구현 (연결리스트로 구현하면 새로운 노드를 힙의 "마지막 위치"에 추가하는것이 쉽지 않음)
/// 2. 노드에 고유 번호를 부여, 고유번호는 노드의 데이터가 저장 될 배열의 인덱스 값
///	   [0][1 -A][2 -B][3 -C][4 -D][5 -E][6 -F][7 -G][8 -H][9 -I]
///       A1
///    B2    C3
///  D4 E5  F6 G7
/// HI  ●● ●●  ●●
/// 3. 노드의 인덱스 값
///		- 왼쪽 자식 노드의 인덱스값	= 부모노드의 인덱스 * 2
/// 	- 오른쪽 자식 노드의 인덱스값 = 부모노드의 인덱스 * 2 + 1
///		- 부모 노드의 인덱스값		= 자식노드의 인덱스 / 2
/// </summary>

#define HEAP_MAX 255

template <typename T>
class eHeap
{
private:
	int m_nCount;
	_heapElement<T> heapArr[HEAP_MAX];

public:
	eHeap();
	~eHeap();

	bool IsEmpty();
	void Insert(T value, Priority pr);
	T Delete();

private:
	int GetParentNodeIdx(int curIdx);
	int GetLeftChildIdx(int curIdx);
	int GetRightChildIdx(int curIdx);
	
	int GetHighPriorityChildIdx(int curIdx);
};


#pragma once
#include "../eNode.h"

/// <summary>
/// Heap ����
/// 1. ���� ���� Ʈ��
/// 2. Max Heap - ��� ��忡 ����� ���� �ڽĳ�忡 ����� ������ ũ�ų� ����. (root node�� ���� ū ��)
/// 3. Min Heap - ��� ��忡 ����� ���� �ڽĳ�忡 ����� ������ �۰ų� ����. (root node�� ���� ���� ��)
/// 
/// Add Node
/// 1. ���� ���� ������ ��ġ�� ��ġ ��, �θ�� ���Ͽ� ��ġ�� ã�ư���.
/// 
/// Delete Node
/// 1. ������ ����� ��ġ�� ������ ��Ʈ�� ���� �� �ڽİ� ���Ͽ� ��ġ�� ã�ư���.
/// 
/// Ư�̻���
/// 1. �迭������� ���� (���Ḯ��Ʈ�� �����ϸ� ���ο� ��带 ���� "������ ��ġ"�� �߰��ϴ°��� ���� ����)
/// 2. ��忡 ���� ��ȣ�� �ο�, ������ȣ�� ����� �����Ͱ� ���� �� �迭�� �ε��� ��
///	   [0][1 -A][2 -B][3 -C][4 -D][5 -E][6 -F][7 -G][8 -H][9 -I]
///       A1
///    B2    C3
///  D4 E5  F6 G7
/// HI  �ܡ� �ܡ�  �ܡ�
/// 3. ����� �ε��� ��
///		- ���� �ڽ� ����� �ε�����	= �θ����� �ε��� * 2
/// 	- ������ �ڽ� ����� �ε����� = �θ����� �ε��� * 2 + 1
///		- �θ� ����� �ε�����		= �ڽĳ���� �ε��� / 2
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


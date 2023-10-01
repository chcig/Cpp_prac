#pragma once
#include "../eNode.h"

template <typename T>
class eLinkedList
{
protected:
	_node<T>* Head = nullptr;

private:
	_node<T>* point = nullptr;
	_node<T>* temp = nullptr;

public:
	eLinkedList();
	~eLinkedList();

	int Length = 0;

	void add(T t);
	void insert(T t, int nPos);
	bool remove(int n);

	T& operator[](int idx);
	T& GetAt(int n);
};
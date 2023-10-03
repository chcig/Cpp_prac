#pragma once
enum treePos
{
	LEFT = 0,
	RIGHT
};

template <typename T>
struct _node
{
	T value;
	_node<T>* pre;
	_node<T>* next;

	_node() {};
	_node(T t)
	{
		value = t;
		pre = nullptr;
		next = nullptr;
	}
};

template <typename T>
struct _treeNode
{
	T value;
	_treeNode<T>* left;
	_treeNode<T>* right;

	int level;
	bool isFull;

	_treeNode()
	{
		left = nullptr;
		right = nullptr;
	};

	_treeNode(_treeNode<T>* pt)
	{
		value = pt->value;
		left = nullptr;
		right = nullptr;

		level = 0;
		isFull = false;
	}

	_treeNode(T t)
	{
		value = t;
		left = nullptr;
		right = nullptr;

		level = 0;
		isFull = false;
	}
};
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
	_node* pre;
	_node* next;

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
	_treeNode* left;
	_treeNode* right;

	int level;
	bool isFull;

	_treeNode() {};
	_treeNode(T t)
	{
		value = t;
		left = nullptr;
		right = nullptr;

		level = 0;
		isFull = false;
	}
};
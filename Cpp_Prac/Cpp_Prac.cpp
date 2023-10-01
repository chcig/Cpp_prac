﻿#include <iostream>
#include "DataStructure/Tree/eBinaryTree.h"

int main()
{
    eBinaryTree<int> nTree;

    nTree.Add(4);
    nTree.Add(3);
    nTree.Add(7);
    nTree.Add(34);
    nTree.Add(544);
    nTree.Add(1);

    nTree.printOrder(Order::PREORDER);
    nTree.printOrder(Order::INORDER);
    nTree.printOrder(Order::POSTORDER);
}
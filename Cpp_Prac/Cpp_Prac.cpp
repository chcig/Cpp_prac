#include <iostream>
#include "DataStructure/Tree/BinaryTree/eBinaryTree.h"
#include "Algorithm/ExpresstionNotation.h"

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


    std::string strQ = "((1-2)+3)*(5-2)";

    std::string strConv = ConvertToReversePolishNotation(strQ);
    nTree.MakeExpresstionTree(strConv);

    std::cout << strQ << " 전위표기법 변환 -> "; 
    nTree.ShowExpresstionOrder(Order::PREORDER);

    std::cout << strQ << " 중위표기법 변환 -> ";
    nTree.ShowExpresstionOrder(Order::INORDER);

    std::cout << strQ << " 후위표기법 변환 -> ";
    nTree.ShowExpresstionOrder(Order::POSTORDER);
}
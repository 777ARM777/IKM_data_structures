#include <iostream>
#include "BinaryTree.h"

int main()
{
    /*
    Node<char>* f = new Node<char>('f');
    Node<char>* i = new Node<char>('i');
    Node<char>* g = new Node<char>('g', i);
    Node<char>* e = new Node<char>('e', f, g);
    Node<char>* d = new Node<char>('d', nullptr, e);
    Node<char>* b = new Node<char>('b', nullptr, d);

    Node<char>* h = new Node<char>('h');
    Node<char>* j = new Node<char>('j');
    Node<char>* c = new Node<char>('c', h, j);

    Node<char>* a = new Node<char>('a', b, c);

    BinaryTree<char> tree(a);
    */
    BinaryTree<int> tree;

    tree.insertR(20);
    tree.insertR(14);
    tree.insertI(10);
    tree.insertR(30);
    tree.insertR(9);
    tree.insertI(15);
    tree.insertR(18);
    tree.insertR(7);
    tree.insertI(25);
    tree.insertI(7);
    tree.insertR(15);


//  Exam main
//    std::cout << "\nMax data at level Iterative: ";
//    tree.maxOfLevelI();
//    std::cout << "\nMax data at level Recursive: ";
//    tree.maxOfLevelR();
//
//    std::cout << "\nLevels with the maximum count: ";
//    tree.maxCountLevelI();
//
//    std::cout << "tree containsR 55: " << std::boolalpha << tree.containsR(55) << std::endl;
//    std::cout << "tree containsI 55: " << std::boolalpha << tree.containsI(55) << std::endl;
//    std::cout << "tree containsR 15: " << std::boolalpha << tree.containsR(15) << std::endl;
//    std::cout << "tree containsI 15: " << std::boolalpha << tree.containsI(15) << std::endl;
//    std::cout << "tree containsR -5: " << std::boolalpha << tree.containsR(-5) << std::endl;
//    std::cout << "tree containsI -5: " << std::boolalpha << tree.containsI(-5) << std::endl;
//
//    std::cout <<"\npreorder recursive: ";
//    tree.preorderR();
//
//    std::cout << "\npreorder iterative:  ";
//    tree.preorderI();
//
//    std::cout << "\ninorder recursive: ";
//    tree.inorderR();
//
//    std::cout << "\ninorder iterative:  ";
//    tree.inorderI();
//
//    std::cout << "\npostorder recursive: ";
//    tree.postorderR();
//
//    std::cout << "\npostorder iterative:  ";
//    tree.postorderI();
//
//    std::cout << "\nlevelOrder iterative:  ";
//    tree.levelorder();
//
//    std::cout << "\nCount of Nodes: " << tree.countOfNodesR();
//    std::cout << "\nCount of Leaves: " << tree.countOfLeavesR();
//
//    std::cout << "\nHeight of Tree: " << tree.heightR();
//    std::cout << "\nHeightPreorderI of Tree: " << tree.height_preorderI();
//    std::cout << "\nheightLevelOrderI of Tree: " << tree.height_levelorderI();
//    std::cout << "\nWidth of Tree: " << tree.widthR();
//    std::cout << "\nMax of Tree: " << tree.findMaxI();
//    std::cout << "\nMin of Tree: " << tree.findMinR();
//
//    std::cout << "deleting 7 15 20" << std::endl;
//
//    tree.eraseR(7);
//    tree.eraseR(15);
//    tree.eraseR(20);
//    tree.eraseR(15);
//
//
//    std::cout << "\ninorder recursive after deleting nodes: ";
//    tree.inorderR();
//
//    std::cout << "\nlevelOrder iterative:  ";
//    tree.levelorder();
//
//    tree.clearR();
//
//    std::cout << "\npostorder after clearing: ";
//    tree.postorderR();
//
//    std::cout << "\nMax data at level Iterative: ";
//    tree.maxOfLevelI();
//    std::cout << "\nMax data at level Recursive: ";
//    tree.maxOfLevelR();
//
//    std::cout << "\nLevels with the maximum count Iterative: ";
//    tree.maxCountLevelI();
//    std::cout << "\nLevels with the maximum count Recursive: ";
//    tree.maxCountLevelR();
//
//    std::cout << "\nTree is fullR: " << std::boolalpha << tree.isFullTreeR();
//    std::cout << "\nTree is fullI: " << std::boolalpha << tree.isFullTreeI();
//
//
//    BinaryTree<int> c = tree.copy();
//
//    std::cout << "\npreorder iterative:  ";
//    c.preorderI();
//
//    std::cout << "\ninorder iterative:  ";
//    c.inorderI();

    std::cout << "\nSum of elements above Ith levelI:  ";
    std::cout << tree.sumOfAboveIthLevel(5);

    std::cout << "\nSum of elements above Ith levelR:  ";
    std::cout << tree.sumOfAboveIthLevelR(5);


//
//    std::cout << "\nCount of Nodes with two childrens Iterative: " << tree.countNodesWithTwoChildrenI();
//    std::cout << "\nCount of Nodes with two childrens Recursive: " << tree.countNodesWithTwoChildrenR() << std ::endl;
//
//    std::cout << "\nCount of Nodes with one childrens Iterative: " << tree.countNodesWithOneChildI();
//    std::cout << "\nCount of Nodes with one childrens Recursive: " << tree.countNodesWithOneChildR() << std ::endl;
//
//    std::cout << "\nLevels with zero-valued nodes Iterative: ";
//    tree.levelsWithZeroNodesInorderI();
//    std::cout << "\nLevels with zero-valued nodes Recurisve: ";
//    tree.levelsWithZeroNodesInorderR();

//    std::cout << "\nNulls in level orderI: " << tree.nullsLevelorderI(7);
//    std::cout << "\nNulls in level orderR: " << tree.nullsLevelorderR(30);

    return 0;
}

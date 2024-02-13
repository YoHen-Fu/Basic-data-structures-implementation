#include<iostream>
#include<vector>
#include"BinTree.h"

int main(){
    // std::vector<int> nums{1, 2, 3, 4, 5, -1, -1, 8};
    // BinTree<int>* BT = new BinTree<int>();
    std::vector<char> nums{'a', 'b', 'c', 'd', 'e', '0', '0', 'f'};
    BinTree<char>* BT = new BinTree<char>();
    BT->setBinTree(nums);
    std::cout<<"二叉树的前序遍历结果为：";
    BT->getPreOrderT();
    std::cout<<"二叉树的中序遍历结果为：";
    BT->getInOrderT();
    std::cout<<"二叉树的后序遍历结果为：";
    BT->getPostOrderT();
    std::cout<<"二叉树的层次遍历结果为：";
    BT->getLevelOrderT();
    std::cout<<"二叉树的叶子结点为：";
    BT->getLeaves();
    std::cout<<std::endl;
    std::cout<<"二叉树的高度为："<< BT->getHeight();
}
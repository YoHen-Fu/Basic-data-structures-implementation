// 二叉树链表实现
#include<iostream>
#include<vector>
#include"BinTree.h"
#include <string>


int main(){
    std::vector<int> nums1{1, 2, 3, 4, 5, -1, -1, 8};
    std::vector<int> nums2{1, 2, 3, 5, 4, -1, -1, -1, -1, 8};
    BinTree<int>* BT1 = new BinTree<int>(nums1);
    BinTree<int>* BT2 = new BinTree<int>(nums2);
    std::cout<<"是否同构："<<BT1->IsIsomorphic(BT2);
}
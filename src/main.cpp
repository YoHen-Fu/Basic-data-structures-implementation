// 二叉树链表实现
#include<iostream>
#include<vector>
#include "LinkedList.h"

int main(){
    std::vector<int> nums1{1, 2, 3, 4, 5, -1, -1, 8};
    LinkedList<int> *LN = new LinkedList<int>();
    for(auto i = 0; i < nums1.size(); i++){
        LN->Insert(nums1[i], LN->getLength());
    }
    LNode<int>* LNode_tmp;
    LNode_tmp = LN->getValue();
    while(LNode_tmp){
        std::cout<<LNode_tmp->value<<" ";
        LNode_tmp = LNode_tmp->next;
    }
    std::cout<<std::endl;
    if(LN->Find(2)){
        std::cout<<LN->Find(2)->value;
    }
    if(LN->Find(12)){
        std::cout<<LN->Find(12)->value;
    }
    if(LN->Findith(3)){
        std::cout<<LN->Findith(3)->value;
    }
    if(LN->Findith(12)){
        std::cout<<LN->Findith(12)->value;
    }
}
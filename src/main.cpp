#include<iostream>
#include<vector>
#include "LinkedList.h"

int main(){
    std::vector<int> nums1{1, 2, 3, 4, 5, -1, -1, 8};
    LinkedList<int> *LN = new LinkedList<int>();
    for(auto i = 0; i < nums1.size(); i++){
        LN->Insert(nums1[i], LN->getLength());  //遍历给链表赋值
    }
    //链表的长度
    std::cout<<"链表的长度为："<<LN->getLength()<<std::endl;
    //输出链表中存储的值
    LNode<int>* LNode_tmp;
    LNode_tmp = LN->getValue();
    std::cout<<"链表中的值为：";
    while(LNode_tmp){
        std::cout<<LNode_tmp->value<<" ";
        LNode_tmp = LNode_tmp->next;
    }
    LN->Delete(2);
    std::cout<<std::endl;
    LNode_tmp = LN->getValue();
    std::cout<<"删除位置2处的元素后，链表中的值为："<<std::endl;
    while(LNode_tmp){
        std::cout<<LNode_tmp->value<<" ";
        LNode_tmp = LNode_tmp->next;
    }
    //查找链表中的值
    if(LN->Find(2)){
        std::cout<<"链表中存在值为2的元素";
    }else{
        std::cout<<"链表中不存在值为2的元素";
    }
    if(LN->Find(12)){
        std::cout<<LN->Find(12)->value<<std::endl;
    }
    if(LN->Findith(3)){
        std::cout<<"链表中位置3处的值为"<<LN->Findith(3)->value<<std::endl;
    }
    if(LN->Findith(12)){
        std::cout<<"链表中位置3处的值为"<<LN->Findith(12)->value<<std::endl;
    } 
}
#include "LinkedList.h"

/*******************构造与析构函数********************/
//构造与析构函数
template <typename LValueType>
LinkedList<LValueType>::LinkedList(){
    LN = nullptr;
}
template <typename LValueType>
LinkedList<LValueType>::~LinkedList(){
    LNode<LValueType> *LNode_tmp{LN};
    while(LN->next){
        LN = LN->next;
        delete LNode_tmp;
        LNode_tmp = LN;
    }
    delete LNode_tmp;
    LNode_tmp = nullptr;
}
/*******************添加与删除元素********************/
//在位置i处插入元素X，有头指针，因此编号从 1 开始
template <typename LValueType>
void LinkedList<LValueType>::Insert( LValueType X, Position i ){
    LNode<LValueType>* s_tmp;
    if(i == 0){
        LNode<LValueType>* Node_tmp = new LNode<LValueType>();
        Node_tmp->value = X;
        Node_tmp->next = LN;
        LN = Node_tmp;
        return;
    }
    s_tmp = Findith(i-1);
    if(s_tmp == nullptr){
        std::cout<<"插入位置不正确！";
        return;
    }
    LNode<LValueType>* p = new LNode<LValueType>();
    p->value = X;
    p->next = s_tmp->next;
    s_tmp->next = p;
}
//删除位置i处的元素
template <typename LValueType>
void LinkedList<LValueType>::Delete( Position i ){
    if(i == 0){
        LNode<LValueType>* LNode_tmp{LN};
        LN = LN->next;
        delete LNode_tmp;
        LNode_tmp = nullptr;
        return;
    }
    LNode<LValueType>* p = Findith(i-1);
    if(p == nullptr || p->next == nullptr){
        std::cout<<"删除位置不正确！";
        return;
    }
    LNode<LValueType>* s{p->next};
    p->next = p->next->next;
    delete s;
    s = nullptr;
}
/**********************查找元素************************/
//查找表中位置为i的元素
template <typename LValueType>
LNode<LValueType>* LinkedList<LValueType>::Findith( Position i ){
    LNode<LValueType>* Node_tmp{LN};
    int num{0};
    while(Node_tmp != nullptr && num < i){
        Node_tmp = Node_tmp->next;
        num++;
    }
    if(num == i){
        return Node_tmp;
    }
    return nullptr;
}
//查找表中元素X的位置
template <typename LValueType>
LNode<LValueType>* LinkedList<LValueType>::Find( LValueType X ){
    LNode<LValueType>* p = LN;
    while(p != nullptr){
        if(p->value == X){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}
/**********************链表属性************************/
//返回元素的长度
template <typename LValueType>
int LinkedList<LValueType>::getLength(){
    LNode<LValueType>* Node_tmp{LN};
    int length{0};
    while(Node_tmp != nullptr){
        length++;
        Node_tmp = Node_tmp->next;
    }
    delete Node_tmp;
    Node_tmp = nullptr;
    return length;
}

template <typename LValueType>
LNode<LValueType>* LinkedList<LValueType>::getValue(){
    return LN;
}

template class LinkedList<int>;
template class LinkedList<double>;
template class LinkedList<char>;
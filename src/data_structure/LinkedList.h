#pragma once
#include <iostream>

typedef int Position;
template <typename LValueType>
struct LNode{ 
    LNode<LValueType>* next; 
    LValueType value;
};

template <typename LValueType>
class LinkedList{
private:
  LNode<LValueType>* LN;
/*******************构造与析构函数********************/
public:
    LinkedList();
    ~LinkedList();
/*******************添加与删除元素********************/
public:
    void Insert( LValueType X, Position i );
    //删除位置i处的元素
    void Delete( Position i );
/**********************查找元素************************/
public:
    //查找表中位置为i的元素
    LNode<LValueType>* Findith( Position i );
    //查找表中元素X的位置
    LNode<LValueType>* Find( LValueType X );
/**********************链表属性************************/
public:
    //返回元素的长度
    int getLength();
    LNode<LValueType>* getValue();
};
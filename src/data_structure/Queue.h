// 队列的链式存储实现
#pragma once
#include<iostream>
#include"BinTree.h"

#define Error nullptr
template<typename QElementType>
struct QNodeVal{
    QElementType Data;
    struct QNodeVal *next;
};
template<typename QElementType>
struct QNode{
    struct QNodeVal<QElementType> *rear;
    struct QNodeVal<QElementType> *front;
};

template<typename QElementType>
class Queue{
private:
    QNode<QElementType>* PtrQ;
public:
    Queue():PtrQ{new QNode<QElementType>} {};
    ~Queue(){};
    //创建新队列
    void CreateQueue();
    //判断队列是否为空
    bool IsEmpty();
    //向队列中添加元素
    void AddQ(QElementType X);
    //从队列中删除元素
    QElementType DeleteQ();
};
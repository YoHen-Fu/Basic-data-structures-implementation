// 队列的链式存储实现
#pragma once
#include<iostream>
#include"BinTree.h"

#define Error nullptr
template<typename QValueType>
struct QNodeVal{
    QValueType Data;
    struct QNodeVal *next{nullptr};
};
template<typename QValueType>
struct QNode{
    struct QNodeVal<QValueType> *rear{nullptr};
    struct QNodeVal<QValueType> *front{nullptr};
};

template<typename QValueType>
class Queue{
private:
    QNode<QValueType>* PtrQ;
public:
    Queue():PtrQ{new QNode<QValueType>} {};
    ~Queue(){};
    //创建新队列
    void CreateQueue();
    //判断队列是否为空
    bool IsEmpty();
    //向队列中添加元素
    void AddQ(QValueType X);
    //从队列中删除元素
    QValueType DeleteQ();
};

//创建新队列
template<typename QValueType>
void Queue<QValueType>::CreateQueue(){
    PtrQ->front = PtrQ->rear = nullptr;
}
//判断队列是否为空
template<typename QValueType>
bool Queue<QValueType>::IsEmpty(){
    return (PtrQ->front == nullptr);
}
//向队列中添加元素
template<typename QValueType>
void Queue<QValueType>::AddQ(QValueType X){
    QNodeVal<QValueType> *FrontCurr = new QNodeVal<QValueType>;
    FrontCurr->Data = X;
    if(IsEmpty()){
        FrontCurr->next = PtrQ->front;
        PtrQ->front = FrontCurr;
        PtrQ->rear = FrontCurr;
    }else{
        PtrQ->rear->next = FrontCurr;
        PtrQ->rear = FrontCurr;
    }
}
//从队列中删除元素
template<typename QValueType>
QValueType Queue<QValueType>::DeleteQ(){
    QNodeVal<QValueType> *FrontCell = new QNodeVal<QValueType>;
    QValueType FrontElem;
    // if(IsEmpty()){
    //     std::cout<<"队列空！";
    //     return Error;
    // }
    // else{
        FrontCell = PtrQ->front;
        if(PtrQ->front == PtrQ->rear){
            PtrQ->front = PtrQ->rear = nullptr;
        }else{
            PtrQ->front = PtrQ->front->next;
        }
        FrontElem = FrontCell->Data;
        delete FrontCell;
        FrontCell = nullptr;
        return FrontElem;
    // }
}

// 队列的链式存储实现
#include<iostream>
#include "Queue.h"

//创建新队列
template<typename QElementType>
void Queue<QElementType>::CreateQueue(){
    PtrQ->front = PtrQ->rear = nullptr;
}
//判断队列是否为空
template<typename QElementType>
bool Queue<QElementType>::IsEmpty(){
    return (PtrQ->front == nullptr);
}
//向队列中添加元素
template<typename QElementType>
void Queue<QElementType>::AddQ(QElementType X){
    QNodeVal<QElementType> *FrontCurr = new QNodeVal<QElementType>;
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
template<typename QElementType>
QElementType Queue<QElementType>::DeleteQ(){
    QNodeVal<QElementType> *FrontCell = new QNodeVal<QElementType>;
    QElementType FrontElem;
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

template class Queue<int>;
template class Queue<char>;
template class Queue<TNode<int>*>;
template class Queue<TNode<char>*>;

// 队列的链式存储实现
#pragma once
#include<iostream>
#include"BinTree.h"

#define Error nullptr
template<typename QValueType>
struct QNodeVal{
    QValueType value;
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
    QNode<QValueType>* QNPtr{nullptr};
public:
    Queue():QNPtr{new QNode<QValueType>} {};
    ~Queue(){};
    //创建新队列
    void CreateQueue();
    //判断队列是否为空
    bool IsEmpty();
    //向队列中添加元素
    void AddQ(QValueType item);
    //从队列中删除元素
    QValueType DeleteQ();
};

//创建新队列
template<typename QValueType>
void Queue<QValueType>::CreateQueue(){
    QNPtr->front = QNPtr->rear = nullptr;
}
//判断队列是否为空
template<typename QValueType>
bool Queue<QValueType>::IsEmpty(){
    return (QNPtr->front == nullptr);
}
//向队列中添加元素
template<typename QValueType>
void Queue<QValueType>::AddQ(QValueType item){
    QNodeVal<QValueType> *FrontCurr = new QNodeVal<QValueType>;
    FrontCurr->value = item;
    if(IsEmpty()){
        FrontCurr->next = QNPtr->front;
        QNPtr->front = FrontCurr;
        QNPtr->rear = FrontCurr;
    }else{
        QNPtr->rear->next = FrontCurr;
        QNPtr->rear = FrontCurr;
    }
}
//从队列中删除元素
template<typename QValueType>
QValueType Queue<QValueType>::DeleteQ(){
    QNodeVal<QValueType> *FrontCell = new QNodeVal<QValueType>;
    QValueType FrontElem;
    try{
        if(!IsEmpty()){
            FrontCell = QNPtr->front;
            if(QNPtr->front == QNPtr->rear){
                QNPtr->front = QNPtr->rear = nullptr;
            }else{
                QNPtr->front = QNPtr->front->next;
            }
            FrontElem = FrontCell->value;
            delete FrontCell;
            FrontCell = nullptr;
            return FrontElem;
        }else{
            throw "队列为空！";
        }
    }catch(const char* msg){
        std::cerr << msg << std::endl;
    }
    throw "队列为空！";
}

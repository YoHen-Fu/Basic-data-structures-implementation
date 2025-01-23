#pragma once

typedef int Position;
template <typename LValueType>
struct LNode{ 
    LNode<LValueType>* next; 
    LValueType value;
};
template <typename LValueType>
class ILinkedList {
public:
    virtual ~ILinkedList() = default;
public:
    virtual void Insert( LValueType item, Position pos ) = 0;
    virtual void Delete( Position pos ) = 0;
    virtual LNode<LValueType>* Findith( Position pos ) = 0;
    virtual LNode<LValueType>* Find( LValueType item ) = 0;
    virtual int getLength() = 0;
    virtual LNode<LValueType>* getValue() = 0;
};

template <typename SValueType>
struct SNode{
    SValueType value;
    SNode* next;
};
template <typename SValueType>
class IStack{
public:
    virtual ~IStack() = default;
    //判断栈是否空
    virtual bool IsEmpty () = 0;
    //向栈中压入元素
    virtual void Push( SValueType item ) = 0;
    //从栈中弹出元素
    virtual SValueType Pop() = 0;
};

template<typename QValueType>
class IQueue{
public:
    virtual ~IQueue() = default;
    //创建新队列
    virtual void CreateQueue() = 0;
    //判断队列是否为空
    virtual bool IsEmpty() = 0;
    //向队列中添加元素
    virtual void AddQ(QValueType item) = 0;
    //从队列中删除元素
    virtual QValueType DeleteQ() = 0;
};
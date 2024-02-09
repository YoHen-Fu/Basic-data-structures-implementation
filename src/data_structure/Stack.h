#pragma once
typedef int ElementType;
typedef int Position;

template <typename SValueType>
struct SNode{
    SValueType value;
    SNode* next;
};

template <typename SValueType>
class Stack{
private:
    SNode<SValueType>* S;
public:
    Stack(){S = nullptr;};
    ~Stack(){};
    //判断栈是否空
    bool IsEmpty ();
    //向栈中压入元素
    void Push( SValueType item );
    //从栈中弹出元素
    SValueType Pop();
};
#pragma once

template <typename SValueType>
struct SNode{
    SValueType value;
    SNode* next;
};

template <typename SValueType>
class Stack{
private:
    SNode<SValueType>* SNPtr = nullptr;
public:
    Stack(){};
    ~Stack(){};
    //判断栈是否空
    bool IsEmpty ();
    //向栈中压入元素
    void Push( SValueType item );
    //从栈中弹出元素
    SValueType Pop();
};

//判断栈是否空
template <typename SValueType>
bool Stack<SValueType>::IsEmpty (){
    return (SNPtr == nullptr);
}

//向栈中压入元素
template <typename SValueType>
void Stack<SValueType>::Push( SValueType item ){
    SNode<SValueType>* SNPtr_tmp = new SNode<SValueType>();
    SNPtr_tmp->value = item;
    SNPtr_tmp->next = SNPtr;
    SNPtr = SNPtr_tmp;
}
//从栈中弹出元素
template <typename SValueType>
SValueType Stack<SValueType>::Pop(){
    try{
        if(SNPtr != nullptr){
            SValueType pop_value;
            SNode<SValueType>* SNPtr_tmp{SNPtr};
            SNPtr = SNPtr->next;
            pop_value = SNPtr_tmp->value;
            delete SNPtr_tmp;
            SNPtr_tmp = nullptr;
            return pop_value;
        }else{
            throw "堆栈为空！";
        }
    }catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    return -1;  
}
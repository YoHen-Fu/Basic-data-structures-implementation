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

//判断栈是否空
template <typename SValueType>
bool Stack<SValueType>::IsEmpty (){
    return (S == nullptr);
}

//向栈中压入元素
template <typename SValueType>
void Stack<SValueType>::Push( SValueType item ){
    SNode<SValueType>* S_tmp = new SNode<SValueType>();
    S_tmp->value = item;
    S_tmp->next = S;
    S = S_tmp;
}
//从栈中弹出元素
template <typename SValueType>
SValueType Stack<SValueType>::Pop(){
    try{
        if(S != nullptr){
            SValueType pop_value;
            SNode<SValueType>* S_tmp{S};
            S = S->next;
            pop_value = S_tmp->value;
            delete S_tmp;
            S_tmp = nullptr;
            return pop_value;
        }else{
            throw "堆栈为空！";
        }
    }catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    return -1;  
}
#include<iostream>
#include<vector>
#include "Stack.h"

int main(){
    std::vector<int> nums1{12, 2, 6, 8, 1, 10, 22, 25};
    Stack<int>* S = new Stack<int>();
    for(auto i = 0; i < nums1.size(); i++){
        S->Push(nums1[i]);
    }
    std::cout<<"堆栈中元素为：";
    while(!S->IsEmpty()){
        std::cout<<S->Pop()<<" ";
    }
}
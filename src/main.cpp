#include<iostream>
#include<vector>
#include"Stack.h"

int main(){
    std::vector<int> nums{1, 2, 3, 4, 5, -1, -1, 8};
    Stack<int> stack;
    for (size_t i = 0; i < nums.size(); i++)
    {
        stack.Push(nums[i]);
    }
    
    // std::cout << "The stack is empty: " << stack.IsEmpty() << std::endl;
    return 0;
}
#include <iostream>
#include <vector>
#include "DSFactory.h"
#include "DSInterface.h"

int main(){    
    std::vector<int> nums{10, 8, 11, 6, 9, -1, 12};
    IBinSearchTree<int>* Tree = DSFactory::createBinSearchTree<int>();
    Tree->setBinSTree(nums);
    auto tmp{Tree->Find(11)};
    if(tmp){
        std::cout<<tmp->value<<std::endl;
    }
    auto max{Tree->FindMax()};
    if(max){
        std::cout<<max->value<<std::endl;
    }
    auto min{Tree->FindMin()};
    if(min){
        std::cout<<min->value<<std::endl;
    }
    Tree->Insert(13);
    Tree->Insert(5);
    Tree->Insert(7);
    Tree->Delete(10);
    std::cout<<"程序执行完毕";
}
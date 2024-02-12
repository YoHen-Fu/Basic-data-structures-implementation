#include<iostream>
#include<vector>
#include"BinTree.h"
#include"Queue.h"

/*************************创建二叉树*********************/
template <typename TElementType>
BinTree<TElementType>::BinTree(std::vector<TElementType> TreeData){
    setBinTree(TreeData);
}
//创建二叉树
template <typename TElementType>
void BinTree<TElementType>::setBinTree( std::vector<TElementType> nums ){
    Tree = SetBinTree( Tree, nums, 1);
}

template <typename TElementType>
TNode<TElementType>* BinTree<TElementType>::getBinTree(){
    return Tree;
}

template <typename TElementType>
TNode<TElementType>* BinTree<TElementType>::SetBinTree( TNode<TElementType>* Tree, std::vector<TElementType> nums, int pos){
    if(typeid(nums[pos-1]) == typeid(int)){
        if(nums[pos-1] == -1){
            return nullptr;
        } 
    }else if(typeid(nums[pos-1]) == typeid(char)){
        if(nums[pos-1] == ' '){
            return nullptr;
        }
    }

    Tree = new TNode<TElementType>();
    Tree->value = nums[pos-1];
    if(pos*2 <= nums.size()){
        Tree->Left = SetBinTree( Tree->Left, nums, pos*2);
    }else{
        Tree->Left = nullptr;
    }
    if(pos*2+1 <= nums.size()){
        Tree->Right = SetBinTree( Tree->Right, nums, pos*2+1);
    }else{
        Tree->Right = nullptr;
    }
    return Tree;
}
/*******************二叉树基本性质**********************/
template <typename TElementType>
int BinTree<TElementType>::GetHeight(TNode<TElementType>* Tree){
    int maxH, HL, HR;
    if(Tree){
        HL = GetHeight(Tree->Left);
        HR = GetHeight(Tree->Right);
        maxH = HL > HR ? HL : HR;
        return maxH+1;
    }
    return 0;
} 
/*******************二叉树操作**********************/
template <typename TElementType>
void BinTree<TElementType>::getLeaves(){
    PreOrderPrintLeaves(Tree);
}
template <typename TElementType>
bool BinTree<TElementType>::IsIsomorphic( BinTree<TElementType>* BT2 ){
    return Isomorphic(Tree, BT2->getBinTree());
}

//打印叶结点
template <typename TElementType>
void BinTree<TElementType>::PreOrderPrintLeaves(TNode<TElementType>* Tree){
    if(Tree){
        if(Tree->Left == nullptr && Tree->Right == nullptr){
            std::cout<<Tree->value;
            std::cout<<" ";
        }
        PreOrderPrintLeaves(Tree->Left);
        PreOrderPrintLeaves(Tree->Right);
    }
}
template <typename TElementType>
bool BinTree<TElementType>::Isomorphic( TNode<TElementType>* Tree1, TNode<TElementType>* Tree2 ){
    if(!Tree1 && !Tree2){
        return 1;
    }
    if((!Tree1 && Tree2) || (Tree1 && !Tree2)){
        return 0;
    }
    if(Tree1->value != Tree2->value){
        return 0;
    }
    if(!Tree1->Left && !Tree2->Left){
        return Isomorphic(Tree1->Right, Tree2->Right);
    }
    if(Tree1->Left && Tree2->Left && Tree1->Left->value == Tree2->Left->value){
        return (Isomorphic(Tree1->Left, Tree2->Left) && Isomorphic(Tree1->Right, Tree2->Right));
    }
    else{
        return (Isomorphic(Tree1->Left, Tree2->Right) && Isomorphic(Tree1->Right, Tree2->Left));
    }
}
/*************************二叉树的遍历*****************************/

//先序遍历
template <typename TElementType>
void BinTree<TElementType>::getPreOrderT(){  
    PreOrderTraversal(Tree);
    std::cout<<std::endl;
}
//中序遍历
template <typename TElementType>
void BinTree<TElementType>::getInOrderT(){  
    InOrderTraversal(Tree);
    std::cout<<std::endl;
}
//后序遍历
template <typename TElementType>
void BinTree<TElementType>::getPostOrderT(){  
    PostOrderTraversal(Tree);
    std::cout<<std::endl;
}
//层次遍历
template <typename TElementType>
void BinTree<TElementType>::getLevelOrderT(){  
    Queue<TNode<TElementType>*>* Q = new Queue<TNode<TElementType>*>();
    TNode<TElementType>* T;
    if(!Tree){return;}
    Q->CreateQueue();
    Q->AddQ(Tree);
    while(!Q->IsEmpty()){
        T = Q->DeleteQ();
        std::cout<<T->value;
        std::cout<<" ";
        if(T->Left){Q->AddQ(T->Left);}
        if(T->Right){Q->AddQ(T->Right);}
    }
    std::cout<<std::endl;
}

//先序遍历
template <typename TElementType>
void BinTree<TElementType>::PreOrderTraversal(TNode<TElementType>* Tree){  
    if(Tree){
        std::cout<<Tree->value;
        std::cout<<" ";
        PreOrderTraversal(Tree->Left);
        PreOrderTraversal(Tree->Right);
    }
}
//中序遍历
template <typename TElementType>
void BinTree<TElementType>::InOrderTraversal(TNode<TElementType>* Tree){  
    if(Tree){
        InOrderTraversal(Tree->Left);
        std::cout<<Tree->value;
        std::cout<<" ";
        InOrderTraversal(Tree->Right);
    }
}
//后序遍历
template <typename TElementType>
void BinTree<TElementType>::PostOrderTraversal(TNode<TElementType>* Tree){  
    if(Tree){
        PostOrderTraversal(Tree->Left);
        PostOrderTraversal(Tree->Right);
        std::cout<<Tree->value;
        std::cout<<" ";
    }
}

template class BinTree<int>;
template class BinTree<char>;
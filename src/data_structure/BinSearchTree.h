#include "DSInterface.h"

template <typename BSTElementType>
class BinSearchTree : public IBinSearchTree<BSTElementType>{
public:
    BinSearchTree();
    ~BinSearchTree();
public:
    //判断二叉搜索树是否为空
    bool IsEmpty();
    //给二叉树赋值
    BSTNode<BSTElementType>* setBinSTree(std::vector<BSTElementType> nums) override;
    //查找二叉搜索树中的元素X，返回所在地址
    BSTNode<BSTElementType>* Find( BSTElementType X ) override;
    //返回二叉搜索树中最大值地址
    BSTNode<BSTElementType>* FindMax() override;
    //返回二叉搜索树中最小地址
    BSTNode<BSTElementType>* FindMin() override;
    //向二叉搜索树中插入元素
    BSTNode<BSTElementType>* Insert( BSTElementType X ) override;
    //删除二叉搜索树中的元素
    BSTNode<BSTElementType>* Delete( BSTElementType X ) override;
private:
    BSTNode<BSTElementType>* RCFind( BSTElementType X, BSTNode<BSTElementType>* BST_tmp );
    BSTNode<BSTElementType>* RCFindMax( BSTNode<BSTElementType>* BST_tmp );
    BSTNode<BSTElementType>* RCFindMin( BSTNode<BSTElementType>* BST_tmp );
    BSTNode<BSTElementType>* RCInsert( BSTElementType X, BSTNode<BSTElementType>* BST_tmp );
    BSTNode<BSTElementType>* RCDelete( BSTElementType X, BSTNode<BSTElementType>* BST_tmp );
private:
    BSTNode<BSTElementType>* BSTree = new BSTNode<BSTElementType>();
};

template <typename BSTElementType>
BinSearchTree<BSTElementType>::BinSearchTree(){}
template <typename BSTElementType>
BinSearchTree<BSTElementType>::~BinSearchTree(){}

//判断二叉搜索树是否为空
template <typename BSTElementType>
bool BinSearchTree<BSTElementType>::IsEmpty(){
    return (BSTree == nullptr);
}
//给二叉树赋值
template <typename BSTElementType>
BSTNode<BSTElementType>* BinSearchTree<BSTElementType>::setBinSTree(std::vector<BSTElementType> nums){
    BSTree->value = nums[0];
    for(auto i = 1; i < nums.size(); i++){
        Insert(nums[i]);
    }
    return BSTree;
}
//查找二叉搜索树中的元素X，返回所在地址
template <typename BSTElementType>
BSTNode<BSTElementType>* BinSearchTree<BSTElementType>::Find( BSTElementType X ){
    return RCFind(X, BSTree);
}
template <typename BSTElementType>
BSTNode<BSTElementType>* BinSearchTree<BSTElementType>::RCFind( BSTElementType X, BSTNode<BSTElementType>* BST_tmp ){
    if(BST_tmp == nullptr){
        return nullptr;
    }
    if(X<BST_tmp->value){
        BST_tmp = BST_tmp->Left;
        return RCFind(X, BST_tmp);
    }else if(X>BST_tmp->value){
        BST_tmp = BST_tmp->Right;
        return RCFind(X, BST_tmp);
    }else{
        return BST_tmp;
    }
}
//返回二叉搜索树中最大值地址
template <typename BSTElementType>
BSTNode<BSTElementType>* BinSearchTree<BSTElementType>::FindMax(){
    return RCFindMax(BSTree);
}
template <typename BSTElementType>
BSTNode<BSTElementType>* BinSearchTree<BSTElementType>::RCFindMax( BSTNode<BSTElementType>* BST_tmp ){
    if(BST_tmp == nullptr){
        return nullptr;
    }
    if(BST_tmp->Right){
        BST_tmp = RCFindMax(BST_tmp->Right);
    }
    return BST_tmp;
}
//返回二叉搜索树中最小地址
template <typename BSTElementType>
BSTNode<BSTElementType>* BinSearchTree<BSTElementType>::FindMin(){
    return RCFindMin(BSTree);
}
template <typename BSTElementType>
BSTNode<BSTElementType>* BinSearchTree<BSTElementType>::RCFindMin( BSTNode<BSTElementType>* BST_tmp ){
    if(BST_tmp == nullptr){
        return nullptr;
    }
    if(BST_tmp->Left){
        BST_tmp = RCFindMin(BST_tmp->Left);
    }
    return BST_tmp;
}
//向二叉搜索树中插入元素
template <typename BSTElementType>
BSTNode<BSTElementType>* BinSearchTree<BSTElementType>::Insert( BSTElementType X ){
    return RCInsert(X, BSTree);
}
template <typename BSTElementType>
BSTNode<BSTElementType>* BinSearchTree<BSTElementType>::RCInsert( BSTElementType X, BSTNode<BSTElementType>* BST_tmp ){
    if(BST_tmp == nullptr){
        BSTNode<BSTElementType>* TN_tmp = new BSTNode<BSTElementType>();
        TN_tmp->value = X;
        TN_tmp->Left = nullptr;
        TN_tmp->Right = nullptr;
        BST_tmp = TN_tmp;
    }
    if(X < BST_tmp->value){
        if(BST_tmp->Left == nullptr){
            BSTNode<BSTElementType>* TN_tmp = new BSTNode<BSTElementType>();
            TN_tmp->value = X;
            TN_tmp->Left = nullptr;
            TN_tmp->Right = nullptr;
            BST_tmp->Left = TN_tmp;
        }
        BST_tmp = RCInsert(X, BST_tmp->Left);
    }else if(X > BST_tmp->value){
        if(BST_tmp->Right == nullptr){
            BSTNode<BSTElementType>* TN_tmp = new BSTNode<BSTElementType>();
            TN_tmp->value = X;
            TN_tmp->Left = nullptr;
            TN_tmp->Right = nullptr;
            BST_tmp->Right = TN_tmp;
        }
        BST_tmp = RCInsert(X, BST_tmp->Right);
    }
    return BST_tmp;
}
//删除二叉搜索树中的元素
template <typename BSTElementType>
BSTNode<BSTElementType>* BinSearchTree<BSTElementType>::Delete( BSTElementType X ){
    return RCDelete(X, BSTree);
}
template <typename BSTElementType>
BSTNode<BSTElementType>* BinSearchTree<BSTElementType>::RCDelete( BSTElementType X, BSTNode<BSTElementType>* BST_tmp ){
    if(!BST_tmp){
        std::cout<<"要删除的元素未找到！"<<std::endl;
    }
    else if(X < BST_tmp->value){  //删除的元素值小于当前元素值
        BST_tmp->Left = RCDelete(X, BST_tmp->Left);
    }else if(X > BST_tmp->value){  //删除的元素值大于当前元素值
        BST_tmp->Right = RCDelete(X, BST_tmp->Right);
    }else{  //删除的元素值等于当前元素值
        BSTNode<BSTElementType> * tmp{BST_tmp};
        if(BST_tmp->Left && BST_tmp->Right){  //被删除的元素同时存在左右两个子结点
            tmp = RCFindMin(BST_tmp->Right);
            BST_tmp->value = tmp->value;
            BST_tmp->Right = RCDelete(BST_tmp->value, BST_tmp->Right);
        }else{
            if(BST_tmp->Left){
                BST_tmp = BST_tmp->Left;
            }else if(BST_tmp->Right){
                BST_tmp = BST_tmp->Right;
            }
            delete tmp;
            tmp = nullptr;
        }
    }
    return BST_tmp;
}

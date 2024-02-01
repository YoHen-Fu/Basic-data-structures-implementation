#pragma once
#include <iostream>
#include <vector>
#include <typeinfo>

//定义二叉树基本结点
template <typename TElementType>
struct TNode{
    TNode* Left;
    TNode* Right;
    TElementType value;
};

//定义二叉树类
template <typename TElementType>
class BinTree{
private:
    TNode<TElementType>* Tree{nullptr};
public:
    BinTree(){CreatBinTree();}
    BinTree(std::vector<TElementType> TreeData);
    ~BinTree(){}
/*************************创建二叉树*********************/
public:
    //创建二叉树
    void setBinTree( std::vector<TElementType> nums );
    TNode<TElementType>* getTree();
private:
    void CreatBinTree();
    TNode<TElementType>* SetBinTree(TNode<TElementType>* Tree, std::vector<TElementType> nums, int pos);
/*******************二叉树基本性质**********************/
public:
    //判断二叉树是否为空
    bool IsEmpty(){return (Tree == nullptr);    }
    //二叉树的高度
    int getHeight(){return GetHeight( Tree );    }
private:
    int GetHeight(TNode<TElementType>* Tree);
/*******************二叉树操作**********************/
public: 
    //反转
    void Traversal();
    void getLeaves();
    bool IsIsomorphic( BinTree<TElementType>* BT2 );
    // void operator=(std::vector<TElementType>* TreeData) {
    //     this->setBinTree(TreeData);
    // }
    
private:
    //打印叶结点
    void PreOrderPrintLeaves(TNode<TElementType>* Tree);
    bool Isomorphic( TNode<TElementType>* Tree1, TNode<TElementType>* Tree2 );
/*************************二叉树的遍历*****************************/
public:
    //先序遍历
    void getPreOrderT();
    //中序遍历
    void getInOrderT();
    //后序遍历
    void getPostOrderT();
    //层次遍历
    void getLevelOrderT();
private:
    //先序遍历
    void PreOrderTraversal(TNode<TElementType>* Tree);
    //中序遍历
    void InOrderTraversal(TNode<TElementType>* Tree);
    //后序遍历
    void PostOrderTraversal(TNode<TElementType>* Tree);
    //先序遍历输出二叉树中叶子结点
};
#pragma once
#include <vector>

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

template <typename TElementType>
struct TNode{
    TNode* Left;
    TNode* Right;
    TElementType value;
};
template <typename TElementType>
class IBinTree{
public:
    virtual ~IBinTree() = default;
/*************************创建二叉树*********************/
public:
    //创建二叉树
    virtual void setBinTree( std::vector<TElementType> nums ) = 0;
    virtual TNode<TElementType>* getBinTree() = 0;
    //判断二叉树是否为空
    virtual bool IsEmpty() = 0;
    //二叉树的高度
    virtual int getHeight() = 0;
    virtual void getLeaves() = 0;
    virtual bool IsIsomorphic( IBinTree<TElementType>* BT2 ) = 0;
    //先序遍历
    virtual void getPreOrderT() = 0;
    //中序遍历
    virtual void getInOrderT() = 0;
    //后序遍历
    virtual void getPostOrderT() = 0;
    //层次遍历
    virtual void getLevelOrderT() = 0;
};
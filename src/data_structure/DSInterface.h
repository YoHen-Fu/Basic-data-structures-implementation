#pragma once
#include <vector>

typedef int Position;
typedef unsigned int uint;

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

// 二叉搜索树
template <typename BSTElementType>
struct BSTNode{
    BSTNode* Left;
    BSTNode* Right;
    BSTElementType value;
};
template <typename BSTElementType>
class IBinSearchTree{
public:
    virtual ~IBinSearchTree() = default;
public:
    //判断二叉搜索树是否为空
    virtual bool IsEmpty() = 0;
    //给二叉树赋值
    virtual BSTNode<BSTElementType>* setBinSTree(std::vector<BSTElementType> nums) = 0;
    //查找二叉搜索树中的元素X，返回所在地址
    virtual BSTNode<BSTElementType>* Find( BSTElementType X ) = 0;
    //返回二叉搜索树中最大值地址
    virtual BSTNode<BSTElementType>* FindMax() = 0;
    //返回二叉搜索树中最小地址
    virtual BSTNode<BSTElementType>* FindMin() = 0;
    //向二叉搜索树中插入元素
    virtual BSTNode<BSTElementType>* Insert( BSTElementType X) = 0;
    //删除二叉搜索树中的元素
    virtual BSTNode<BSTElementType>* Delete( BSTElementType X ) = 0;
};

template<typename HeapElementType>
struct HeapStruct{
    HeapElementType* Elements;
    uint Size;
    uint Capacity;
};
template<typename HeapElementType>
class IMaxHeap{
public:
        virtual IMaxHeapMaxHeap() = default;
public:
    //创建最大堆
    virtual HeapStruct* CreateMaxHeap( HeapStruct* H, int MaxSize ) = 0;
    //判断堆是否满
    virtual bool IsFull( HeapStruct* H ) = 0;
    //判断堆是否空
    virtual bool IsEmpty( HeapStruct* H ) = 0;
    //向堆中插入元素
    virtual void Insert( HeapStruct* H, HeapElementType item ) = 0;
    //删除堆顶元素，并调整堆仍为最大堆
    virtual HeapElementType DeleteMax( HeapStruct* H ) = 0;
};
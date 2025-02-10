#pragma once
#include "DSInterface.h"

struct HeapStruct{
    int* Elements;
    int Size;
    int Capacity;
};

template<typename HeapElementType>
class MaxHeap :  public IMaxHeap<HeapElementType>{
public:
        MaxHeap();
        ~MaxHeap();
public:
    //创建最大堆
    HeapStruct* CreateMaxHeap( HeapStruct* H, int MaxSize ) override;
    //判断堆是否满
    bool IsFull( HeapStruct* H ) override;
    //判断堆是否空
    bool IsEmpty( HeapStruct* H ) override;
    //向堆中插入元素
    void Insert( HeapStruct* H, HeapElementType item ) override;
    //删除堆顶元素，并调整堆仍为最大堆
    HeapElementType DeleteMax( HeapStruct* H ) override;
};


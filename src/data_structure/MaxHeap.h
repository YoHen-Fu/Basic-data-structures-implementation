#pragma once
#include "DSInterface.h"

template<typename HeapElementType>
class MaxHeap :  public IMaxHeap<HeapElementType>{
public:
        MaxHeap(std::vector<HeapElementType> HeapData, uint MaxData, uint MaxSize);
        ~MaxHeap();
public:
    //创建最大堆
    HeapStruct* CreateMaxHeap( HeapStruct* H, int MaxSize ) override;
    //判断堆是否满
    bool IsFull() override;
    //判断堆是否空
    bool IsEmpty() override;
    //向堆中插入元素
    void Insert( HeapElementType item ) override;
    //删除堆顶元素，并调整堆仍为最大堆
    HeapElementType DeleteMax() override;
private:
    HeapStruct* Heap;
};

template<typename HeapElementType>
MaxHeap<HeapElementType>::MaxHeap(std::vector<HeapElementType> HeapData, uint MaxData, uint MaxSize){
    Heap->Elements = new int[HeapData.size()+1];
    Heap->Elements[0] = MaxData;
    Heap->Size = HeapData.size();
    Heap->Capacity = MaxSize;
    for(int i = 1; i < HeapData.size()+1; i++){
        Insert(HeapData[i]);
    }
}

template<typename HeapElementType>
bool MaxHeap<HeapElementType>::IsFull(){
    return Heap->Size == Heap->Capacity;
}

template<typename HeapElementType>
bool MaxHeap<HeapElementType>::IsEmpty(){
    return Heap->Size == 0;
}

template<typename HeapElementType>
void MaxHeap<HeapElementType>::Insert(HeapElementType item){
    if(IsFull()){
        std::cout<<"最大堆已满！"<<std::endl;
        return;
    }
    uint index{++H->Size};
    for( ; item > H->Elements[index/2]; index/=2){
        H->Elements[index] = H->Elements[index/2];
    }
    H->Elements[index] = item;
}

//删除堆顶元素，并调整堆仍为最大堆
template<typename HeapElementType>
HeapElementType MaxHeap<HeapElementType>::DeleteMax(){
    int MaxItem{0}, tmp{0};
    int Parent, Child;
    if(IsEmpty(H)){
        std::cout<<"堆为空！"<<std::endl;
        return -1;
    }
    MaxItem = H->Elements[1];
    tmp = H->Elements[H->Size--];
    for( Parent = 1; Parent*2 < H->Size; Parent = Child ){
        Child = Parent*2;
        if(Child < H->Size && (H->Elements[Child] < H->Elements[Child+1])){
            Child++;
        }
        if(tmp > H->Elements[Child]) break;
        else{
            H->Elements[Parent] = H->Elements[Child];
        }
    }
    H->Elements[Parent] = tmp;
    return MaxItem;
}

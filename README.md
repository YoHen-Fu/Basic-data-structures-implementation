# 基本数据结构的C++实现

## 1、数组（Array）

**public functions:**

| type | function name |
| ----:|:------------- |
|      |               |
|      |               |
|      |               |
|      |               |
|      |               |
|      |               |

## 2、[链表（Liked List）](./docs/LinkedList.md)

**public functions:**

| type                 | function name                      |
| --------------------:|:---------------------------------- |
|                      | `LinkedList()`                     |
|                      | `~LinkedList()`                    |
| `void`               | `Insert(LValueType X, Position i)` |
| `void`               | `Delete(Position i)`               |
| `LNode<LValueType>*` | `Findith(Position i)`              |
| `LNode<LValueType>*` | `Find(LValueType X)`               |
| `int`                | `getLength()`                      |
| `LNode<LValueType>*` | `getValue()`                       |

**test**

```c
#include<iostream>
#include<vector>
#include "LinkedList.h"

int main(){
    std::vector<int> nums1{1, 2, 3, 4, 5, -1, -1, 8};
    LinkedList<int> *LN = new LinkedList<int>();
    for(auto i = 0; i < nums1.size(); i++){
        LN->Insert(nums1[i], LN->getLength());  //遍历给链表赋值
    }
    //链表的长度
    std::cout<<"链表的长度为："<<LN->getLength()<<std::endl;
    //输出链表中存储的值
    LNode<int>* LNode_tmp;
    LNode_tmp = LN->getValue();
    std::cout<<"链表中的值为：";
    while(LNode_tmp){
        std::cout<<LNode_tmp->value<<" ";
        LNode_tmp = LNode_tmp->next;
    }
    LN->Delete(2);
    std::cout<<std::endl;
    LNode_tmp = LN->getValue();
    std::cout<<"删除位置2处的元素后，链表中的值为："<<std::endl;
    while(LNode_tmp){
        std::cout<<LNode_tmp->value<<" ";
        LNode_tmp = LNode_tmp->next;
    }
    //查找链表中的值
    if(LN->Find(2)){
        std::cout<<"链表中存在值为2的元素";
    }else{
        std::cout<<"链表中不存在值为2的元素";
    }
    if(LN->Find(12)){
        std::cout<<LN->Find(12)->value;
    }
    if(LN->Findith(3)){
        std::cout<<"链表中位置3处的值为"<<LN->Findith(3)->value;
    }
    if(LN->Findith(12)){
        std::cout<<"链表中位置3处的值为"<<LN->Findith(12)->value;
    } 
}
```

**output**

```c
链表的长度为：8
链表中的值为：1 2 3 4 5 -1 -1 8
删除位置2处的元素后，链表中的值为：
1 2 4 5 -1 -1 8 链表中存在值为2的元素链表中位置3处的值为5
```

## [3、栈（Stack）](./docs/Stack.md)

**public functions:**

| type         | function name |
| ------------:|:------------- |
|              | `Stack()`     |
|              | `~Stack()`    |
| `int`        | `IsEmpty()`   |
| `void`       | `Push()`      |
| `SValueType` | `Pop()`       |

**test**

```c
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
```

**outpu**

```c
堆栈中元素为：25 22 10 1 8 6 2 12
```

## 4、[队列（Queue）](./docs/Queue.md)

**public functions:**

| type           | function name          |
| --------------:|:---------------------- |
|                | `Queue()`              |
|                | `~Queue()`             |
| `void`         | `CreateQueue()`        |
| `bool`         | `IsEmpty()`            |
| `void`         | `AddQ(QElementType X)` |
| `QElementType` | `Delete()`             |

## 5、树（Tree）

**public functions:**

| type | function name |
| ----:|:------------- |
|      |               |
|      |               |
|      |               |
|      |               |
|      |               |
|      |               |

## 6、散列表（Hash）

**public functions:**

| type | function name |
| ----:|:------------- |
|      |               |
|      |               |
|      |               |
|      |               |
|      |               |
|      |               |

## 7、 堆（Heap）

**public functions:**

| type | function name |
| ----:|:------------- |
|      |               |
|      |               |
|      |               |
|      |               |
|      |               |
|      |               |

## 8、图（Graph）

**public functions:**

| type | function name |
| ----:|:------------- |
|      |               |
|      |               |
|      |               |
|      |               |
|      |               |
|      |               |

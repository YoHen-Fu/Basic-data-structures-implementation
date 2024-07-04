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
    try{
        S->Pop();
    }catch(const char* e){
        std::cout<<e<<std::endl;
    }
    delete S;
    S = nullptr;
    return 0;
}
```

**output**

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

**test**

```c
#include<iostream>
#include<vector>
#include"Queue.h"

int main(){
    Queue<int>* Qe = new Queue<int>();
    Qe->AddQ(12);
    Qe->AddQ(5);
    int res;
    while(!Qe->IsEmpty()){
        std::cout<<Qe->DeleteQ()<<" ";
    }
}
```

**output**

```c
12 5
```

## 5、树（Tree）

### [基本二叉树（BinTree）](./docs/BinTree.md)

**public functions:**

| type                   | function name                                 |
| ----------------------:|:--------------------------------------------- |
|                        | `BinTree()`                                   |
|                        | `BinTree(std::vector<TElementType> TreeData)` |
|                        | `~BinTree()`                                  |
| `void`                 | `setBinTree(std::vector<TElementType> nums)`  |
| `TNode<TElementType>*` | `getBinTree()`                                |
| `int`                  | `getHeight`                                   |
| `void`                 | `getLeaves`                                   |
| `void`                 | `getPreOrderT()`                              |
| `void`                 | `getInOrderT()`                               |
| `void`                 | `getPostOrderT()`                             |
| `void`                 | `getLevelOrderT()`                            |
| `bool`                 | `IsIsomorphic(BinTree<TElementType>* BT2)`    |

**private function**

| type                   | function name                                                                    |
| ----------------------:|:-------------------------------------------------------------------------------- |
| `TNode<TElementType>*` | `SetBinTree(TNode<TElementType>* Tree, std::vector<TElementType> nums, int pos)` |
| `int`                  | `GetHeight(TNode<TElementType>* Tree)`                                           |
| `void`                 | `PreOrderPrintLeaves(TNode<TElementType>* Tree)`                                 |
| `bool`                 | `Isomorphic(TNode<TElementType>* Tree1, TNode<TElementType>* Tree2)`             |
| `void`                 | `PreOrderTraversal(TNode<TElementType>* Tree)`                                   |
| `void`                 | `InOrderTraversal(TNode<TElementType>* Tree)`                                    |
| `void`                 | `PostOrderTraversal(TNode<TElementType>* Tree)`                                  |

**test**

```c
#include<iostream>
#include<vector>
#include"BinTree.h"

int main(){
    // std::vector<int> nums{1, 2, 3, 4, 5, -1, -1, 8};
    // BinTree<int>* BT = new BinTree<int>();
    std::vector<char> nums{'a', 'b', 'c', 'd', 'e', '0', '0', 'f'};
    BinTree<char>* BT = new BinTree<char>();
    BT->setBinTree(nums);
    std::cout<<"二叉树的前序遍历结果为：";
    BT->getPreOrderT();
    std::cout<<"二叉树的中序遍历结果为：";
    BT->getInOrderT();
    std::cout<<"二叉树的后序遍历结果为：";
    BT->getPostOrderT();
    std::cout<<"二叉树的层次遍历结果为：";
    BT->getLevelOrderT();
    std::cout<<"二叉树的叶子结点为：";
    BT->getLeaves();
    std::cout<<std::endl;
    std::cout<<"二叉树的高度为："<< BT->getHeight();
}
```

**output**

```c
二叉树的前序遍历结果为：a b d f e c 0 0
二叉树的中序遍历结果为：f d b e a 0 c 0
二叉树的后序遍历结果为：f d e b 0 0 c a
二叉树的层次遍历结果为：a b c d e 0 0 f
二叉树的叶子结点为：f e 0 0
二叉树的高度为：4
```

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

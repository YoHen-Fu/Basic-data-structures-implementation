# BinTree

## 详细描述（Detailed Description）

### `BinTree()`

默认构造函数

### `BinTree(std::vector<TElementType> TreeData)`

带参构造函数，将`TreeData`中的数据储存到二叉树中

### `~BinTree()`

默认析构函数

### `void setBinTree(std::vector<TElementType> nums)`

设置二叉树中存储的数据为`num`

### `TNode<TElementType>* getBinTree()`

返回类`BinTree`中存储的二叉树

### `int getHeight()`

返回二叉树的高度

### `void getPreOrderT()`

前序遍历输出二叉树中的值

### `void getInOrderT()`

中序遍历输出二叉树的值

### `void getPostOrderT()`

后序遍历输出二叉树的值

### `void getLevelOrderT()`

层次遍历输出二叉树的值

### `bool IsIsomorphic(BinTree* BT2)`

判断两个二叉树是否同构

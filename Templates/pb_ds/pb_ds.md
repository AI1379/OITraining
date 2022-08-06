# pb_ds食用教程

> 平板电视：比STL还STL
> 
> ——来自luogu某佬

## Intro 前言

`pb_ds`的主体部分在`__gnu_pb_ds`命名空间下，使用前需要`using namespace __gnu_pbds`

头文件如下：

```cpp
#include <ext/pb_ds/assoc_container.hpp> // 某种单链表 OI里没用
#include <ext/pb_ds/tree_policy.hpp> // tree
#include <ext/pb_ds/hash_policy.hpp> // hash
#include <ext/pb_ds/trie_policy.hpp> // trie
#include <ext/pb_ds/priority_queue.hpp> // priority_queue
```

或者

```cpp
#include <bits/extc++.h>
// 类似bits/stdc++.h
// 据称这个文件在dev-c++里面会报找不到文件 因此建议上面的写法
```

**WARNING: pb_ds是以libstdc++为标准库的编译器中专属的库 仅gcc可用**

为什么要`pb_ds`？

它封装了可并堆，字典树，平衡树等一堆常用且难搞的东西，极大程度减少码量，甚至可能可以降低时间复杂度。

## hash 哈希表

## trie 字典树

## tree 平衡树

## priority_queue 堆

> 注意：如果用`__gnu_pbds::priority_queue`那么建议不要引用万能头或者`using namespace std`以免与`std::priority_queue`发生冲突导致CE。

### 前置知识：如何自定义`priority_queue`的排序方式

~~其实这个前置知识并不会影响pbds的使用~~

我们都知道，对于一个结构体，我们不能直接把它丢进`priority_queue`，无论是STL还是pbds。那么我们有两种方案：重载小于号，或者写一个**仿函数 functor**

仿函数听着玄乎，其实很简单，只是一个重载了括号运算符的结构体而已。

比方说，众所周知，有个东西叫`std::less`，它其实就是一个仿函数，实现也很简单：

```cpp
template<typename T>
struct less{
    bool operator()(const T& lhs,const T& rhs){
        return lhs<rhs;
    }
};
```

那么，我们同样也可以自己写一个`comp`，用来比较，就像这样：

```cpp
struct comp{
    bool operator()(int x, int y){
        return dis[x] > dis[y];
    }    
};
```

使用的时候则这么用：

```cpp
std::priority_queue<int,std::vector<int>,comp> q;
```

于是就可以得到堆里面装了数组下标，以下标对应的`dis`值为关键字的小根堆

~~是不是非常简单~~

### 模板参数 & 成员函数

```cpp
template<
    typename ValueType,
    typename Comp = std::less<ValueType>,
    typename Tag = pairing_heap_tag,
    typename Alloc = std::allocator<char>>
class priority_queue;
```

其中：

+ `ValueType`是堆里面的元素类型

+ `Comp`是比较器，是一个functor。注意pbds的堆和STL一样 传入less会得到大根堆

+ `Tag`是堆的实现，总共有以下几种：
  
  + `pairing_heap_tag` 配对堆 最有用
  
  + `binary_heap_tag` 二叉堆
  
  + `binomial_heap_tag` 二项堆
  
  + `rc_binomial_heap_tag` 冗余计数二项堆
  
  + `thin_heap_tag` Tarjan老爷子发明的一种 除了合并以外复杂度都和Fibonacci堆一样的一种堆

+ `Alloc`是空间分配器，不用管他，省略即可 

除了`pairing_heap_tag`以外，其他四个在OI中都不如`std::pirority_queue`。配对堆不仅优于STL的二叉堆，同时也优于`algorithm`头文件中的`make_heap`系列函数。

五种tag都支持以下的操作：

+ `push` 压入一个元素

+ `pop` 弹出一个元素

+ `top` 获得堆顶

+ `size` 获得大小

+ `empty` 获得是否为空

+ `modify` 修改某一个位置的元素 并且重新调整结构

+ `erase` 删除某一个位置的元素

+ `join` 合并两个堆

### 复杂度

|                        | push                                | pop                                 | modify                                                         | erase                               | join              |
| ---------------------- | ----------------------------------- | ----------------------------------- | -------------------------------------------------------------- | ----------------------------------- | ----------------- |
| `std::priority_queue`  | 最坏$\Theta(n)$均摊$\Theta(\log n)$     | $\Theta(\log n)$                    | $\Theta(n\log n)$                                              | $\Theta(n\log n)$                   | $\Theta(n\log n)$ |
| `pairing_heap_tag`     | $O(1)$                              | 最坏 $\Theta(n)$ 均摊 $\Theta(\log(n))$ | 最坏 $\Theta(n)$ 均摊 $\Theta(\log(n))$                            | 最坏 $\Theta(n)$ 均摊 $\Theta(\log(n))$ | $O(1)$            |
| `binary_heap_tag`      | 最坏 $\Theta(n)$ 均摊 $\Theta(\log(n))$ | 最坏 $\Theta(n)$ 均摊 $\Theta(\log(n))$ | $\Theta(n)$                                                    | $\Theta(n)$                         | $\Theta(n)$       |
| `binomial_heap_tag`    | 最坏 $\Theta(\log(n))$ 均摊 $O(1)$      | $\Theta(\log(n))$                   | $\Theta(\log(n))$                                              | $\Theta(\log(n))$                   | $\Theta(\log(n))$ |
| `rc_binomial_heap_tag` | $O(1)$                              | $\Theta(\log(n))$                   | $\Theta(\log(n))$                                              | $\Theta(\log(n))$                   | $\Theta(\log(n))$ |
| `thin_heap_tag`        | $O(1)$                              | 最坏 $\Theta(n)$ 均摊 $\Theta(\log(n))$ | 最坏 $\Theta(\log(n))$ 均摊 $O(1)$或者$\Theta(\log n)$ 这取决于修改是增加还是减少 | 最坏 $\Theta(n)$ 均摊 $\Theta(\log(n))$ | $\Theta(n)$       |

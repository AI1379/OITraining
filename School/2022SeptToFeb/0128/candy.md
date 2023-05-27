# candy

由于每个人都只考虑左边和右边，所以某一位上的变化对整体变化并不大，因此不会存在让某一位变大使总和变小的情况——也就是说这个题可以贪心。当然这个贪心是显而易见的：我们要使总和尽可能小，就意味着要使每一位都尽可能小

~~显然这段话是废话~~

然后我们就要考虑如何求每一位最小的可能的值了

先从简单的情况开始，我们先来考虑什么样子的位最终的 `ans[i]` 能取到`1`。这样的位显而易见，有两种情况：

1. 左边和右边都比`ans[i]`大
2. 左边和右边都和`ans[i]`相等

第一种情况，显然不会有什么会要求`ans[i]`大于某一个值；而第二种情况，左右两边都不关心第`i`位是多少，那么他可以是任何可能的值。

然后我们考虑怎么填。

填进去比较复杂。一个很自然的情况是从左往右扫然后只考虑前一位的影响，但是显然不行：因为最后一位会出现问题。

那么我们考虑简化这个问题。我们考虑为什么刚才的做法不对：因为在那种做法里我们只考虑了一边的情况，而事实上我们应该考虑两边。但是考虑两边是很麻烦的，前前后后会有很多麻烦需要处理。所以我们考虑尝试着改变填入的顺序，使得我们可以合理的忽略一部分的约束。这种做法不难想到（~~虽然我自己一开始也没想到~~）：按照值的大小，从小到大填。

为什么可以呢？我们先来回顾一下刚才是怎么确定哪几位是`1`的：看看这一位左右两边的数对这一位的影响。如果两边的数都大于等于它自己，那么这一位就可以是任意一个尽可能小的值，因为两边两位都不会要求这一位大于某个值。打个比方，样例中的`1 2 0`，`0`的两边分别是`1`和`2`，那么我就可以让`0`这一位填上`1`而不对别的位造成影响。

那么我们只要从小到大排序记录位置就好了。

当然并没有这么简单。我们还得要考虑左右两边相等的情况。如果两边都相等，显然我可以是；如果只有一边相等，那么就考虑不相等的那一边即可。这样的话，结论就呼之欲出了：



```cpp
def pos(i):
    return (i % n+n) % n


n = int(input())
a = [int(x) for x in input().split()]
ans = [0 for i in range(n)]
p = sorted([(a[i], i) for i in range(n)])

for i in range(n):
    if a[pos(p[i][1]-1)] == a[p[i][1]] and a[pos(p[i][1]+1)] == a[p[i][1]]:
        ans[p[i][1]] = 1
    elif a[pos(p[i][1]-1)] == a[p[i][1]]:
        ans[p[i][1]] = ans[pos(p[i][1]+1)]+1
    elif a[pos(p[i][1]+1)] == a[p[i][1]]:
        ans[p[i][1]] = ans[pos(p[i][1]-1)]+1
    else:
        ans[p[i][1]] = max(ans[pos(p[i][1]-1)], ans[pos(p[i][1]+1)])+1

s = sum(ans)
print(s)

```

~~以下是拓扑排序的半个伪做法~~

```python
import queue


def pos(i):
    # 一个辅助函数 求第i个元素在环里面的位置
    # 比如说第0位 前一位是n-1 第n-1位后一位是0
    # 这样可以简化编码
    return (i % n+n) % n


n = int(input())
a = [int(x) for x in input().split()]
q = queue.Queue()

# ans记录最终每一个点上面的值
ans = [0 for i in range(n)]
# vis记录有没有进过队列
vis = dict.fromkeys(range(n), False)

for i in range(n):
    if a[pos(i-1)] >= a[i] and a[i] <= a[pos(i+1)]:
        q.put(i)
        ans[i] = 1

while not q.empty():
    p = q.get()
    vis[p] = True
    if a[pos(p-1)] > a[p]:
        if a[pos(p-2)] >= a[pos(p-1)] or vis[pos(p-2)]:
            if not vis[pos(p-1)]:
                q.put(pos(p-1))
                ans[pos(p-1)] = ans[p]+1
    if a[pos(p+1)] > a[p]:
        if a[pos(p+2)] >= a[pos(p+1)] or vis[pos(p+2)]:
            if not vis[pos(p+1)]:
                q.put(pos(p+1))
                ans[pos(p+1)] = ans[p]+1

s = sum(ans)

print(s)

```
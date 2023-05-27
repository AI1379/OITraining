import queue


def pos(i):
    return (i % n+n) % n


n = int(input())
a = [int(x) for x in input().split()]
q = queue.Queue()
ans = [0 for i in range(n)]
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

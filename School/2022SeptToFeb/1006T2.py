t = int(input())
n = 0
q = []
for i in range(t):
    q.append(int(input()))
n = max(q) + 50
vis = dict.fromkeys(range(n+10), False)
pri = []

for i in range(2, n):
    if vis[i] == False:
        pri.append(i)
    for j in pri:
        if i * j >= n:
            break
        vis[i*j] = True
        if i % j == 0:
            break


def query(x):
    l = 0
    r = len(pri)
    ans = 0
    while l <= r:
        mid = (l+r)//2
        if pri[mid] > x:
            r = mid-1
        else:
            ans = mid
            l = mid+1
    if x-pri[ans] >= pri[ans+1]-x:
        return pri[ans+1]
    else:
        return pri[ans]


for i in q:
    print(query(i))

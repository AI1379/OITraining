n = int(input())
v = [int(x) for x in input().split()]
f = [0]*n
d = [0x3fffffff]*(n+1)
d[1] = 0


def find(x: int):
    l = 1
    r = n
    ans = -1
    while l <= r:
        mid = (l+r)//2
        if d[mid] < x:
            ans = mid
            l = mid+1
        else:
            r = mid-1
    return ans


for i in range(n):
    f[i] = find(v[i])
    d[f[i]+1] = v[i]

print(max(f))

n, m = map(int, input().split())
val = [int(x) for x in input().split()]


def check(x: int):
    tmp = 0
    p = 0
    for i in val:
        if i-tmp < x:
            p += 1
        else:
            tmp = i
    return p <= m


l = 1
r = val[n]
ans = 0
while l <= r:
    mid = (l+r)//2
    if check(mid):
        ans = mid
        l = mid + 1
    else:
        r = mid - 1

print(ans)

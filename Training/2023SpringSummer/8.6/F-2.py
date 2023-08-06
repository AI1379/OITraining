n, q = map(int, input().split())
lis = []
for _ in range(n):
    lis = lis + [int(x) for x in input().split()]

lis = sorted(lis)


def lowerbound(x):
    l, r = 0, len(lis) - 1
    mid, res = 0, len(lis)
    while l <= r:
        mid = (l + r) // 2
        if lis[mid] < x:
            l = mid + 1
        else:
            res = mid
            r = mid - 1
    return res


for _ in range(q):
    v = int(input())
    print(min(n, len(lis) - lowerbound(v)))

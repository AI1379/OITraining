n, x = map(int, input().split())
lis = [0] + [int(t) for t in input().split()]
s = 0
for i in range(1, n + 1):
    if lis[i] + lis[i - 1] > x:
        s += lis[i] + lis[i - 1] - x
        lis[i] = x - lis[i - 1]
print(s)

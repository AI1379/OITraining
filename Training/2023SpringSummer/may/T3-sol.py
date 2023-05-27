n = int(input())
h = [0] + sorted([int(x) for x in input().split()])
p, q = n, 0
ans = 0
while q < p:
    ans += (h[q]-h[p])**2
    q += 1
    ans += (h[q]-h[p])**2
    p -= 1

print(ans)

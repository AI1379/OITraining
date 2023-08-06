n, t = map(int, input().split())
lis = [[0, 0, 0] for _ in range(n)]
for i in range(n):
    lis[i][0], lis[i][1] = map(int, input().split())
    lis[i][2] = lis[i][1] / lis[i][0]
lis.sort(key=lambda x: x[2], reverse=True)
ans = 0
idx = 0
while t > 0:
    ans += lis[idx][2] * min(t, lis[idx][0])
    t -= min(t, lis[idx][0])
    idx += 1
print("%.2f" % ans)

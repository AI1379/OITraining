n, m = [int(x) for x in input().split()]
ans = 0
for i in range(0, n):
    try:
        int(input(), base=m)
        ans += 1
    except:
        pass
print(ans)

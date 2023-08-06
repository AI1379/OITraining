eps = 0.0001
n, m, k = map(int, input().split())


l, r = 0, 5
while r - l > eps:
    mid = (l + r) / 2
    if (1 / (1 + mid)) ** k < (1 - n / m * mid):
        l = mid
    else:
        r = mid
print("%.1f" % (l * 100))

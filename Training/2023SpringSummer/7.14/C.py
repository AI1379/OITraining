n, c = map(int, input().split())
s = sorted([int(x) for x in input().split()])


def find1(p, x):
    l = p + 1
    r = len(s) - 1
    ans = len(s)
    while l <= r:
        mid = (l + r) // 2
        if s[mid] >= x:
            ans = mid
            r = mid - 1
        else:
            l = mid + 1
    return ans


def find2(p, x):
    l = p + 1
    r = len(s) - 1
    ans = len(s)
    while l <= r:
        mid = (l + r) // 2
        if s[mid] > x:
            ans = mid
            r = mid - 1
        else:
            l = mid + 1
    return ans


# print(s)
ans = 0
for i in range(len(s)):
    # print(i, s[i], s[i] + c, find1(i, s[i] + c), find2(i, s[i] + c))
    ans += find2(i, s[i] + c) - find1(i, s[i] + c)

print(ans)

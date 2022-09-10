n, m = [int(x) for x in input().split()]
ans = 0
lst = []
for i in range(0, m):
    lst.append(chr(i+ord('0')))
if m > 10:
    for i in range(0, m-10):
        lst.append(chr(i+ord('A')))
for i in range(0, n):
    p = input()
    flag = True
    for j in p:
        if j == '\r':
            break
        if lst.count(j) == 0:
            flag = False
            break
    if flag:
        ans += 1
print(ans)

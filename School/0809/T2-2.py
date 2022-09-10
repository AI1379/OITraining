ans = 0
a = input().split()
n = int(a[0])
m = int(a[1])
lst = []

if m <= 10:
    for i in range(0, m):
        lst.append(chr(i + ord('0')))
else:
    for i in range(0, 10):
        lst.append(chr(i + ord('0')))
    for i in range(0, m - 10):
        lst.append(chr(i + ord('A')))

for i in range(0, n):
    flag = True
    p = input()
    if len(p) < 1:
        flag = False
    for j in p:
        if flag == False:
            break
        if lst.count(j) == 0:
            flag = False
            break
    if flag == True:
        ans += 1

print(ans)

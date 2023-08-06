x = input()
a = []
for i in range(4):
    a.append([int(x) for x in input().split()])
ans = 0
for i in a:
    ans1 = 0
    if len(i) <= 2:
        ans += max(i)
        continue
    i.sort(reverse=True)
    q1 = i[0]
    q2 = i[1]
    for j in range(2, len(i)):
        if q1 > q2:
            q2 += i[j]
        else:
            q1 += i[j]
    print(q1, q2)
    ans += max(q1, q2)
print(ans)

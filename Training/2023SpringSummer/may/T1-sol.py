n = int(input())
ans = []
flag = False
for i in range(n):
    m = int(input())
    flag = False
    for j in range(m):
        s = input()
        if s.lower().find("liyue") != -1:
            ans.append(s)
            flag = True
    if not flag:
        ans.append("Time to play Genius Invokation TCG!")
for s in ans:
    print(s)

p, s = input(), input()
ans = 0
for i in range(len(p) - 1):
    for j in range(1, len(s)):
        if p[i] == s[j] and p[i + 1] == s[j - 1]:
            ans += 1
print(2**ans)

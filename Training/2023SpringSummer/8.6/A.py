s, t = input(), input()
a, b = 1, 1
for i in s:
    a = a * (ord(i) - ord("A") + 1) % 47
for i in t:
    b = b * (ord(i) - ord("A") + 1) % 47
if a == b:
    print("GO")
else:
    print("STAY")

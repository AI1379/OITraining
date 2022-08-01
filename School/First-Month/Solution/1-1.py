import random
n = int(input())
lst = []
for i in range(n):
	lst.append(random.randint(1,100))
avg = sum(lst)/n
print(avg)
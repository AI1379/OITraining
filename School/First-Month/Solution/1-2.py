def isPrime(x):
	div = 2
	while div*div <= x:
		if x%div == 0:
			return False
		div+=1
	return True

n = int(input())
ans = 0
for i in range(5,n,2):
	if isPrime(i-2) and isPrime(i):
		ans+=1
print(ans)
N, K = map(int, input().split())
coins = []

for i in range(N) :
	coins.append(int(input()))

coins.sort(reverse = True)

cnt = 0

for i in range(N) :
	if K >= coins[i] :
		cnt += K // coins[i]
		K %= coins[i]

print(cnt)


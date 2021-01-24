N, K = map(int, input().split())
coins = [0 for _ in range(N)]

for i in range(N) :
	coins[N - i - 1] = (int(input()))

cnt = 0

for i in range(N) :
	if K >= coins[i] :
		cnt += K // coins[i]
		K %= coins[i]

print(cnt)


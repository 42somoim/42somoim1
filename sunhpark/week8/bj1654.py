# bj1654 랜선 자르기

K, N = map(int, input().split())

lan = []

for i in range(K) :
    lan.append(int(input()))

h = sum(lan) // N
l = 1

while l <= h :
    mid = (h + l) // 2
    cnt = sum([x // mid for x in lan])
    if cnt < N :
        h = mid - 1
    elif cnt >= N :
        l = mid + 1
        ans = mid
print(ans)

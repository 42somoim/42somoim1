#bj2110 공유기설치

N, C = map(int, input().split())
house = []
for i in range(N) :
    house.append(int(input()))

house.sort()

l = house[1] - house[0]
r = house[-1] - house[0]

ans = 0

while l <= r :
    mid = (l + r) // 2
    val = house[0]
    cnt = 1

    for i in range(1, len(house)) :
        if house[i] >= val + mid :
            cnt += 1
            val = house[i]

    if cnt >= C :
        l = mid + 1
        ans = mid
    else :
        r = mid - 1

print(ans)

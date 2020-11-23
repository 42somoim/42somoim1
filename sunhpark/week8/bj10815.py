# bj 10815 number card

N = int(input())
card = list(map(int, input().split()))

M = int(input())
nums = list(map(int, input().split()))

cnt = {}

for i in card :
    try :
        cnt[i] += 1
    except :
        cnt[i] = 1

ans = []
for i in nums :
    try :
        ans.append(cnt[i])
    except :
        ans.append(0)

for i in ans :
    print(i, end = ' ')

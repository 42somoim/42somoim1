N = int(input())
room = []

for i in range(N) :
	room.append(list(map(int, input().split())))

room.sort(key = lambda x:x[0])
room.sort(key = lambda x:x[1])

start = room[0][0]
end = room[0][1]
cnt = 1

for i in range(N - 1) :
	if room[i + 1][0] >= end :
		end = room[i + 1][1]
		cnt += 1

print(cnt)

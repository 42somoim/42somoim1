#bj 2667 단지번호 붙이기

def dfs(x, y, cnt, house) :
    visited[x][y] = 1
    dx = [0, 0, 1, -1]
    dy = [-1, 1, 0, 0]
    for i in range(4) :
        nx = x + dx[i]
        ny = y + dy[i]
        if (0 <= nx < N) and (0 <= ny < N) and house[nx][ny] == 1 and visited[nx][ny] == 0 :
            cnt = dfs(nx, ny, cnt + 1, house)
    return cnt
         

N = int(input())

house = []
visited = [[0 for j in range(N)] for i in range(N)]
cnt = []

for i in range(N) :
    house.append(list(map(int, input())))

for i in range(N) :
    for j in range(N) :
        if house[i][j] == 1 and visited[i][j] == 0:
            cnt.append(dfs(i, j, 1, house))

print(len(cnt))
for i in sorted(cnt) :
    print(i)

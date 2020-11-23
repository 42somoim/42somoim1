#bj 2178번 미로탐색

from collections import deque

def bfs(N, M, maze) :
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    
    q = deque()
    q.append([0,0])
    visited[0][0] = 1
    dist[0][0] = 1
    
    while q :
        x, y  = q.popleft()
        for i in range(4) :
            nx = x + dx[i]
            ny = y + dy[i]
            if (0 <= nx < N) and (0 <= ny < M) :
                if (visited[nx][ny] == 0) and maze[nx][ny] == 1 :
                    q.append([nx, ny])
                    dist[nx][ny] = dist[x][y] + 1
                    visited[nx][ny] = 1

N, M = map(int, input().split())

maze = []
visited = [[0] * M for i in range(N)]
dist = [[0] * M for i in range(N)]

for i in range(N) :
    maze.append(list(map(int, input())))

bfs(N, M, maze)

print(dist[N-1][M-1])

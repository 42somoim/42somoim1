dx = [1, -1, 0, 0, 1, -1, 1, -1]
dy = [0, 0, -1, 1, -1, -1, 1, 1]

def bfs(i, j) :
    array[i][j] = 0
    queue = [[i, j]]
    while queue :
        a, b = queue[0][0], queue[0][1]
        del queue[0]
        for k in range(8) :
            x = a + dx[k]
            y = b + dy[k]
            if 0 <= x < H and 0 <= y < W and array[x][y] == 1 :
                array[x][y] = 0
                queue.append([x, y])

while True :
    W, H = map(int, input().split())
    if W == 0 and H == 0 :
        break
    array = []
    cnt = 0
    for i in range(H) :
        array.append(list(map(int, input().split())))
    for i in range(H) :
        for j in range(W) :
            if array[i][j] == 1 :
                bfs(i, j)
                cnt += 1
    print(cnt)

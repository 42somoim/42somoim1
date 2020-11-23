#include <iostream>
#include <queue>

using namespace std;

int n;
int board[2001][2001];
bool visited[2010*2010];
vector<int> graph[2010*2010];

/* 
 * 일단 그래프를
 * board에다 다 그려버리자.
 * */

void    bfs(int x, int y)
{
    queue<int> qx;
    queue<int> qy;

    qx.push(x); qy.push(y);
    board[y][x] = 0;
    while (!qx.empty()) {
        x = qx.front(); qx.pop();
        y = qy.front(); qy.pop();
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx <= 2000 && 0 <= ny && ny <= 2000
                    && board[ny][nx] != 0) {
                board[ny][nx] = 0;
                qx.push(nx); qy.push(ny);
            }
        }
    }
}

int     main(void)
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 500; x1 *= 2;
        y1 += 500; y1 *= 2;
        x2 += 500; x2 *= 2;
        y2 += 500; y2 *= 2; 
        for (int x = x1; x <= x2; x++) {
            board[y2][x] = board[y1][x] = i;
        }
        for (int y = y1; y <= y2; y++) {
            board[y][x1] = board[y][x2] = i;
        }
    }

    int ans = 0;
    if (board[1000][1000] != 0)
        ans--;

    for (int y = 0; y <= 2000; y++) {
        for (int x = 0; x <= 2000; x++) {
            if (board[y][x] != 0) {
                bfs(x, y);
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}

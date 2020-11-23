#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int N, M, K;
string map[101];
int d[101][101][101];
string to_find;

int		solve(int x, int y, int i) {
    if (i + 1 == to_find.length())
        return d[y][x][i] = 1;
    else if (d[y][x][i] != -1)
        return d[y][x][i];

    d[y][x][i] = 0;
    /* y-axis */
    for (int dy = -K; dy <= K; dy++) {
        if (dy == 0)
            continue;
        int nx = x;
        int ny = y + dy;
        if (0 <= nx && nx < M && 0 <= ny && ny < N) {
            /* next char matches find */
            if (map[ny][nx] == to_find[i + 1]) {
                d[y][x][i] += solve(nx, ny, i + 1);
            }
        }
    }
    /* x-axis */
    for (int dx = -K; dx <= K; dx++) {
        if (dx == 0)
            continue;
        int nx = x + dx;
        int ny = y;
        if (0 <= nx && nx < M && 0 <= ny && ny < N) {
            /* next char matches find */
            if (map[ny][nx] == to_find[i + 1]) {
                d[y][x][i] += solve(nx, ny, i + 1);
            }
        }
    }
	return d[y][x][i];
}

int		main(void)
{
    memset(d, -1, sizeof(d));
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	cin >> to_find;


	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (to_find[0] == map[i][j]) {
				int num = solve(j, i, 0);
				ans += num;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

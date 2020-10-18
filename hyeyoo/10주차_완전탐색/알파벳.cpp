#include <iostream>
#include <algorithm>

using namespace std;

string board[200];
bool visited[1000];
int ans = 0;
int R, C;

void	solve(int x, int y, int depth) {
	ans = max(depth, ans);
	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, -1, 1};
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < C && 0 <= ny && ny < R) {
			if (!visited[board[ny][nx]]) {
				visited[board[ny][nx]] = true;
				solve(nx, ny, depth + 1);
				visited[board[ny][nx]] = false;
			}
		}
	}
}

int		main(void)
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		cin >> board[i];
	visited[board[0][0]] = true;
	solve(0, 0, 1);
	cout << ans << endl;
	return 0;
}

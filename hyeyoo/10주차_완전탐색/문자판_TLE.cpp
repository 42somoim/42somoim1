#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N, M, K;
string map[101];
string to_find;

struct s {
	public:
		string	str;
		int		x;
		int		y;
		s(string str, int x, int y) {
			this->str = str;
			this->x = x;
			this->y = y;
		}
};

int		solve(int start_x, int start_y) {
	queue<s> q;
	q.push(s(string(), start_x, start_y));
	q.front().str += map[start_y][start_x];

	int ans = 0;
	while (!q.empty()) {
		s u = q.front(); q.pop();
		if (u.str == to_find) {
			ans++;
			continue;
		}
		/* y-axis */
		for (int dy = -K; dy <= K; dy++) {
				int nx = u.x;
				int ny = u.y + dy;
				if (0 <= nx && nx < M && 0 <= ny && ny < N) {
					/* next char matches find */
					if (map[ny][nx] == to_find[u.str.size()]) {
						s v = s(u.str, nx, ny);
						v.str += map[ny][nx];
						q.push(v);
					}
				}
		}
		/* x-axis */
		for (int dx = -K; dx <= K; dx++) {
				int nx = u.x + dx;
				int ny = u.y;
				if (0 <= nx && nx < M && 0 <= ny && ny < N) {
					/* next char matches find */
					if (map[ny][nx] == to_find[u.str.size()]) {
						s v = s(u.str, nx, ny);
						v.str += map[ny][nx];
						q.push(v);
					}
				}
		}
	}
	return ans;
}

int		main(void)
{
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	cin >> to_find;

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (to_find[0] == map[i][j]) {
				int num = solve(j, i);
				ans += num;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

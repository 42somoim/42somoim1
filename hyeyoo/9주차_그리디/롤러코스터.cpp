#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void	repeat(string & s, char c, int len)
{
	for (int i = 0; i < len; i++)
		s.push_back(c);
}

int		main(void)
{
	int R, C;
	int **map;
	string ans;
	cin >> R >> C;

	map = new int*[R];
	for (int i = 0; i < R; i++) {
		map[i] = new int[C];
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	if (R % 2 == 1) {
		for (int i = 0; i < R; i++) {
			if (i % 2 == 0) {
				repeat(ans, 'R', C - 1);
				if (i != R - 1)
					repeat(ans, 'D', 1);
			} else {
				repeat(ans, 'L', C - 1);
				repeat(ans, 'D', 1);
			}
		}
	} else if (C % 2 == 1) {
		for (int i = 0; i < C; i++) {
			if (i % 2 == 0) {
				repeat(ans, 'D', R - 1);
				if (i != C - 1)
					repeat(ans, 'R', 1);
			} else {
				repeat(ans, 'U', R - 1);
				repeat(ans, 'R', 1);
			}
		}
	} else {
		string rev_ans;
		int min_x = 0;
		int min_y = 1;
		for (int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) {
				if ((i + j) % 2 == 1) {
					if (map[i][j] < map[min_x][min_y]) {
						min_y = j;
						min_x = i;
					}
				}
			}
		}

		int x1 = 0, y1 = 0;
		int x2 = R - 1, y2 = C - 1;

		while (x2 - x1 > 1) {
			if (x1 / 2 < min_x / 2) {
				repeat(ans, 'R', C - 1);
				repeat(ans, 'D', 1);
				repeat(ans, 'L', C - 1);
				repeat(ans, 'D', 1);
				x1 += 2;
			}
			if (min_x / 2 < x2 / 2) {
				repeat(rev_ans, 'R', C - 1);
				repeat(rev_ans, 'D', 1);
				repeat(rev_ans, 'L', C - 1);
				repeat(rev_ans, 'D', 1);
				x2 -= 2;
			}
		}

		while (y2 - y1 > 1) {
			if (y1 / 2 < min_y / 2) {
				repeat(ans, 'D', 1);
				repeat(ans, 'R', 1);
				repeat(ans, 'U', 1);
				repeat(ans, 'R', 1);
				y1 += 2;
			}
			if (min_y / 2 < y2 / 2) {
				repeat(rev_ans, 'D', 1);
				repeat(rev_ans, 'R', 1);
				repeat(rev_ans, 'U', 1);
				repeat(rev_ans, 'R', 1);
				y2 -= 2;
			}
		}

		if (min_y == y1) {
			repeat(ans, 'R', 1);
			repeat(ans, 'D', 1);
		} else {
			repeat(ans, 'D', 1);
			repeat(ans, 'R', 1);
		}
		reverse(rev_ans.begin(), rev_ans.end());
		ans += rev_ans;
	}

	cout << ans << endl;
	return 0;
}

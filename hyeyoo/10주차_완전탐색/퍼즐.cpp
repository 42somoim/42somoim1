#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
int ans = 10000000;
map<int, bool> visited;

class Puzzle {
	public:
		int move;
		int x, y;
		int arr[3][3];
		Puzzle() {
			x = 0;
			y = 0;
			move = 0;
		}
		Puzzle(Puzzle const& p) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					arr[i][j] = p.arr[i][j];
					if (arr[i][j] == 9) {
						y = i;
						x = j;
					}
				}
			}
			move = p.move;
		}

		Puzzle &operator=(Puzzle const& p) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					arr[i][j] = p.arr[i][j];
					if (arr[i][j] == 9) {
						y = i;
						x = j;
					}
				}
			}
			move = p.move;
			return *this;
		}
};

int		get_id(int mat[3][3]) {
	int id = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			id = id * 10 + mat[i][j];
		}
	}
	return id;
}

void	swap(int& x, int& y) {
	int tmp = x;
	x = y;
	y = tmp;
}

bool	is_sorted(int puzzle[3][3]) {
	int before = puzzle[0][0];
	for (int i = 1; i < 9; i++) {
		if (before > puzzle[i / 3][i % 3] && puzzle[i / 3][i % 3] != 0) {
			return false;
		}
		before = puzzle[i / 3][i % 3];
	}
	return true;
}

/*
   x, y : coord of 0
*/
int		solve(Puzzle p) {
	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, 1, -1};

	queue<Puzzle> q;
	q.push(p);
	int id = get_id(p.arr);
	visited[id] = true;

	while (!q.empty()) {
		p = q.front(); q.pop();
		if (is_sorted(p.arr)) {
			return p.move;
		}
		for (int i = 0; i < 4; i++) {
			int nx = p.x + dx[i];
			int ny = p.y + dy[i];
			if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) {
				Puzzle next(p);
				swap(next.arr[ny][nx], next.arr[p.y][p.x]);
				next.y = ny;
				next.x = nx;
				next.move = p.move + 1;
				int nid = get_id(next.arr);
				/* not visited */
				if (visited.find(nid) == visited.end()) {
					q.push(next);
					visited[get_id(next.arr)] = true;
				}
			}
		}
	}
	return -1;
}

int		main(void)
{
	Puzzle p;
	int x = 0, y = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> p.arr[i][j];
			if (p.arr[i][j] == 0) {
				p.y = i;
				p.x = j;
				p.arr[i][j] = 9;
			}
		}
	}
	p.move = 0;

	cout << solve(p) << endl;
	return 0;
}

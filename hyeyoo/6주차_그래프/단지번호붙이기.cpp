#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <list>

using namespace std;

map<int, vector<int> > graph;
bool **visited;
string *maps;
int n;

int		bfs(int x, int y)
{
	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};
	int ret = 0;
	queue<int> qx;
	queue<int> qy;

	qx.push(x);
	qy.push(y);
	visited[y][x] = true;

	while (!qx.empty() && !qy.empty()) {
		ret++;
		int ux = qx.front();
		int uy = qy.front();
		qx.pop();
		qy.pop();

		for(int i = 0; i < 4; i++) {
			int nx = ux + dx[i];
			int ny = uy + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n
					&& maps[ny][nx] == '1' && !visited[ny][nx]) {
				qx.push(nx);
				qy.push(ny);
				visited[ny][nx] = true;
			}
		}
	}
	return ret;
}
int		main(void)
{
	cin >> n;

	visited = new bool*[n];
	maps = new string[n];
	for (int i = 0; i < n; i++) {
		visited[i] = new bool[n];
		fill_n(visited[i], false, n);
		cin >> maps[i];
	}

	list<int> residents;
	for (int y = 0; y < n; y++) {
		for(int x = 0; x < n; x++) {
			if (!visited[y][x] && maps[y][x] == '1') {
				int num = bfs(x, y);
				residents.push_back(num);
			}
		}
	}
	cout << residents.size() << endl;
	residents.sort();
	while (!residents.empty()) {
		cout << residents.front() << endl;
		residents.pop_front();
	}
}

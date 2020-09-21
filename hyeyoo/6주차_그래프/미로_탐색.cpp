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
int h, w;

int		bfs(int x, int y)
{
	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};
	int ret = 0;
	queue<int> qx;
	queue<int> qy;
	queue<int> qdist;
	qx.push(x);
	qy.push(y);
	qdist.push(1);
	visited[y][x] = true;

	while (!qx.empty() && !qy.empty()) {
		ret++;
		int ux = qx.front();
		int uy = qy.front();
		int udist = qdist.front();
		qx.pop();
		qy.pop();
		qdist.pop();

		if (ux == w - 1 && uy == h - 1)
			return udist;

		for(int i = 0; i < 4; i++) {
			int nx = ux + dx[i];
			int ny = uy + dy[i];
			int ndist = udist + 1;
			if (0 <= nx && nx < w && 0 <= ny && ny < h
					&& maps[ny][nx] == '1' && !visited[ny][nx]) {
				qx.push(nx);
				qy.push(ny);
				qdist.push(ndist);
				visited[ny][nx] = true;
			}
		}
	}
	return 0;
}
int		main(void)
{
	cin >> h >> w;

	visited = new bool*[h];
	maps = new string[h];
	for (int i = 0; i < h; i++) {
		visited[i] = new bool[w];
		fill_n(visited[i], false, w);
		cin >> maps[i];
	}
	cout << bfs(0, 0) << endl;
}

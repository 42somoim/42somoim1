#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <list>

using namespace std;

bool **visited;
int **maps;
int w, h;

void bfs(int x, int y)
{
	int dx[] = {0,1,0,-1,1,1,-1,-1};
	int dy[] = {-1,0,1,0,1,-1,1,-1};
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

		for(int i = 0; i < 8; i++) {
			int nx = ux + dx[i];
			int ny = uy + dy[i];
			if (0 <= nx && nx < w && 0 <= ny && ny < h
					&& maps[ny][nx] == 1 && !visited[ny][nx]) {
				qx.push(nx);
				qy.push(ny);
				visited[ny][nx] = true;
			}
		}
	}
}
int		main(void)
{
	cin >> w >> h;
	while (!(w == 0 && h == 0)) {
		visited = new bool*[h];
		maps = new int*[h];
		for (int i = 0; i < h; i++) {
			visited[i] = new bool[w];
			maps[i] = new int[w];
			for (int x = 0; x < w; x++) {
				cin >> maps[i][x];
				visited[i][x] = false;
			}
		}

		int ans = 0;
		for (int y = 0; y < h; y++) {
			for(int x = 0; x < w; x++) {
				if (!visited[y][x] && maps[y][x] == 1) {
					bfs(x, y);
					ans++;
				}
			}
		}
		cout << ans << endl;
		for(int y = 0; y < h; y++) {
			delete[] visited[y];
			delete[] maps[y];
		}
		delete[] visited;
		delete[] maps;
		cin >> w >> h;	
	}
}

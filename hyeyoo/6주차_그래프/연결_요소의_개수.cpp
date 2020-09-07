#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int n = 0, m = 0;
map<int, vector<int> > graph;
bool *visited;

void	bfs(int u)
{
	queue<int> q;
	q.push(u);
	visited[u] = true;

	while (!q.empty())
	{
		u = q.front();
		q.pop();
		for(int i = 0; i < graph[u].size(); i++) {
			int v = graph[u][i];
			if (!visited[v]) {
				visited[v] = true;
				q.push(v);
			}
		}
	}
}

int		main(void)
{
	cin >> n >> m;
	visited = new bool[n + 1];
	while (m--) {
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	int ans = 0;
	fill_n(visited, n + 1, false);
	for(int i = 1; i <= n; i++) {
		if (!visited[i]) {
			bfs(i);
			ans++;
		}
	}
	cout << ans;
}

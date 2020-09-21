#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int n = 0, m = 0, v = 0;
map<int, vector<int> > graph;

void	dfs(int u, bool *visited) {
	visited[u] = true;
	cout << u << " ";
	for(int i = 0; i < graph[u].size(); i++) {
		int v = graph[u][i];
		if (!visited[v]) {
			dfs(v, visited);
		}
	}
}

void	bfs(int start) {
	queue<int> q;
	bool visited[n + 1];

	fill_n(visited, n + 1, false);
	visited[start] = true;
	q.push(start);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		cout << u << " ";
		for(int i = 0; i < graph[u].size(); i++) {
			int v = graph[u][i];
			if (!visited[v]) {
				q.push(v);
				visited[v] = true;
			}
		}
	}
	cout << endl;
}

int		main(void)
{
	cin >> n >> m >> v;
	while (m--) {
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	for(int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end());
	bool visited[n + 1];
	fill_n(visited, n + 1, false);
	dfs(v, visited);
	cout << endl;
	bfs(v);
}

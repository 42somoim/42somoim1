#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int NONE = 0;
const int WHITE = 1;
const int BLACK = 2;

bool is_bipartite(map<int, vector<int> > graph, int v)
{
	int color[v + 1];
	queue<int> q;
	
	fill_n(color, v + 1, NONE);
	q.push(1);
	color[1] = WHITE;

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = 0; i < graph[u].size(); i++) {
			int w = graph[u][i];
			if (color[w] == NONE) {
				color[w] = (color[u] == WHITE) ? BLACK : WHITE;
				q.push(w);
			} else if (color[w] == color[u]) {
				return false;
			}
		}
	}
	return true;
}

int		main(void)
{
	int t;
	cin >> t;
	while (t--) {
		int v, e;
		cin >> v >> e;
		map<int, vector<int> > graph;
		
		while(e--) {
			int s, e;
			cin >> s >> e;
			graph[s].push_back(e);
			graph[e].push_back(s);
		}
		cout << (is_bipartite(graph, v) ? "YES" : "NO") << endl;
	}
}

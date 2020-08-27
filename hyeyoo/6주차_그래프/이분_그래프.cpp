#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int NONE = 0;
const int WHITE = 1;
const int BLACK = 2;
int *color;

bool is_bipartite(int start, map<int, vector<int> > graph, int v)
{
	queue<int> q;	
	q.push(start);
	color[start] = WHITE;

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
		color = new int[v + 1];
		fill_n(color, v + 1, NONE);

		while(e--) {
			int s, e;
			cin >> s >> e;
			graph[s].push_back(e);
			graph[e].push_back(s);
		}

		bool is_yes = true;
		for(int i = 1; i <= v; i++) {
			if (color[i])
				continue;
			if (!is_bipartite(i, graph, v)) {
				is_yes = false;
				break;
			}
		}
		cout << (is_yes ? "YES" : "NO") << endl;
		delete[] color;
	}
}

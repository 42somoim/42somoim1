#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int start, vector<int> graph[], bool check[])
{
	check[start] = true;

	for (int i = 0; i < graph[start].size(); i++)
	{
		int next = graph[start][i];
		if (check[next] == false)
		{
			dfs(next, graph, check);
		}
	}
}

int main() 
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, com = 0;
	cin >> n >> m;

	vector<int>* graph = new vector<int>[n + 1];

	bool check[1001] = { false };

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	for (int i = 1; i <= n; i++)
	{
		if (check[i] == false)
		{
			dfs(i, graph, check);
			com += 1;
		}
	}
	cout << com <<"\n";

	return 0;
}



#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int node[100001];

void dfs(int start, vector<int> graph[], bool check[])
{
	check[start] = true;
	for (int i = 0; i < graph[start].size(); i++)
	{
		int next = graph[start][i];
		if (check[next] == false)
		{
			node[graph[start][i]] = start;
			dfs(next, graph, check);
		}
	}
}

int main() {

	int n;
	cin >> n;

	vector<int>* graph = new vector<int>[n + 1];

	bool check[100001] = { false };

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}


	dfs(1, graph, check);
	for (int i = 2; i <= n; i++)
	{
		cout << node[i] << "\n";
	}
	return 0;
}



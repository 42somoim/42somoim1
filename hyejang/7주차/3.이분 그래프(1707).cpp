#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int test[20001];
bool done = false;

void dfs(int start, vector<int> graph[], bool check[])
{
	check[start] = true;

	for (int i = 0; i < graph[start].size(); i++)
	{
		int next = graph[start][i];
		if (check[next] == false)
		{
			test[next] = test[start] == 1 ? 2 : 1;
			dfs(next, graph, check);
		}
		if (test[next] == test[start] && done == false)
		{
			done = true;
		}
	}
}

int main() 
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int k, v, e, com = 0;
	cin >> k;
	
	for (int i = 0; i < k; i++)
	{
		cin >> v >> e;

		vector<int>* graph = new vector<int>[v + 1];

		bool check[20001] = { false };
		done = false;

		for (int i = 0; i < e; i++)
		{
			int u, v;
			cin >> u >> v;

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		for (int i = 1; i <= v; i++)
		{
			sort(graph[i].begin(), graph[i].end());
		}
		fill(test, test + v + 1, 0);

		for (int i = 1; i <= v; i++)
		{
			if (check[i] == false)
			{
				test[i] = 1;
				dfs(i, graph, check);
			}
		}
		if (done == false)
		{
			cout << "YES" << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}
	}
	return 0;
}



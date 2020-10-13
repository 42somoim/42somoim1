#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define MAX 1001

int			N, M;
vector<int>	G[MAX];
bool		visited[MAX];

void		dfs(int v)
{
	visited[v] = true;
	for (int i = 0; i < G[v].size(); i++)
	{
		int	next = G[v][i];
		if (!visited[next])
		{
			dfs(next);
		}
	}
}

int			main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}

	int		cnt = 0;
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			cnt++;
			dfs(i);
		}
	}
	cout << cnt << '\n';
	return (0);
}


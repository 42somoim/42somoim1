#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int			N, M, V;
int			map[1001][1001];
int			visited[1001];
queue<int>	q;

void		dfs(int v)
{
	cout << v << " ";
	// 체크인
	visited[v] = 1;
	for (int i = 1; i <= N; i++)
	{
		// 갈 수 있는가?
		if (map[v][i] && !visited[i])
		{
			// 간다!
			dfs(i);
		}
	}
}

void		bfs(int v)
{
	visited[v] = 1;
	q.push(v);

	while(!q.empty())
	{
		v = q.front();
		q.pop();

		cout << v << " ";
		for (int i = 1; i <= N; i++)
		{
			if (map[v][i] && !visited[i])
			{
				q.push(i);
				visited[i] = 1;
			}
		}
	}
}


int			main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> V;
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < M; i++)
	{
		int		x, y;
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}
	dfs(V);
	cout << "\n";

	memset(visited, 0, sizeof(visited));
	bfs(V);
	cout << "\n";
	return (0);
}



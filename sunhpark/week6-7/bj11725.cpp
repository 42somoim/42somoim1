#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX 100001

using namespace std;

int				parent[MAX];
vector<int> 	connect[MAX];
int				N;

int				bfs()
{
	queue<pair<int, int>> bfs_queue;
	for (int i = 0; i < connect[1].size(); i++)
	{
		bfs_queue.push({1, connect[1].at(i)});
	}
	while (bft_queue.size())
	{
		pair<int, int> sub_connect = bfs_queue.front();
		bfs_queue.pop();

		parent[sub_connect.second] = sub_connect.front();
		
		for (int i = 0; i < connect[sub_connect.second].size(); i++)
		{
			if (parent[connect[sub_connect.second].at(i)] == 0)
			{
				bfs_queue.push({sub_connect.second, connect[sub_connect.second].at(i)});
			}
		}
	}
}

int				main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int	x, y;
		cin >> x >> y;
		connect[x].push_back(y);
		connect[y].push_back(x);
	}

	parent[1] = -1;
	bfs();

	for (int i = 2; i <= N; i++)
	{
		cout << parent[i] << '\n';
	}

	return (0);
}

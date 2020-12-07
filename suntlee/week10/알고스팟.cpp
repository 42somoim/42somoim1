#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

const int MAX = 100;
typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int M, N;
string input[MAX];
bool visited[MAX][MAX];

int BFS(void)
{
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({ 0, {0, 0} });
	visited[0][0] = true;

	while (!pq.empty())
	{
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		int block = pq.top().first;

		pq.pop();
		if (y == N - 1 && x == M - 1)
				return block;

		for (int i = 0; i < 4; i++)
		{
			int nextY = y + moveDir[i].y;
			int nextX = x + moveDir[i].x;

			if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M)
			{
				if (!visited[nextY][nextX])
				{
					if (input[nextY][nextX] == '1')
						pq.push({ block + 1,{ nextY, nextX } });
					else
						pq.push({ block, {nextY, nextX} });
					visited[nextY][nextX] = true;
				}
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;
	for (int i = 0; i < N; i++)
		cin >> input[i];

	cout << BFS() << "\n";
	return 0;
}

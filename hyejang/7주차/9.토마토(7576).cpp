#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> 
#include <queue>

using namespace std;

int max_day = 0;
int width = 1, height = 1;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int, int>> q;

void bfs(int map[][1001])
{
	while (!q.empty())
	{
		pair<int, int> now = q.front();
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int x = now.first + dx[k];
			int y = now.second + dy[k];

			if (x >= 1 && x <= height && y >= 1 && y <= width)
			{
				if (map[now.first][now.second] > 0 && map[x][y] == 0)
				{
					map[x][y] = map[now.first][now.second] + 1;
					q.push(make_pair(x, y));
				}
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> width >> height;

	int box[1001][1001];

	//지형 입력
	for (int i = 1; i <= height; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			cin >> box[i][j];
			if (box[i][j] == 1)
			{
				q.push(make_pair(i, j));
			}
		}
	}

	bfs(box);

	for (int i = 1; i <= height; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			max_day = max(box[i][j], max_day);
			if (box[i][j] == 0)
			{
				cout << "-1" << "\n";
				return 0;
			}
		}
	}
	cout << max_day - 1 << "\n";

	return 0;
}
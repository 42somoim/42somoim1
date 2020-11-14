#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> 
#include <queue>

using namespace std;

int map_size = 1;
int land_count = 0;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int land_count_arr[102][102] = { 0 };

bool check[102][102] = { false };


void dfs(int x, int y, int size, int map[][102])
{
	check[x][y] = true;
	land_count_arr[x][y] = land_count;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && nx <= size && ny >= 1 && ny <= size)
		{
			if (check[nx][ny] == false && map[nx][ny] == 1)
			{
				dfs(nx, ny, map_size, map);
			}
		}
	}
}

int bfs(int map[][102], int start_land_num)
{
	queue<pair<int, int>> q;

	int leg = 0;

	for (int i = 1; i <= map_size; i++)
	{
		for (int j = 1; j <= map_size; j++)
		{
			check[i][j] = false;
			if (land_count_arr[i][j] == start_land_num)
			{
				q.push(make_pair(i, j));
			}
		}
	}

	while (!q.empty())
	{
		int curSize = q.size();

		for (int i = 0; i < curSize; i++)
		{
			pair<int, int> now = q.front();
			q.pop();

			for (int k = 0; k < 4; k++)
			{
				int x = now.first + dx[k];
				int y = now.second + dy[k];

				if (x >= 1 && x <= map_size && y >= 1 && y <= map_size)
				{
					if (land_count_arr[x][y] != start_land_num && map[x][y] != 0)
					{
						return leg;
					}
					else if (check[x][y] == false)
					{
						check[x][y] = true;
						q.push(make_pair(x, y));
					}
				}
			}
		}
		leg++;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int map[102][102];
	int min_value = 999999;

	cin >> map_size;

	//지형 입력
	for (int i = 1; i <= map_size; i++)
	{
		for (int j = 1; j <= map_size; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= map_size; i++)
	{
		for (int j = 1; j <= map_size; j++)
		{
			if (check[i][j] == false && map[i][j] == 1)
			{
				land_count++;
				dfs(i, j, map_size, map);
			}
		}
	}

	for (int i = 0; i < land_count; i++)
	{
		min_value = min(bfs(map, i + 1), min_value);
	}

	cout << min_value << "\n";

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> 
#include <queue>

using namespace std;

int max_day = 999999;
int width = 1, height = 1;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int current_Value = 0;

bool check[102][102] = { false };
queue<pair<int, int>> q;

void bfs(int map[][102])
{
	while (!q.empty())
	{
		pair<int, int> now = q.front();
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int x = now.first + dx[k];
			int y = now.second + dy[k];

			if (x >= 1 && x <= width && y >= 1 && y <= height)
			{
				if (map[x][y] > 0 && check[x][y] == false)
				{
					check[x][y] = true;
					q.push(make_pair(x, y));
					if (map[now.first][now.second] != -1)
					{
						current_Value = map[now.first][now.second];
					}
					map[x][y] = current_Value + 1;
					map[now.first][now.second] = -1;
				}
				if (width == x && height == y)
				{
					return ;
				}
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string tmp;
	int miro[102][102];

	cin >> width >> height;

	//지형 입력
	for (int i = 1; i <= width; i++)
	{
		cin >> tmp;
		for (int j = 1; j <= height; j++)
		{
			miro[i][j] = tmp[j - 1] - 48;
		}
	}
	q.push(make_pair(1, 1));

	bfs(miro);

	cout << miro[width][height] << "\n";

	return 0;
}
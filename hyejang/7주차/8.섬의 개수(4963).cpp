#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> 

using namespace std;

int house_num = 0;
int width = 1, height = 1;
int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

void dfs(int i, int j, int map[][51], bool check[][51])
{
	check[i][j] = true;

	for (int k = 0; k < 8; k++)
	{
		int x = i + dx[k];
		int y = j + dy[k];

		if (x >= 1 && x <= height && y >= 1 && y <= width)
		{
			if (map[x][y] == 1 && check[x][y] == false)
			{
				dfs(x, y, map, check);
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int map[51][51];
	bool check[51][51] = { false };

	while (width && height)
	{
		house_num = 0;

		cin >> width >> height;

		for (int i = 1; i <= 50; i++)
		{
			for (int j = 1; j <= 50; j++)
			{
				map[i][j] = 0;
				check[i][j] = false;
			}
		}


		//지형 입력
		for (int i = 1; i <= height; i++)
		{
			for (int j = 1; j <= width; j++)
			{
				cin >> map[i][j];
			}
		}

		//섬일시 주변 체크하는 dfs

		for (int i = 1; i <= height; i++)
		{
			for (int j = 1; j <= width; j++)
			{
				if (map[i][j] == 1 && check[i][j] == false)
				{
					dfs(i, j, map, check);
					house_num++;
				}
			}
		}
		cout << house_num << "\n";
	}
	return 0;
}



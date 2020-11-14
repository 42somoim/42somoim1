#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> 

using namespace std;

int max_house[323];
int house_num = 0;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int x, int y, int size, int map[][26], bool check[][26])
{
	house_num++;
	check[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= size || ny < 0 || ny >= size)
		{
			continue;
		}
		if (map[nx][ny] == 1 && check[nx][ny] == false)
		{
			dfs(nx, ny, size, map, check);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string tmp;
	int map[26][26];
	bool check[26][26] = { false };
	int size, data, house_count = 0;

	cin >> size;

	fill(max_house, max_house + 323, 999);

	for (int i = 0; i < size; i++)
	{
		cin >> tmp;
		for (int j = 0; j < size; j++)
		{
			map[i][j] = tmp[j] - 48;
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (map[i][j] == 1 && check[i][j] == false)
			{
				house_num = 0;
				dfs(i, j, size, map, check);
				max_house[house_count++] = house_num;
			}
		}
	}
	sort(max_house, max_house + house_count);
	for (int i = 0; i < house_count; i++)
	{
		cout << max_house[i] << "\n";
	}
	return 0;
}



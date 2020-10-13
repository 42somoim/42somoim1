#include <iostream>
#include <cstring>
using	namespace std;

int		W, H;
int		visited[51][51];
int		map[51][51];

// 맵 탐색
void	dfs(int i, int j)
{
	visited[j][i] == 1;
	// 위	
	if (j > 0 && !visited[j - 1][i] && map[j - 1][i] == 1)
		dfs(i, j - 1);
	// 아래
	if (j < H - 1 && !visited[j + 1][i] && map[j + 1][i] == 1)
		dfs(i, j + 1);
	// 왼쪽
	if (i > 0 && !visited[j][i - 1] && map[j][i - 1] == 1)
		dfs(i - 1, j);
	// 오른쪽
	if (i < W - 1 && !visited[j][i + 1] && map[j][i + 1] == 1)
		dfs(i + 1, j);
	// 왼쪽 위
	if (j > 0 && i > 0 && !visited[j - 1][i - 1] && map[j - 1][i - 1] == 1)
		dfs(i - 1, j - 1);
	// 오른쪽 위
	if (j > 0 && i < W - 1 && !visited[j - 1][i + 1] && map[j - 1][i + 1] == 1)
		dfs(i + 1, j - 1);
	// 왼쪽 아래
	if (map[j + 1][i - 1] == 1)
		dfs(i - 1, j + 1);
	// 오른쪽 아래
	if (map[j + 1][i + 1] == 1)
		dfs(i + 1, j + 1);
}


int		main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (1)
	{
		cin >> W >> H;
		if (W == 0 && H == 0)
			break;
		memset(visited, 0, sizeof(visited));
		memset(map, -1, sizeof(map));
		// 맵 입력 받기
		for (int i = 0; i < W; i++)
		{
			for (int j = 0; j < H; j++)
			{
				cin >> map[j][i];
			}
		}
		// 맵 탐색
		int	cnt = 0;
		for (int i = 0; i < W; i++)
		{
			for (int j = 0; j < H; j++)
			{
				// 섬이고, 방문 한 적이 없으면
				// 탐색
				if (map[j][i] == 1 && !visited[j][i])
				{
					cnt++;
					dfs(i, j);
				}
			}
		}
		cout << cnt << '\n';
	}
	return (0);
}


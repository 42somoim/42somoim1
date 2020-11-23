/*
**	01194.cpp
**
**	달이 차오른다, 가자. by acmicpc.net
**
**
*/

#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct		map
{
	int x, y, flag, cnt;
};

queue<map>		q;
int				maps[52][52];
int				visited[52][52][(1 << 6)];
int				start[2];

int			main(void)
{
	int		n, m;
	int		i, j;
	string	in;

	i = 0;
	cin >> n >> m;
	while (i < n)
	{
		j = 0;
		cin >> in;
		while (j < in.size())
		{
			maps[i][j] = in.at(j);
			if (maps[i][j] == '0')
			{
				start[0] = i;
				start[1] = j;
			}
			j++;
		}
		i++;
	}

	q.push({start[0], start[1], 0, 0});
	while (q.size())
	{
		map	temp = q.front();
		q.pop();

		//printf("%d %d %d %d %c\n", temp.x, temp.y, temp.flag, temp.cnt, maps[temp.x][temp.y]);
		if (maps[temp.x][temp.y] >= 'a' && maps[temp.x][temp.y] <= 'f')
		{
			temp.flag |= (1 << (maps[temp.x][temp.y] - 'a'));
		}
		else if (maps[temp.x][temp.y] >= 'A' && maps[temp.x][temp.y] <= 'F')
		{
			if (!(temp.flag & (1 << (maps[temp.x][temp.y] - 'A'))))
				continue ;
		}
		else if (maps[temp.x][temp.y] == '1')
		{
			cout << temp.cnt << "\n";
			return (0);
		}
		else if (maps[temp.x][temp.y] == '#')
			continue ;
		if (visited[temp.x][temp.y][temp.flag])
			continue;
		visited[temp.x][temp.y][temp.flag] = 1;
		if (temp.x > 0)
			q.push({temp.x - 1, temp.y, temp.flag, temp.cnt + 1});
		if (temp.x < n - 1)
			q.push({temp.x + 1, temp.y, temp.flag, temp.cnt + 1});
		if (temp.y > 0)
			q.push({temp.x, temp.y - 1, temp.flag, temp.cnt + 1});
		if (temp.y < m - 1)
			q.push({temp.x, temp.y + 1, temp.flag, temp.cnt + 1});
	}
	cout << -1 << "\n";
	return (0);
}
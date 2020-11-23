/**
 *	02001.cpp
 *
 *	보석 줍기 from acmicpc.net
 * 
 **/


#include <iostream>

#define MAX(a, b) (a > b ? a : b)

using namespace std;

int		island[100][100];
int		list[100][(1 << 14)];
int		key[15];
int		n, m, k;
int		ans;

int		bit_count(int a)
{
	int	ret;

	ret = 0;
	while (a)
	{
		if (a % 2)
			ret++;
		a >>= 1;
	}
	return (ret);
}

void	dfs(int num, int jew)
{
	int	i;
	int	cnt;
	int	newjew;
	int	newcnt;

	if (list[num][jew])
		return ;
	list[num][jew] = 1;
	cnt = bit_count(jew);
	i = 0;
	newjew = jew;
	while (i < k)
	{
		if (num == key[i])
			newjew |= (1 << i);
		i++;
	}
	newcnt = bit_count(newjew);
	if (num == 0)
	{
		ans = MAX(ans, cnt);
		ans = MAX(ans, newcnt);
	}
	i = 0;
	while (i < n)
	{
		if (island[num][i] && island[num][i] >= cnt)
			dfs(i, jew);
		if (newjew != jew && island[num][i] && island[num][i] >= newcnt)
			dfs(i, newjew);
		i++;
	}
	return ;
}

int			main(void)
{
	int		i;
	int		x, y, in;
	int		temp;

	temp = 0;
	cin >> n >> m >> k;
	i = 0;
	while (i < k)
	{
		cin >> in;
		key[i] = in - 1;
		i++;
	}
	i = 0;
	while (i < m)
	{
		cin >> x >> y >> in;
		island[x - 1][y - 1] = in;
		island[y - 1][x - 1] = in;
		i++;
	}
	dfs(0, 0);
	cout << ans;
}
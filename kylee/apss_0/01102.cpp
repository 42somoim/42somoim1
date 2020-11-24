/*
**	01102.cpp
**
**	발전소 by acmicpc.net
**
*/

#include <iostream>
#include <string>
#include <cstring>

#define MIN(a, b) (a > b ? b : a) 

using namespace std;

int				cost[17][17];
int				cache[65537];
int				max_cnt;
int				n;

int				visit_count(int visit)
{
	int			ret;
	int			i;

	ret = 0;
	i = 0;
	while (i < n)
	{
		if (visit & (1 << i))
			ret++;
		i++;
	}
	return (ret);
}

int				dfs(int visit)
{
	int			i;
	int			j;

	//cout << "visit : [" << visit << "]\n";
	if (visit_count(visit) >= max_cnt)
	{
		return (0);
	}
	if (cache[visit] != -1)
		return (cache[visit]);
	
	int			ret;

	ret = 987654321;
	i = 0;
	while (i < n)
	{
		if (visit & (1 << i))
		{
			j = 0;
			while (j < n)
			{
				if (!(visit & (1 << j)))
				{
					ret = MIN(ret, dfs((visit | (1 << j))) + cost[i][j]);
					//cout << "inside : " << ret << "\n";
					cache[visit] = ret;
				}
				j++;
			}
		}
		i++;
	}
//	cout << ret << "\n";
	return (ret);
}

int				main(void)
{
	int			i;
	int			j;
	string		in;
	int			flag;
	int			ret;


	cin >> n;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			cin >> cost[i][j];
			j++;
		}
		i++;
	}
	cin >> in;
	i = 0;
	while (i < n)
	{
		if (in.at(i) == 'Y')
			flag |= (1 << i);
		i++;
	}
	cin >> max_cnt;

	ret = 987654321;
	memset(cache, -1, sizeof(cache));
	ret = MIN(ret, dfs(flag));
	if (ret != 987654321)
		cout << ret;
	else
		cout << -1;
}
/*
**	02098.cpp
**
**	외판원 순회 by acmicpc.net
**
*/

#include <iostream>

#define MIN(a, b) (a > b ? b : a)

using namespace std;

int		cost[20][20];
int		cache[20][(1 << 16)];
int		n;

long long		tsp(int now, int visit)
{
	int	i;


	if (visit == ((1 << n) - 1))
	{
		if (cost[now][0])
			return cost[now][0];
		else
			return (987654321);
	}
	if (cache[now][visit])
		return (cache[now][visit]);
	i = 0;
	int ret = 987654321;
	while (i < n)
	{
		if (!(visit & (1 << i)))
		{
			if (cost[now][i] != 0)
			{
				ret = MIN(ret, tsp(i, (visit | (1 << i))) + cost[now][i]);
				cache[now][visit] = ret;
			}
		}
		i++;
	}
	return (ret);
}

int		main(void)
{
	int	i, j;

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

	cout << tsp(0, (1 << 0));
}
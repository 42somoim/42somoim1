/**
 * 
 * 01562.cpp
 * 
 * 계단 수 by acmicpc.net
 * 
 */

#include <iostream>

#define DIV 1000000000
#define DEBUG 0
using namespace std;
typedef	long long ll;
ll		list[10][100][(1 << 10)];

void	solve(int i, int n)
{
	int	j, k, r;
	if (i == n)
	{
		return ;
	}
	else if (i == 0)
	{
		j = 1;
		while (j < 10)
		{
			list[j][i][(1 << j)] = 1;
			j++;
		}
	}
	j = 0;
	while (j < 10)
	{
		r = 0;
		while (r < (1 << 10))
		{
			if (list[j][i][r])
			{
				#if DEBUG
				if (j == 2)
					printf("%d %d %d\n", j, i, r);
				#endif
				if (j != 9)
					list[j + 1][i + 1][(r | (1 << (j + 1)))] = (list[j + 1][i + 1][r | (1 << (j + 1))] + list[j][i][r]) % DIV;
				if (j != 0)
					list[j - 1][i + 1][(r | (1 << (j - 1)))] = (list[j - 1][i + 1][r | (1 << (j - 1))] + list[j][i][r]) % DIV;
			}
			r++;
		}
		j++;
	}
	solve(i + 1, n);
}

int		main(void)
{
	int	n;
	int	i;
	int	j;
	ll	sum;

	cin >> n;
	solve(0, n);
	i = 0;
	sum = 0;
	while (i < 10)
	{
		sum = (sum + list[i][n - 1][(1 << 10) - 1]) % 1000000000;
		i++;
	}
	cout << sum;
}
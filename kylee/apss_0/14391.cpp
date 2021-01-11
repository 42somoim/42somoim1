/**
 * 
 * 14391.cpp
 * 
 * 종이 조각 from acmicpc.net
 * 
 **/


#include <iostream>
#include <string>

#define MAX(a, b) (a > b ? a : b)
using namespace std;

int		list[4][4];
string	in[4];
int		n;
int		m;

int		main(void)
{
	int	i;
	int	j;

	i = 0;
	cin >> n >> m;
	while (i < n)
	{
		cin >> in[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			if (i == 0)
			{
				list[i][j] = stoi(in[i].substr(0, j + 1));
			}
			else if (j == 0)
			{
				list[i][j] = in[i].at(j);
			}
			else
			{
			}
			
			j++;
		}
		i++;
	}
	cout << list[n - 1][m - 1];
}
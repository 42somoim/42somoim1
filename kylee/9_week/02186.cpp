/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02186.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:45:31 by kylee             #+#    #+#             */
/*   Updated: 2020/10/09 14:58:09 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define MIN(a, b) (a > b ? b : a)
#define MAX(a, b) (a > b ? a : b)
using namespace std;

int list[105][105][80];
string findc;


int check(int y, int x, int k, int find, int n, int m, int findc)
{
	int	i;
	int	ret;

	ret = 0;
	i = MAX(0, y - k);
	while (i <= MIN(n - 1, y + k))
	{
		if (i == y)
		{
			i++; continue ;
		}
		if (findc == list[i][x][0])
		{
			ret += list[i][x][find];
		}
		i++;
	}
	i = MAX(0, x - k);
	while (i <= MIN(m - 1, x + k))
	{
		if (i == x)
		{
			i++; continue ;
		}
		if (findc == list[y][i][0])
			ret += list[y][i][find];
		i++;
	}
	return (ret);
}

int main(void)
{
	int n, m, k;
	int i, j, l;
	string in;
	int	len_find;
	int	out;

	out = 0;
	cin >> n >> m >> k;
	i = 0;
	while (i < n)
	{
		cin >> in;
		j = 0;
		while (j < m)
		{
			list[i][j][0] = in.at(j);
			j++;
		}
		i++;
	}
	i = 0;
	cin >> findc;
	len_find = findc.length();
	while (i < len_find)
	{
		j = 0;
		while (j < n)
		{
			l = 0;
			while (l < m)
			{
				if (list[j][l][0] == findc[i])
				{
					if (i == 0)
						list[j][l][i + 1] = 1;
					else if (i != len_find - 1)
					{

						list[j][l][i + 1] = check(j, l, k, i, n, m, findc[i - 1]);
					}
					else
					{
						out += check(j, l, k, i, n, m, findc[i - 1]);
					}
					
				}
				l++;
			}
			j++;
		}
		i++;
	}
	if (len_find == 1)
	{
		i = 0;
		while (i < n)
		{
			j = 0;
			while (j < m)
			{
				out += list[i][j][1];
				j++;
			}
			i++;
		}
	}
	cout << out;
}
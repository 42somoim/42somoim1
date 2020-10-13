/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01987.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 17:34:29 by kylee             #+#    #+#             */
/*   Updated: 2020/10/10 18:40:15 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#define MAX(a, b) (a > b ? a : b)
using namespace std;

int g_index;
int g_test;
int alpha[30];
int	list[25][25];

int dfs(int x, int y, int index, int r, int c)
{
	if (x - 1 >= 0 && alpha[list[x - 1][y] - 'A'] == 0)
	{
		alpha[list[x - 1][y] - 'A'] = 1;
		dfs(x - 1, y, index + 1, r, c);
		g_index = MAX(index + 1, g_index);
		alpha[list[x - 1][y] - 'A'] = 0;
	}
	if (y - 1 >= 0 && alpha[list[x][y - 1] - 'A'] == 0)
	{
		g_index = MAX(index + 1, g_index);
		alpha[list[x][y - 1] - 'A'] = 1;
		dfs(x, y - 1, index + 1, r, c);
		alpha[list[x][y - 1] - 'A'] = 0;
	}
	if (x + 1 < r && alpha[list[x + 1][y] - 'A'] == 0)
	{
		g_index = MAX(index + 1, g_index);
		alpha[list[x + 1][y] - 'A'] = 1;
		dfs(x + 1, y, index + 1, r, c);
		alpha[list[x + 1][y] - 'A'] = 0;
	}
	if (y + 1 < c && alpha[list[x][y + 1] - 'A'] == 0)
	{
		g_index = MAX(index + 1, g_index);
		alpha[list[x][y + 1] - 'A'] = 1;
		dfs(x, y + 1, index + 1, r, c);
		alpha[list[x][y + 1] - 'A'] = 0;
	}
	/*
	i = 0;
	flag = 0;
	while (x + 1 < r && i < 262)
	{
		if (alpha[i] == list[x + 1][y])
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (x + 1 < r && flag == 0)
	{
		g_index = MAX(index, g_index);
		alpha[index] = list[x + 1][y];
		dfs(x + 1, y, index + 1, r, c);
		alpha[index] = 0;
	}
	i = 0;
	flag = 0;
	while (y - 1 > 0 && i < 26)
	{
		if (alpha[i] == list[x][y - 1])
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (y - 1 > 0 && flag == 0)
	{
		g_index = MAX(index, g_index);
		alpha[index] = list[x][y - 1];
		dfs(x, y - 1, index + 1, r, c);
		alpha[index] = 0;
	}
	i = 0;
	flag = 0;
	while (y + 1 < c && i < 26)
	{
		if (alpha[i] == list[x][y + 1])
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (y + 1 < c && flag == 0)
	{
		g_index = MAX(index, g_index);
		alpha[index] = list[x][y + 1];
		dfs(x, y + 1, index + 1, r, c);
		alpha[index] = 0;
	}
	*/
	return (0);
}

int	main(void)
{
	int	i;
	int	j;
	int	r, c;
	string in;

	cin >> r >> c;

	i = 0;
	while (i < r)
	{
		j = 0;
		cin >> in;
		while (j < c)
		{
			list[i][j] = in[j];
			j++;
		}
		i++;
	}
	alpha[list[0][0] - 'A'] = 1;
	g_index = 1;
	dfs(0, 0, 1, r, c);
	cout << g_index;
}
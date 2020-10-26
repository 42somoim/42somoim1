/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03108.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 16:41:16 by kylee             #+#    #+#             */
/*   Updated: 2020/10/19 16:22:40 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int 	list[2001][2001];

void	dfs(int y, int x)
{
	if (y < 0 || y > 2000 || x < 0 || y > 2000)
		return ;
	if (list[y][x] != 1)
		return ;
	list[y][x] = 2;
	dfs(y-1, x);
	dfs(y, x-1);
	dfs(y+1, x);
	dfs(y, x+1);
}

int main(void)
{
	int n;
	int	i, j;
	int x1, y1, x2, y2;
	int	ans, temp;

	i = 0;
	cin >> n;
	ans = 0;
	while (i < n)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		temp = 0;
		x1 = (x1 + 500) * 2;
		x2 = (x2 + 500) * 2;
		y1 = (y1 + 500) * 2;
		y2 = (y2 + 500) * 2;
		j = x1;
		while (j <= x2)
		{
			list[y1][j] = 1;
			list[y2][j] = 1;
			j++;
		}
		j = y1 + 1;
		while (j < y2)
		{
			list[j][x1] = 1;
			list[j][x2] = 1;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 2000)
	{
		j = 0;
		while (j < 2000)
		{
			if (list[i][j] == 1)
			{
				dfs(i, j);
				ans++;
			}
			j++;
		}
		i++;
	}
	cout << ((list[1000][1000] == 2) ? ans - 1 : ans);
}
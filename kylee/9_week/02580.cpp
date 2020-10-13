/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02580.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 16:54:36 by kylee             #+#    #+#             */
/*   Updated: 2020/10/10 17:27:05 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

int 	list[9][9];
vector<pair<int, int> > vt;

int check(int x, int y, int num)
{
	int	i;
	int	j;

	i = 0;
	while (i < 9)
	{
		if (list[x][i] == num)
			return (0);
		i++;
	}
	i = 0;
	while (i < 9)
	{
		if (list[i][y] == num)
			return (0);
		i++;
	}
	i = (x / 3) * 3;
	while (i < (x / 3) * 3 + 3)
	{
		j = (y / 3) * 3;
		while (j < (y / 3) * 3 + 3)
		{
			if (list[i][j] == num)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void dfs(int n)
{
	int	i;
	int	j;

	i = 0;
	if (n == vt.size())
	{
		while(i < 9)
		{
			j = 0;
			while (j < 9)
			{
				cout << list[i][j] << " ";
				j++;
			}
			cout << "\n";
			i++;
		}
		exit(0);
	}
	i = 0;
	while(i < 9)
	{
		if (check(vt[n].first, vt[n].second, i + 1))
		{
			list[vt[n].first][vt[n].second] = i + 1;
			dfs(n + 1);
			list[vt[n].first][vt[n].second] = 0;
		}
		i++;
	}
}
int main(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			cin >> list[i][j];
			if (list[i][j] == 0)
				vt.push_back(make_pair(i, j));
			j++;
		}
		i++;
	}
	dfs(0);
}
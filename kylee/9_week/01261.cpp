/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01261.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 17:01:53 by kylee             #+#    #+#             */
/*   Updated: 2020/10/14 18:57:03 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
#define MAX 100000
#define MIN(a, b)
int list[105][105][3];
typedef pair<int, pair<int, int> > T;
priority_queue< T, vector< T >, greater< T > > q;

int test;

int main(void)
{
	int	n, m;
	int	i, j;
	string in;
	T temp;

	cin >> n >> m;
	i = 0;
	while (i < m)
	{
		j = 0;
		cin >> in;
		while (j < n)
		{
			list[i][j][0] = in[j] - '0';
			j++;
		}
		i++;
	}
	i = 0;
	while (i < m)
	{
		j = 0;
		while (j < n)
		{
			list[i][j][1] = i + j;
			j++;
		}
		i++;
	}
	q.push({ 0, {0, 0} });
	list[0][0][1] = 0;
	while (!q.empty())
	{
		temp = q.top();
		q.pop();
		test++;
		//cout << test << " " <<  temp.second.first << " " << temp.second.second << "\n";
		if (temp.second.first == m - 1 && temp.second.second == n - 1)
		{
			break ;
		}
		if (list[temp.second.first][temp.second.second][2] == 0)
		{
			list[temp.second.first][temp.second.second][2] = 1;
			if (temp.second.first != 0)
			{
				if (list[temp.second.first][temp.second.second][1] < list[temp.second.first - 1][temp.second.second][1])
				{
					list[temp.second.first - 1][temp.second.second][1] = list[temp.second.first][temp.second.second][1] + list[temp.second.first - 1][temp.second.second][0];
					q.push({list[temp.second.first - 1][temp.second.second][1], {temp.second.first-1, temp.second.second} });
				}
			}
			if (temp.second.first != m - 1)
			{
				if (list[temp.second.first][temp.second.second][1] < list[temp.second.first + 1][temp.second.second][1])
				{
					list[temp.second.first + 1][temp.second.second][1] = list[temp.second.first][temp.second.second][1] + list[temp.second.first + 1][temp.second.second][0];
					q.push({list[temp.second.first + 1][temp.second.second][1], {temp.second.first+1, temp.second.second} });
				}
			}
			if (temp.second.second != n - 1)
			{
				if (list[temp.second.first][temp.second.second][1] < list[temp.second.first][temp.second.second + 1][1])
				{
					list[temp.second.first][temp.second.second + 1][1] = list[temp.second.first][temp.second.second][1] + list[temp.second.first][temp.second.second + 1][0];
					q.push({list[temp.second.first][temp.second.second+1][1], {temp.second.first, temp.second.second+1} });
				}
			}
			if (temp.second.second != 0)
			{
				if (list[temp.second.first][temp.second.second][1] < list[temp.second.first][temp.second.second - 1][1])
				{
					list[temp.second.first][temp.second.second - 1][1] = list[temp.second.first][temp.second.second][1] + list[temp.second.first][temp.second.second - 1][0];
					q.push({list[temp.second.first][temp.second.second-1][1], {temp.second.first, temp.second.second-1} });
				}
			}
		}

	}
	cout << list[m - 1][n - 1][1];
}
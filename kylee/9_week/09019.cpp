/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09019.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 20:13:34 by kylee             #+#    #+#             */
/*   Updated: 2020/09/28 18:00:05 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int								list[10000];

void							init(void)
{
	int							i;

	i = 0;
	while (i < 10000)
	{
		list[i] = 0;
		i++;
	}
	return ;
}

int								main(void)
{
	int							t;
	int							s;
	int							e;
	queue<pair<int, string> >	q;

	cin >> t;
	while (t--)
	{
		cin >> s >> e;
		q.push(pair<int, string>(s, ""));
		while (!q.empty())
		{
			if (q.front().first == e)
			{
				cout << q.front().second << "\n";
				break ;
			}
			if (!list[(2 * q.front().first) % 10000])
			{
				q.push(pair<int, string>((2 * q.front().first) % 10000, q.front().second + "D"));
				list[(2 * q.front().first) % 10000] = 1;
			}
			if (q.front().first != 0)
			{
				if (!list[(q.front().first - 1) % 10000])
				{
					q.push(pair<int, string>((q.front().first - 1) % 10000, q.front().second + "S"));
					list[(q.front().first - 1) % 10000] = 1;
				}
			}
			else
			{
				if (!list[9999])
				{
					q.push(pair<int, string>(9999, q.front().second + "S"));
					list[9999] = 1;
				}
			}
			if (!list[(q.front().first * 10) % 10000 + (q.front().first / 1000)])
			{
				q.push(pair<int, string>((q.front().first * 10) % 10000 + (q.front().first / 1000), q.front().second + "L"));
				list[(q.front().first * 10) % 10000 + (q.front().first / 1000)] = 1;
			}
			if (!list[(q.front().first / 10) + (q.front().first % 10) * 1000])
			{
				q.push(pair<int, string>((q.front().first / 10) + (q.front().first % 10) * 1000, q.front().second + "R"));
				list[(q.front().first / 10) + (q.front().first % 10) * 1000] = 1;
			}
			q.pop();
		}
		while (!q.empty())
		{
			q.pop();
		}
		init();
	}
}
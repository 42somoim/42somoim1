/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01525.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 18:01:36 by kylee             #+#    #+#             */
/*   Updated: 2020/09/28 20:36:51 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;

int		dx[4] = {-1, 0, 1, 0};
int		dy[4] = {0, 1, 0, -1};
int		main(void)
{
	int	in;
	int	line;
	int	i;
	queue<int> q;
	map<int, int> m;

	i = 0;
	line = 0;
	while (i < 9)
	{
		cin >> in;
		if (in == 0)
			in = 9;
		line = line * 10 + in;
		i++;
	}
	q.push(line);
	while (!q.empty())
	{
		int xy = to_string(q.front()).find('9');
		int x = xy / 3;
		int y = xy % 3;
		i = 0;
		while (i < 4)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int	temp = q.front();
			if (nx > 2 || ny > 2 || nx < 0 || ny < 0)
			{
				i++;
				continue ;
			}
			string str = to_string(temp);
			swap(str[x * 3 + y], str[nx * 3 + ny]);
			if (m.count(stoi(str)) == 0)
			{
				m[stoi(str)] = m[q.front()] + 1;
				q.push(stoi(str));
			}
			i++;
		}
		q.pop();
	}
	if (m.count(123456789) == 0)
		cout << "-1" << "\n";
	else
		cout << m[123456789];
}
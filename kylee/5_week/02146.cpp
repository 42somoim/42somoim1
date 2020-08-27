/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02146.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 10:57:44 by kylee             #+#    #+#             */
/*   Updated: 2020/08/16 11:54:46 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <queue>

using namespace std;

int list[105][105];
int flag[105][105];
int types[105][105];
queue<pair<int, int> > q;
int flage;

void init(int n)
{
	int i, j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			flag[i][j] = 0;
			j++;
		}
		i++;
	}
}

void dfs(int i, int j, int n, int flags, int type)
{
	if (flag[i][j] == 1)
		return ;
	if (list[i][j] == 0 && flags == 1)
	{
		if (types[i][j] != type)
		{
			types[i][j] = type;
			q.push(pair<int, int>(i, j));
		}
		return ;
	}
	else if (list[i][j] == 0)
		return ;
	flag[i][j] = 1;
	if (i > 0)
	{
		dfs(i - 1, j, n, 1, type);
	}
	if (i < n - 1)
	{
		dfs(i + 1, j, n, 1, type);
	}
	if (j > 0)
	{
		dfs(i, j - 1, n, 1, type);
	}
	if (j < n - 1)
	{
		dfs(i, j + 1, n, 1, type);
	}
}

int fdfs(int i, int j, int n)
{
	if (flag[i][j] == 1 || list[i][j] == 0)
	{
		flag[i][j] = 1;
		return (0);
	}
	flag[i][j] = 1;
	if (i > 0)
	{
		fdfs(i - 1, j, n);
	}
	if (i < n - 1)
	{
		fdfs(i + 1, j, n);
	}
	if (j > 0)
	{
		fdfs(i, j - 1, n);
	}
	if (j < n - 1)
	{
		fdfs(i, j + 1, n);
	}
	return (1);
}

int main(void)
{
	int n, i, j, cnt, temp, step, in;

	cin >> n;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			cin >> list[i][j];
			j++;
		}
		i++;
	}
	init(n);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (flag[i][j] == 0)
			{
				if (fdfs(i, j, n))
					cnt++;
			}
			j++;
		}
		i++;
	}
	step = 1;
	while (1)
	{
		int type = 1;
		flage = 0;
		temp = 0;
		i = 0;
		init(n);
		while (i < n)
		{
			j = 0;
			while (j < n)
			{
				dfs(i, j, n, 0, type++);
				j++;
			}
			i++;
		}
		while (!q.empty())
		{
			//cout << "x and y : " << q.front().first << " " << q.front().second << "\n";
			if (list[q.front().first][q.front().second] == step)
				flage = 1; 
			list[q.front().first][q.front().second] = step;
			types[q.front().first][q.front().second] = 0;
			q.pop();
		}
		init(n);
		i = 0;
		while (i < n)
		{
			j = 0;
			while (j < n)
			{
				if (flag[i][j] == 0)
				{
					if (fdfs(i, j, n))
						temp++;
				}
				j++;
			}
			i++;
		}
		/*
		i = 0;
		while (i < n)
		{
			j = 0;
			while (j < n)
			{
				cout << list[i][j] << " ";
				j++;
			}
			cout << "\n";
			i++;
		}
		cout << cnt << " " << temp << "\n";
		*/
		if (temp != cnt)
			break ;
		step++;
	}
	if (flage)
		cout << 2 * step - 1;
	else
		cout << 2 * step;
}
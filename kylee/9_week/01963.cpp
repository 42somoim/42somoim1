/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01953.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 18:17:20 by kylee             #+#    #+#             */
/*   Updated: 2020/09/14 20:10:20 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int			prime[10000];
int			flag[10000];
vector<int> list[10000];
queue<int>	qs;


int is_prime(int n)
{
	int i;

	i = 2;
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int connect(int n)
{
	int a, b, c, d;
	int i;

	a = n - (n / 1000) * 1000;
	b = n - ((n / 100) % 10) * 100;
	c = n - ((n % 100) / 10) * 10;
	d = n - (n % 10);

	i = 1;
	while (i < 10)
	{
		if (prime[a + i * 1000] && n != a + i * 1000)
		{
			list[n].push_back(a + i * 1000);
		}
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (prime[b + i * 100] && n != b + i * 100)
		{
			list[n].push_back(b + i * 100);
		}
		if (prime[c + i * 10] && n != c + i * 10)
		{
			list[n].push_back(c + i * 10);
		}
		if (prime[d + i * 1] && n != d + i)
		{
			list[n].push_back(d + i);
		}
		i++;
	}
	return (0);
}

int init(void)
{
	int i;

	i = 0;
	while (i < 10000)
	{
		flag[i] = 0;
		i++;
	}
	while (!qs.empty())
		qs.pop();
	return (0);
}

int f_min(int a, int b)
{
	return (a > b ? b : a);
}

int bfs(int s, int e)
{
	int i, temp, ret;
	int l;

	i = 0;
	ret = 0;
	qs.push(s);
	flag[s] = 0;
	while (!qs.empty())
	{
		i = 0;
		temp = qs.front();
		qs.pop();
		if (temp == e)
			return (flag[temp]);
		while (i < list[temp].size())
		{
			if (flag[list[temp].at(i)] == 0 && list[temp].at(i) != s)
			{
				qs.push(list[temp].at(i));
				flag[list[temp].at(i)] = flag[temp] + 1;
			}
			i++;
		}
	}
	return (-1);
}

int main(void)
{
	int t, i;
	int s, e, ret;

	cin >> t;
	i = 1000;
	while (i < 10000)
	{
		if (is_prime(i))
		{
			prime[i] = 1;
		}
		i++;
	}
	i = 1000;
	while (i < 10000)
	{
		if (prime[i])
			connect(i);
		i++;
	}
	while (t--)
	{
		init();
		cin >> s >> e;
		ret = bfs(s, e);
		if (ret == -1)
			cout << "Impossible\n";
		else
			cout << ret << "\n";
	}
}
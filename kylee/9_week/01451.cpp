/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01451.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 19:08:28 by kylee             #+#    #+#             */
/*   Updated: 2020/09/14 18:14:25 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

using namespace std;

long long list[105][105];

long long f_max(long long m, long long n)
{
	return (m < n ? n : m);
}

long long sum(long long i, long long j, long long n, long long m)
{
	long long	x, y;
	long long	a, b, c, d;

	x = 0;
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	while (x < n)
	{
		y = 0;
		while (y < m)
		{
			if (x <= i && y <= j)
				a += list[x][y];
			else if (x <= i && y > j)
				b += list[x][y];
			else if (x > i && y <= j)
				c += list[x][y];
			else
				d += list[x][y];
			y++;
		}
		x++;
	}
	return f_max(f_max((a + b) * c * d, a * (b + d) * c), f_max((c + d) * a * b, (a + c) * b * d));
}

long long sum2(long long i, long long j, long long n, long long m)
{
	long long	x, y;
	long long	a, b, c;

	x = 0;
	a = 0;
	b = 0;
	c = 0;
	while (x < n)
	{
		y = 0;
		while (y < m)
		{
			if (x <= i)
				a += list[x][y];
			else if (x <= j)
				b += list[x][y];
			else
				c += list[x][y];
			y++;
		}
		x++;
	}
	return (a * b * c);
}

long long sum3(long long i, long long j, long long n, long long m)
{
	long long	x, y;
	long long	a, b, c;

	x = 0;
	a = 0;
	b = 0;
	c = 0;
	while (x < n)
	{
		y = 0;
		while (y < m)
		{
			if (y <= i)
				a += list[x][y];
			else if (y <= j)
				b += list[x][y];
			else
				c += list[x][y];
			y++;
		}
		x++;
	}
	return (a * b * c);
}

int main(void)
{
	long long	n, m, i, j;
	string	in;
	long long	ret;

	cin >> n >> m;
	i = 0;
	while (i < n)
	{
		cin >> in;
		j = 0;
		while (j < m)
		{
			list[i][j] = in.at(j) - '0';
			j++;
		}
		i++;
	}
	i = 0;
	ret = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < m - 1)
		{
			ret = f_max(ret, sum(i, j, n, m));
			j++;
		}
		i++;
	}
	i = 0;
	while (i < n - 2)
	{
		j = i + 1;
		while (j < n - 1)
		{
			ret = f_max(ret, sum2(i, j, n, m));
			j++;
		}
		i++;
	}
	i = 0;
	while (i < m - 2)
	{
		j = i + 1;
		while (j < m - 1)
		{
			ret = f_max(ret, sum3(i, j, n, m));
			j++;
		}
		i++;
	}
	cout << ret;
}
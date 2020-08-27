/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01992.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 13:31:53 by kylee             #+#    #+#             */
/*   Updated: 2020/08/27 14:58:21 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

using namespace std;

int list[128][128];

int ppdiv(int size, int x, int y)
{

}

void pdiv(int size, int x, int y)
{
	int t, flag = 0;
	int i, j;
	int temp[4];
	if (size == 1)
	{
		cout << list[y][x];
		return ;
	}

	i = y;
	int o = 1, z = 1;
	while (i < y + size)
	{
		j = x;
		while (j < x + size)
		{
			if (list[i][j] == 1)
				z = 0;
			if (list[i][j] == 0)
				o = 0;
			j++;
		}
		i++;
	}
	if (o)
		cout << 1;
	else if (z)
		cout << 0;
	else
	{
		cout << "(";
		pdiv(size / 2, x, y);
		pdiv(size / 2, x + size / 2, y);
		pdiv(size / 2, x, y + size / 2);
		pdiv(size / 2, x + size / 2, y + size / 2);
		cout << ")";
	}
}

int main(void)
{
	int n, i, j;
	string str;

	i = 0;
	cin >> n;
	while (i < n)
	{
		cin >> str;
		j = 0;
		while (j < n)
		{
			list[i][j] = str.at(j) - '0';
			j++;
		}
		i++;
	}
	pdiv(n, 0, 0);
}
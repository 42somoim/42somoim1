/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01780.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:33:36 by kylee             #+#    #+#             */
/*   Updated: 2020/08/27 13:05:56 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int	list[2200][2200];

int g_ret[3];

int	pdiv(int size, int startx, int starty)
{
	int	f;
	int temp[9];

	f = 0;
	if (size == 1)
		return (list[starty][startx]);
	temp[0] = pdiv(size / 3, startx, starty);
	if (temp[0] == -2)
		f = 1;
	if (temp[0] != (temp[1] = pdiv(size / 3, startx + size / 3, starty)))
		f = 1;
	if (temp[0] != (temp[2] = pdiv(size / 3, startx + 2 * (size / 3), starty)))
		f = 1;
	if (temp[0] != (temp[3] = pdiv(size / 3, startx, starty + size / 3)))
		f = 1;
	if (temp[0] != (temp[4] = pdiv(size / 3, startx + size / 3, starty + size / 3)))
		f = 1;
	if (temp[0] != (temp[5] = pdiv(size / 3, startx + 2 * (size / 3), starty + size / 3)))
		f = 1;
	if (temp[0] != (temp[6] = pdiv(size / 3, startx, starty + 2 * (size / 3))))
		f = 1;
	if (temp[0] != (temp[7] = pdiv(size / 3, startx + size / 3, starty + 2 * (size / 3))))
		f = 1;
	if (temp[0] != (temp[8] = pdiv(size / 3, startx + 2 * (size / 3), starty + 2 * (size / 3))))
		f = 1;
	if (f == 0)
	{
		return (temp[0]);
	}
	else
	{
		int i = 0;
		while (i < 9)
		{
			if (temp[i] != -2)
			{
				g_ret[temp[i] + 1] ++;
			}
			i++;
		}
		return (-2);
	}
}

int main(void)
{
	int n, i, j, temp;
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
	temp = pdiv(n, 0, 0);
	if (g_ret[0] + g_ret[1] + g_ret[2] == 0)
		g_ret[temp + 1]++;
	cout << g_ret[0] << "\n" << g_ret[1] << "\n" << g_ret[2];
}
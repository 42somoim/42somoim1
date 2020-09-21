/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01107.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:04:59 by kylee             #+#    #+#             */
/*   Updated: 2020/09/13 19:04:45 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

vector<int> list;

int f_min(int a, int b)
{
	return (a > b ? b : a);
}

int f_abs(int a)
{
	return (a > 0 ? a : -a);
}

int	f_len(int a)
{
	int	ret;

	ret = 0;
	if (a == 0)
		return (1);
	while (a)
	{
		a /= 10;
		ret++;
	}
	return (ret);
}

int check_ele(int r)
{
	int i = 0;
	while (i < list.size())
	{
		if (r == list.at(i))
			return (0);
		i++;
	}
	return (1);
}

int check(int r)
{
	if (!check_ele(r % 10))
		return (0);
	while (r)
	{
		if (check_ele(r % 10))
			r /= 10;
		else
			return (0);
	}
	return (1);
}

int main(void)
{
	string n;
	int	m, in, i, down, up;

	i = 0;
	cin >> n >> m;
	while (i < m)
	{
		cin >> in;
		list.push_back(in);
		i++;
	}
	down = stoi(n);
	while (down >= 0)
	{
		if (check(down))
			break ;
		down--;
	}
	up = stoi(n);
	while (up <= 1000000)
	{
		if (check(up))
			break ;
		up++;
	}
	if (stoi(n) == 100)
		cout << 0;
	else if (stoi(n) == 99 || stoi(n) == 101)
		cout << 1;
	else if (stoi(n) == 102)
		cout << 2;
	else if (down == -1)
		cout << f_min(f_abs(stoi(n) - 100), f_abs(up - stoi(n)) + f_len(up));
	else if (up == 1000001)
		cout << f_min(f_abs(stoi(n) - 100), f_abs(down - stoi(n)) + f_len(down));
	else
		cout << f_min(f_abs(stoi(n) - 100), f_min(f_abs(up - stoi(n)) + f_len(up), f_abs(down - stoi(n)) + f_len(down)));
}
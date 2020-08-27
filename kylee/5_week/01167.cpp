/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01167.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 23:18:01 by kylee             #+#    #+#             */
/*   Updated: 2020/08/13 00:47:39 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> > list[100005];
char temps[100005];
int mn;

int max(int a, int b)
{
	return (a > b ? a : b);
}

int dfs(int n)
{
	int i, temp, first, second;
	i = 0;
	first = 0;
	second = 0;
	if (list[n].size() == 0)
		return (0);
	temps[n] = 1;
	while (i < list[n].size())
	{
		if (temps[list[n].at(i).first] == 1) { i++; continue ; }
		temp = dfs(list[n].at(i).first) + list[n].at(i).second;
		if (temp > first)
		{
			second = first;
			first = temp;
		}
		else if (temp > second)
		{
			second = temp;
		}
		i++;
	}
	temps[n] = 0;
	mn = max(second + first, mn);
 	return (first);
}

int main(void)
{
	int n, i, in, in1, in2, temp;
	cin >> n;
	i = 0;
	while (i < n)
	{
		cin >> in >> in1;
		while (in1 != -1)
		{
			cin >> in2;
			list[in].push_back(pair<int, int>(in1, in2));
			cin >> in1;
		}
		i++;
	}
	temp = dfs(1);
	cout << max(temp, mn);
}
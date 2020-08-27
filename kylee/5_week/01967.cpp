/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01967.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 23:18:01 by kylee             #+#    #+#             */
/*   Updated: 2020/08/13 00:48:12 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> > list[10005];

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
	while (i < list[n].size())
	{
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
	mn = max(second + first, mn);
 	return (first);
}

int main(void)
{
	int n, i, in, in1, in2, temp;
	cin >> n;
	i = 1;
	while (i < n)
	{
		cin >> in >> in1 >> in2;
		list[in].push_back(pair<int, int>(in1, in2));
		i++;
	}
	//temp = dfs(1);
	cout << max(dfs(1), mn);
}
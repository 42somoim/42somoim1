/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01931.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 13:41:45 by kylee             #+#    #+#             */
/*   Updated: 2020/09/08 01:30:27 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > list;

int sort_list(pair<int, int> a, pair<int, int> b)
{
	if (a.second != b.second)
		return (a.second < b.second);
	return (a.first < b.first);
	
}
int main(void)
{
	int n, i, ret;
	pair<int, int> temp;
	cin >> n;
	i = 0;
	ret = 0;
	while (i < n)
	{
		cin >> temp.first >> temp.second;
		list.push_back(temp);
		i++;
	}
	sort(list.begin(), list.end(), sort_list);
	i = 0;
	temp.first = 0;
	temp.second = -1;
	while (i < n)
	{
		if (temp.second <= list.at(i).first)
		{
			temp.first = list.at(i).first;
			temp.second = list.at(i).second;
			ret++;
		}
		i++;
	}
	cout << ret;
	return (0);
}
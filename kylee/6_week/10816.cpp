/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10816.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 12:55:39 by kylee             #+#    #+#             */
/*   Updated: 2020/08/19 22:52:15 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> list;
int main(void)
{
	int n, i, in, m, ret;
	vector<int>::iterator temp;
	vector<int>::iterator temp2;

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	i = 0;
	while (i < n)
	{
		cin >> in;
		list.push_back(in);
		i++;
	}
	sort(list.begin(), list.end());
	i = 0;
	cin >> m;
	while (i < m)
	{
		cin >> in;
		ret = 0;
		temp = lower_bound(list.begin(), list.end(), in);
		temp2 = upper_bound(list.begin(), list.end(), in);
		cout << temp2 - temp << " ";
		/*
		if (*temp == in)
		{
			while (*temp == in)
			{
				ret++;
				temp++;
			}
		}
		cout << ret << " ";
		*/
		i++;
	}
}
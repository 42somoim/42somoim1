/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02110.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:25:47 by kylee             #+#    #+#             */
/*   Updated: 2020/08/27 12:26:00 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> list;

int get_cnt(int mid)
{
	vector<int>::iterator	it;
	vector<int>::iterator	last;
	int						ret;

	it = list.begin();
	last = list.begin();
	ret = 1;
	while (it != list.end())
	{
		if (*it - *last < mid)
		{
			it++;
			continue ;
		}
		else
		{
			ret++;
			last = it;
			it++;
			continue ;
		}
	}
	return (ret);
}
int main(void)
{
	int n, c, i, input, temp;
	int lo, hi, mid;
	cin >> n >> c;
	i = 0;
	while (i < n)
	{
		cin >> input;
		list.push_back(input);
		i++;
	}
	sort(list.begin(), list.end());
	lo = 1;
	hi = list.back();
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		temp = get_cnt(mid);
		if (c > temp)
		{
			hi = mid - 1;
		}
		else if (c < temp)
		{
			lo = mid + 1;
		}
		else if (c == temp)
		{
			lo += 1;
		}
	}
	cout << lo - 1;
}
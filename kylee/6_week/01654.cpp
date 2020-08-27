/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01654.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 14:24:48 by kylee             #+#    #+#             */
/*   Updated: 2020/08/27 12:26:42 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> list;

long long get_n(int mid)
{
	long long i = 0, ret = 0;
	while (i < list.size())
	{
		ret += list.at(i) / mid;
		i++;
	}
	return (ret);
}

int main(void)
{
	long long k, n, i = 0, temp, result, lo, hi, mid, ret;
	cin >> k >> n;
	while (i < k)
	{
		cin >> temp;
		list.push_back(temp);
		i++;
	}
	sort(list.begin(), list.end());
	lo = 1;
	hi = list.at(list.size() - 1);
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		result = get_n(mid);
		if (result >= n)
		{
			ret = mid;
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}
	cout << ret;
}
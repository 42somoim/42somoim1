/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10815.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 12:45:58 by kylee             #+#    #+#             */
/*   Updated: 2020/08/16 12:57:27 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> list;

void find(int i, int in)
{
	int lo, hi, mid;

	lo = 0;
	hi = list.size() - 1;
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (list.at(mid) < in)
		{
			lo = mid + 1;
		}
		else if (list.at(mid) > in)
		{
			hi = mid - 1;
		}
		else
		{
			cout << "1 ";
			return ;
		}
	}
	cout << "0 ";
	return ;
}
int main(void)
{
	int n, i, in, m;

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
		find(i, in);
		i++;
	}
}
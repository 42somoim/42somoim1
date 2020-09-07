/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02261.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 15:12:52 by kylee             #+#    #+#             */
/*   Updated: 2020/09/03 20:55:43 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int > > list;

int tmin(int a, int b)
{
	return (a > b ? b : a);
}

int tsq(int a)
{
	return (a * a);
}

int	len(pair<int, int> i, pair<int, int> j)
{
	return (tsq(j.first - i.first) + tsq(j.second - i.second));
}

int cmp(pair<int, int> a, pair<int, int> b)
{
	return (a.first < b.first);
}

int cmpy(pair<int, int> a, pair<int, int> b)
{
	return (a.second < b.second);
}

int tdiv(int min, int max)
{
	int mid = (min + max) / 2;
	int	ret = -1;
	int i, j;
	vector<pair<int, int> > llist;

	if (max - min + 1 < 3)
	{
		ret = 0x7fffffff;
		i = min;
		while (i < max)
		{
			j = i + 1;
			while (j <= max)
			{
				if (ret > len(list.at(i), list.at(j)))
					ret = len(list.at(i), list.at(j));
				j++;
			}
			i++;
		}
		return (ret);
	}
	ret = tmin(tdiv(min, mid), tdiv(mid + 1, max));
	i = min;
	while (i <= max)
	{
		if (ret > tsq(list.at(mid).first - list.at(i).first))
			llist.push_back(list.at(i));
		i++;
	}
	sort(llist.begin(), llist.end(), cmpy);
	i = 0;
	while (i < (int)llist.size() - 1)
	{
		j = i + 1;
		while (j < llist.size())
		{
			if ((ret <= tsq(llist.at(i).second - llist.at(j).second)))
				break ;
			if (ret > len(llist.at(i), llist.at(j)))
				ret = len(llist.at(i), llist.at(j));
			j++;
		}
		i++;
	}
	return (ret);
}

int main(void)
{
	int n, i, max;
	pair<int, int> temp;

	i = 0;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> n;
	max = -1;
	while (i < n)
	{
		cin >> temp.first;
		if (max < temp.first)
		{
			max = temp.first;
		}
		cin >> temp.second;
		list.push_back(temp);
		i++;
	}
	sort(list.begin(), list.end(), cmp);
	cout << tdiv(0, list.size() - 1);

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01744.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 15:38:54 by kylee             #+#    #+#             */
/*   Updated: 2020/09/04 15:54:04 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pl;
vector<int> nl;

int main(void)
{
	int i, n, temp, zc, oc, ps, ns, extra;

	i = 0;
	zc = 0;
	oc = 0;
	ps = 0;
	ns = 0;
	extra = 0;
	cin >> n;
	while (i < n)
	{
		cin >> temp;
		if (temp > 1)
		{
			pl.push_back(temp);
		}
		else if (temp < 1)
		{
			nl.push_back(temp);
		}
		else if (temp == 0)
		{
			zc++;
		}
		else
		{
			oc++;
		}
		i++;
	}
	sort(pl.begin(), pl.end());
	sort(nl.begin(), nl.end());
	i = pl.size() - 1;
	while (i >= 0)
	{
		if (i == 0)
		{
			// 한 개
			ps += pl.at(i);
		}
		else
		{
			// 두 개.
			ps += pl.at(i) * pl.at(i - 1);
		}
		i -= 2;
	}
	i = 0;
	while (i < (int)nl.size())
	{
		if (i == (int)nl.size() - 1)
		{
			extra = nl.at(i);
		}
		else
		{
			ns += nl.at(i) * nl.at(i + 1);
		}
		i += 2;
	}
	if (zc)
		extra = 0;
	cout << ps + ns + extra + oc;
}
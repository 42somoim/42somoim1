/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02805.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 14:23:44 by kylee             #+#    #+#             */
/*   Updated: 2020/08/27 12:26:22 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int		tree[1000005];
int main(void)
{
	int n, m, mid, lo, hi, min;
	long long h;
	int i;

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	i = 1;
	cin >> n >> m;
	while (i <= n)
	{
		cin >> tree[i];
		i++;
	}
	lo = 1;
	hi = 2000000000;
	min = 0x7fffffff;
	while (lo < hi)
	{
		mid = (lo + hi) / 2;
		i = 1;
		h = 0;
		while (i <= n)
		{
			h += (tree[i] > mid) ? tree[i] - mid : 0;
			i++;
		}
		if (h == m)
			break ;
		else if (h > m)
		{
			lo = mid + 1;
		}
		else if (h < m)
		{
			hi = mid;
		}
	}
	while (1)
	{
		i = 1;
		h = 0;
		while (i <= n)
		{
			h += (tree[i] > mid) ? tree[i] - mid : 0;
			i++;
		}
		if (h < m)
			mid--;
		else
			break ;
	}
	cout << mid;
}
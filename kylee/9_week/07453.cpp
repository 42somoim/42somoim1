/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07453.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:41:53 by kylee             #+#    #+#             */
/*   Updated: 2020/10/19 00:11:42 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int	a[4001];
int	b[4001];
int	c[4001];
int	d[4001];

vector<long long> sol1;

int main(void)
{
	int	n;
	int	i, j;
	long long	ans;
	pair<vector<long long>::iterator, vector<long long>::iterator> temp;

	i = 0;
	ans = 0;
	cin >> n;
	while (i < n)
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			sol1.push_back(a[i] + b[j]);
			j++;
		}
		i++;
	}
	sort(sol1.begin(), sol1.end());
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			temp = equal_range(sol1.begin(), sol1.end(), -(c[i] + d[j]));
			ans += temp.second - temp.first;
			j++;
		}
		i++;
	}
	cout << ans;
}
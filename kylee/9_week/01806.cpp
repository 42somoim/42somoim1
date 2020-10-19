/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01806.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:29:53 by kylee             #+#    #+#             */
/*   Updated: 2020/10/14 17:47:28 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define INT_MAX 2000000000
using namespace std;

int	list[100005];
int main(void)
{
	long long n, s;
	long long	i;
	long long j;
	long long sum;
	int			ret;
	int			ans = INT_MAX;

	i = 0;
	cin >> n >> s;
	sum = 0;
	while (i < n)
	{
		cin >> list[i];
		i++;
	}
	i = 0;
	j = 0;
	ret = 0;
	sum = list[0];
	while (i <= j && j < n)
	{
		if (s > sum)
		{
			if (j < n)
			{
				j++;
				sum += list[j];
			}
		}
		else
		{
			ret = j - i + 1;
			if (ans > ret)
				ans = ret;
			if (i <= j)
			{
				sum -= list[i];
				i++;
			}
		}
	}
	cout << ((ans == INT_MAX) ? 0 : ans);
}
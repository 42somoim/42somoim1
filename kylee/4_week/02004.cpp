/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02004.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 19:22:02 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 19:37:12 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#define INT_MAX 2147483647
using namespace std;

long long min(long long a, long long b)
{
	return ((a > b) ? b : a);
}
int main(void)
{
	long long n, m, i;
	long long ret, ret2;

	ret = 0;
	ret2 = 0;
	cin >> n >> m;
	i = 5;
	while (i < 1220703126)
	{
		ret += (n / i);
		i *= 5;
	}
	i = 5;
	while (i < 1220703126)
	{
		ret -= (m / i);
		i *= 5;
	}
	i = 5;
	while (i < 1220703126)
	{
		ret -= (n - m) / i;
		i *= 5;
	}
	i = 2;
	while (i < INT_MAX)
	{
		ret2 += (n / i);
		i *= 2;
	}
	i = 2;
	while (i < INT_MAX)
	{
		ret2 -= (m / i);
		i *= 2;
	}
	i = 2;
	while (i < INT_MAX)
	{
		ret2 -= (n - m) / i;
		i *= 2;
	}
	cout << min(ret, ret2);
}
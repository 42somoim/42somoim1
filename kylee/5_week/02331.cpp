/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02331.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 09:23:29 by kylee             #+#    #+#             */
/*   Updated: 2020/08/09 09:51:37 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int arr[500005][2];

int power(int n, int p)
{
	int i = 0 ,ret = 1;

	while (i < p)
	{
		ret *= n;
		i++;
	}
	return (ret);
}

int get(int n, int p)
{
	int ret = 0;

	while (n)
	{
		ret += power((n % 10), p);
		n /= 10;
	}
	return (ret);
}

int main(void)
{
	int a, p, s, ret;
	cin >> a >> p;
	s = a;
	while (1)
	{
		if (arr[a][1] == 1)
			break ;
		arr[a][1] = 1;
		arr[a][0] = get(a, p);
		a = arr[a][0];
	}
	ret = (a != s) ? 1 : 0;
	while (ret)
	{
		if (a == arr[s][0])
			break ;
		s = arr[s][0];
		ret++;
	}
	cout << ret;
}
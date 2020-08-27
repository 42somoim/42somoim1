/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01517.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 18:27:32 by kylee             #+#    #+#             */
/*   Updated: 2020/08/27 19:25:24 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int list[500005];

long long int	fdiv(int s, int e)
{
	int temp[500005];
	int mid = (e + s) / 2;
	long long int ret;

	ret = 0;
	if (e == s)
		return (0);
	ret += fdiv(s, mid);
	ret += fdiv(mid + 1, e);
	int i = s;
	int j = mid + 1;
	int r = 0;
	while (i <= mid && j <= e)
	{
		if (list[i] > list[j])
		{
			temp[r] = list[j];
			ret += (mid - i + 1);
			r++;
			j++; 
		}
		else
		{
			temp[r] = list[i];
			r++;
			i++;
		}
	}
	while (i <= mid)
	{
		temp[r] = list[i];
		r++;
		i++;
	}
	while (j <= e)
	{
		temp[r] = list[j];
		r++;
		j++;
	}
	i = s;
	while (i <= e)
	{
		list[i] = temp[i - s];
		i++;
	}
	return (ret);
}

int main(void)
{
	int n;
	int i;
	long long int ret;

	cin >> n;
	i = 0;
	while (i < n)
	{
		cin >> list[i];
		i++;
	}
	ret = fdiv(0, n - 1);
	i = 0;
	printf("%lld\n", ret);
	while (i < n)
	{
		//cout << list[i] << " ";
		i++;
	}
}
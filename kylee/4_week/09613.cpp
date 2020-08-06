/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09613.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 00:11:43 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 16:34:12 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#define MAX_COUNT 105
using namespace std;

int				ft_gcd(int a, int b)
{
	int			temp;

	temp = (a > b) ? b : a;
	while (!(a % temp == 0 && b % temp == 0))
		temp--;
	return (temp);
}

int				main(void)
{
	int			t;
	int			n;
	int			num[MAX_COUNT];
	int			i;
	long long	sum;
	int			j;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--)
	{
		i = 0;
		sum = 0;
		cin >> n;
		while (i < n)
			cin >> num[i++];
		i = 0;
		while (i < n)
		{
			j = i + 1;
			while (j < n)
			{
				sum += ft_gcd(num[i], num[j]);
				j++;
			}
			i++;
		}
		cout << sum << "\n";
	}
	return (0);
}
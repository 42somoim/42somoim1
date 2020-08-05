/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   쉬운_계단_수.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 19:22:10 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/08/02 20:20:50 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

int		main(void)
{
	int			n;
	int			b = 10007;
	vector<int>	v[10];
	
	cin >> n;
	for(int i = 0; i < 10; i++)
	{
		v[i].push_back(0);
		v[i].push_back(1);
	}
	
	for(int len = 2; len <= n; len++)
	{
		for(int digit = 0; digit < 10; digit++)
		{
			int sum = 0;
			for(int add = digit; add < 10; add++)
			{
				sum = (sum + v[add][len - 1]) % b;
			}
			v[digit].push_back(sum % b);
		}
	}

	long sum = 0;
	for(int i = 0; i < 10; i++)
	{
		sum += (v[i][n] % b);
	}
	cout << sum % b << endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   쉬운_계단_수.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 19:22:10 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/08/02 19:40:44 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

int		main(void)
{
	int			n;
	int			b = 1000000000;
	vector<int>	v[10];
	
	cin >> n;
	for(int i = 0; i < 10; i++)
	{
		v[i].push_back(0);
		if (i != 0)
			v[i].push_back(1);
		else
			v[i].push_back(0);
	}
	
	for(int len = 2; len <= n; len++)
	{
		for(int digit = 0; digit < 10; digit++)
		{
			int sum;
			if (digit == 0)
				sum = v[1][len - 1];
			else if (digit == 9)
				sum = v[8][len - 1];
			else
				sum = (v[digit - 1][len - 1] % b) + (v[digit + 1][len - 1] % b);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10610.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 14:02:55 by kylee             #+#    #+#             */
/*   Updated: 2020/09/04 14:15:33 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int	list[10];
int main(void)
{
	int i, z, sum;

	string str;

	z = 0;
	sum = 0;
	i = 0;
	cin >> str;
	while (i < str.size())
	{
		if (str.at(i) - '0' == 0)
			z++;
		else
			sum += str.at(i) - '0';
		list[str.at(i) - '0']++;
		i++;
	}
	if (!(z > 0 && sum % 3 == 0))
	{
		cout << -1;
		return (0);
	}
	i = 0;
	while (i < 10)
	{
		while (list[9 - i])
		{
			cout << 9 - i;
			list[9 - i]--;
		}
		i++;
	}

}
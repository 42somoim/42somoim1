/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02011.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 23:20:21 by kylee             #+#    #+#             */
/*   Updated: 2020/07/31 00:49:13 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

int	list[5003];

int main(void)
{
	string input;
	int		i;
	int		flag;

	i = 0;
	cin >> input;
	flag = 0;
	while (i < input.size())
	{
		if (i == 0)
		{
			if (input.at(i) - '0' != 0)
				list[i] = 1;
			else
			{
				flag = 1;
			}
			
		}
		else if (i == 1)
		{
			if (input.at(i) - '0' != 0)
				list[i] = 1;
			if (input.at(i - 1) - '0' == 2 && input.at(i) - '0' >= 0 && input.at(i) - '0' <= 6)
			{
				list[i] += list[i - 1];
			}
			else if (input.at(i - 1) - '0' == 1)
				list[i] += list[i - 1];
			else if (input.at(i) - '0' == 0 && input.at(i - 1) - '0' == 0)
				flag = 1;
		}
		else
		{
			if (input.at(i) - '0' != 0)
				list[i] = list[i - 1];
			if (input.at(i - 1) - '0' == 2 && input.at(i) - '0' >= 0 && input.at(i) - '0' <= 6)
				list[i] = (list[i] + list[i - 2]) % 1000000;
			else if (input.at(i - 1) - '0' == 1)
				list[i] = (list[i] + list[i - 2]) % 1000000;
			else if (input.at(i) - '0' == 0 && input.at(i - 1) - '0' == 0)
				flag = 1;
		}
		i++;
	}
	if (!flag)
		cout << list[i - 1] % 1000000;
	else
		cout << 0;	
}
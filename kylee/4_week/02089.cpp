/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02089.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:43:37 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 18:32:46 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>


using namespace std;
vector<char> list;

int abs(int a)
{
	return (a > 0 ? a : -a);
}

int main(void)
{
	int n;
	cin >> n;
	if (n == 0)
	{
		cout << "0";
	}
	while (n)
	{
		if (n > 0)
		{
			list.push_back(n % 2 + '0');
			n /= -2;
		}
		else
		{
			if (abs(n) % 2 == 0)
			{
				list.push_back('0');
				n /= -2;
			}
			else
			{
				list.push_back('1');
				n = abs(n) / 2 + 1;
			}
		}
	}
	while (!list.empty())
	{
		cout << list.back();
		list.pop_back();
	}
}
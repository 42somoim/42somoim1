/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02445.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 00:57:07 by kylee             #+#    #+#             */
/*   Updated: 2020/07/24 00:57:09 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;
int main(void)
{
	int i;
	int k;
	cin >> i;
	k = 0;
	while (k < i - 1)
	{
		int j = 0;
		while (j < k + 1)
		{
			cout << "*";
			j++;
		}
		while (j < 2 * i - k - 1)
		{
			cout << " ";
			j++;
		}
		while (j < 2 * i)
		{
			cout << "*";
			j++;
		}
		cout << "\n";
		k++;
	}
	//
	k = 0;
	while (k++ < 2 * i)
		cout << "*";
	cout << "\n";
	k = 1;
	while (k < i)
	{
		int j = 0;
		while (j < i - k)
		{
			cout << "*";
			j++;
		}
		while (j < i + k)
		{
			cout << " ";
			j++;
		}
		while (j < 2 * i)
		{
			cout << "*";
			j++;
		}
		cout << "\n";
		k++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02446.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 01:00:50 by kylee             #+#    #+#             */
/*   Updated: 2020/07/24 01:00:51 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int main(void)
{
	int i, j, k;
	cin >> i;
	j = 0;
	while (j < i)
	{
		k = 0;
		while (k < j)
		{
			cout << " ";
			k++;
		}
		while (k < 2 * i - j - 1)
		{
			cout << "*";
			k++;
		}
		cout << "\n";
		j++;
	}
	j = 0;
	while (j < i - 1)
	{
		k = 0;
		while (k < i - j - 2)
		{
			cout << " ";
			k++;
		}
		while (k < i + j + 1)
		{
			cout << "*";
			k++;
		}
		cout << "\n";
		j++;
	}
}
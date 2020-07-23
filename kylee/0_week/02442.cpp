/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02442.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 23:02:30 by kylee             #+#    #+#             */
/*   Updated: 2020/07/23 23:02:31 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int main(void)
{
	int i;
	int j;
	int max;
	int k;
	cin >> i;
	max = i;
	while (i)
	{
		j = 2 * (max - i) + 1;
		k = 0;
		while (k < i - 1)
		{
			cout << " ";
			k++;
		}
		while (j--)
		{
			cout << "*";
		}
		cout << "\n";
		i--;
	}
}
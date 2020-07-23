/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02441.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 23:02:04 by kylee             #+#    #+#             */
/*   Updated: 2020/07/23 23:02:04 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int main(void)
{
	int i;
	int max;
	int j;
	cin >> i;
	max = i;
	while (i)
	{
		j = max;
		while (i < j)
		{
			cout << " ";
			j--;
		}
		while (j)
		{
			cout << "*";
			j--;
		}
		cout << "\n";
		i--;
	}
}
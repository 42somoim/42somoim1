/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02522.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 01:00:26 by kylee             #+#    #+#             */
/*   Updated: 2020/07/24 01:00:27 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int main(void)
{
	int i;
	int j;
	cin >> i;
	j = 0;
	while (j < i - 1)
	{
		int k = 0;
		while (k < i - j - 1)
		{
			cout << " ";
			k++;
		}
		while (k < i)
		{
			cout << "*";
			k++;
		}
		cout << "\n";
		j++;
	}
	j = 0;
	while (j++ < i)
		cout << "*";
	cout << "\n";
	j = 0;
	while (j < i - 1)
	{
		int k = 0;
		while (k < j + 1)
		{
			cout << " ";
			k++;
		}
		while (k < i)
		{
			cout << "*";
			k++;
		}
		cout << "\n";
		j++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10953.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 22:55:15 by kylee             #+#    #+#             */
/*   Updated: 2020/07/23 22:55:16 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int t;
	string str;
	string::const_iterator it;
	cin >> t;
	while (t--)
	{
		cin >> str;
		it = str.begin();
		cout << it[0] + it[2] - 2 * '0'  <<"\n";
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10820.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:30:25 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 14:35:17 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

int list[4];
int main(void)
{
	int n;
	string str;
	getline(cin, str);
	while (!cin.eof())
	{
		list[0] = 0;
		list[1] = 0;
		list[2] = 0;
		list[3] = 0;
		n = 0;
		while (n < str.size())
		{
			if (str.at(n) >= 'a' && str.at(n) <= 'z')
				list[0]++;
			else if (str.at(n) >= 'A' && str.at(n) <= 'Z')
				list[1]++;
			else if (str.at(n) >= '0' && str.at(n) <= '9')
				list[2]++;
			else if (str.at(n) == ' ')
				list[3]++;
			n++;
		}
		cout << list[0] << " " << list[1] << " " << list[2] << " " << list[3] << "\n";
		getline(cin, str);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11655.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:38:13 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 14:48:52 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string s;
	getline(cin, s);
	int i = 0;
	while (i < s.size())
	{
		if (s.at(i) >= 'a' && s.at(i) <= 'z')
		{
			cout << (unsigned char)((s.at(i) - 'a' + 13) % 26 + 'a');
		}
		else if (s.at(i) >= 'A' && s.at(i) <= 'Z')
		{
			cout << (unsigned char)((s.at(i) - 'A' + 13) % 26 + 'A');
		}
		else
		{
			cout << (unsigned char)s.at(i);
		}
		i++;
	}
}
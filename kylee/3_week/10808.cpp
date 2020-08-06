/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10808.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:28:45 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 14:29:49 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

int list[26];

int main(void)
{
	string str;
	cin >> str;
	int i = 0;
	while (i < str.size())
	{
		list[str.at(i) - 'a']++;
		i++;
	}
	i = 0;
	while (i < 26)
	{
		cout << list[i] << " ";
		i++;
	}
}
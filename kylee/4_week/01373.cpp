/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01373.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:18:54 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 17:35:07 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string s;
	int i = 0, ret = 0, flag = 1;
	cin >> s;
	
	if (s.size() == 1 && s.at(i) == '0')
		cout << 0;
	while (i < s.size())
	{
		ret *= 2;
		ret += s.at(i) - '0';
		if (!((s.size() - i - 1) % 3))
		{
			if (ret != 0)	
				flag = 0;
			if (!(flag == 1 && ret == 0))
				cout << ret;
			ret = 0;
		}
		i++;
	}
	if (ret)
		cout << ret;
}
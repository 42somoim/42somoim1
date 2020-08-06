/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10799.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:09:14 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 14:12:16 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int i = 0, ret = 0, stack = 0;
	string str;

	cin >> str;
	while (i < str.size() - 1)
	{
		if (str.at(i) == '(' && str.at(i + 1) == ')')
		{
			ret += stack;
			i++;
		}
		else if (str.at(i) == '(')
		{
			ret += 1;
			stack++;
		}
		else if (str.at(i) == ')')
		{
			stack--;
		}
		i++;
	}
	cout << ret;
}
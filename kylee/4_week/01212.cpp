/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01212.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 22:36:20 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 16:34:33 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string output[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};
string output2[8] = {"0", "1", "10", "11", "100", "101", "110", "111"};
int main(void)
{
	string input;
	int		i;

	i = 0;
	cin >> input;
	while (i < input.size())
	{
		if (i)
			cout << output[input.at(i) - '0'];
		else
			cout << output2[input.at(i) - '0'];
		i++;
	}
}
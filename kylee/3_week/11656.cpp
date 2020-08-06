/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11656.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:49:06 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 14:57:45 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
vector<string> list;


int main(void)
{
	int i = 0;
	string s;
	cin >> s;
	while (i < s.size())
	{
		list.push_back(&s.at(i));
		i++;
	}
	sort(list.begin(), list.end());
	i = 0;
	while (i < list.size())
	{
		cout << list.at(i) << "\n";
		i++;
	}
}
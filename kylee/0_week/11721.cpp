/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11721.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 22:58:14 by kylee             #+#    #+#             */
/*   Updated: 2020/07/23 22:58:15 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str;
	string::const_pointer pt;
	cin >> str;
	pt = &str.front();
	int i = 0;
	while (pt[i])
	{
		cout << pt[i];
		i++;
		if (i % 10 == 0)
			cout << "\n";
	}
}
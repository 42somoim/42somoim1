/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02745.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:14:52 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 17:17:31 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	string n;
	int b, i, ret;
	cin >> n >> b;
	i = 0;
	ret = 0;
	while (i < n.size())
	{
		ret *= b;
		if (n.at(i) >= '0' && n.at(i) <= '9')
			ret += n.at(i) - '0';
		else
			ret += n.at(i) - 'A' + 10;
		i++;
	}
	cout << ret;
}
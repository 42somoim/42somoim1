/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11718.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 22:56:58 by kylee             #+#    #+#             */
/*   Updated: 2020/07/23 22:56:59 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;
int main(void)
{
	string str;
	while (1)
	{
		getline(cin, str);
		if (cin.eof())
			return (0);
		cout << str << "\n";
	}
}
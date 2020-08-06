/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11005.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:10:01 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 17:13:56 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;
vector<char> list;
int main(void)
{
	int n, b;
	cin >> n >> b;
	if (n == 0)
		list.push_back('0');
	while (n)
	{
		if (n % b < 10)
			list.push_back(n % b + '0');
		else
			list.push_back(n % b + 'A' - 10);
		n /= b;
	}
	while (!list.empty())
	{
		cout << list.back();
		list.pop_back();
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11047.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 13:05:24 by kylee             #+#    #+#             */
/*   Updated: 2020/09/04 13:29:00 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

vector<int> list;
int main(void)
{
	int n, k, i, temp, cnt;
	cin >> n >> k;
	i = 0;
	while (i < n)
	{
		cin >> temp;
		list.push_back(temp);
		i++;
	}
	cnt = 0;
	i = 0;
	while (i < n)
	{
		temp = k / list[n - 1 - i];
		k -= temp * list[n - 1 - i];
		cnt += temp;
		i++;
	}
	cout << cnt;
}
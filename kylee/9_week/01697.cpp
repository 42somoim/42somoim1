/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01697.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 15:48:44 by kylee             #+#    #+#             */
/*   Updated: 2020/09/14 18:17:06 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <queue>

using namespace std;

int		arr[100005];
queue<int> list;

int main(void)
{
	int i = 0 ;
	int n, k;
	cin >> n >> k;

	while (i <100005)
		arr[i++] = -1;
	arr[n] = 0;
	list.push(n);
	while (!list.empty())
	{
		i = 0;
		int temp = list.front();
		if (temp * 2 < 100001)
		{
			if (arr[2 * temp] == -1)
			{
				arr[2 * temp] = arr[temp] + 1;
				list.push(2 * temp);
			}
		}
		if (temp < 100000)
		{
			if (arr[temp + 1] == -1)
			{
				arr[1 + temp] = arr[temp] + 1;
				list.push(1 + temp);
			}
		}
		if (temp > 0)
		{
			if (arr[temp - 1] == -1)
			{
				arr[temp - 1] = arr[temp] + 1;
				list.push(temp - 1);
			}
		}
		list.pop();
	}
	cout << arr[k];
	return 0;
}
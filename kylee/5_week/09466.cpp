/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09466.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 10:01:32 by kylee             #+#    #+#             */
/*   Updated: 2020/08/09 10:40:59 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int arr[100005][2];

int main(void)
{
	int t, n, i, s, a, ret;
	cin >> t;
	while (t--)
	{
		cin >> n;
		i = 0;
		while (i < n)
		{
			cin >> arr[i + 1][0];
			arr[i + 1][1] = 0;
			i++;
		}
		i = 0;
		ret = 0;
		while (i < n)
		{
			s = i + 1;
			a = s;
			if (arr[s][1] == 1) { i++; continue ; }
			while (1)
			{
				if (arr[a][1] == 1) { break ; }
				arr[a][1] = 1;
				a = arr[a][0];
			}
			while (1)
			{
				if (a == s) break ;
				ret++;
				s = arr[s][0];
			}
			i++;
		}
		cout << ret << "\n";
	}
}
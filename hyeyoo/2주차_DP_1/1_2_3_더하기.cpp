/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_2_3_더하기.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 19:04:20 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/08/02 19:07:53 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

int		main(void)
{
	int			t;
	int			n;
	vector<int> v;

	v.push_back(0);
	v.push_back(1); // 1 = 1
	v.push_back(2); // 2 = 1 + 1 = 2
	v.push_back(4); // 3 = 1 + 1 + 1 = 1 + 2 = 2 + 1 = 3
	for(int i = 4; i <= 11; i++)
	{
		int sum = v[i - 1] + v[i - 2] + v[i - 3];
		v.push_back(sum);
	}

	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << v[n] << endl;
	}
}

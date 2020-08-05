/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2xn_타일링_2.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 19:01:17 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/08/02 19:02:56 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

int		main(void)
{
	int			n;
	vector<int>	v;

	v.push_back(0);
	v.push_back(1);
	v.push_back(3);
	cin >> n;
	for(int i = 3; i <= n; i++)
	{
		int val = (v[i - 1] + 2 * v[i - 2]) % 10007;
		v.push_back(val);
	}
	cout << v[n] << endl;
}

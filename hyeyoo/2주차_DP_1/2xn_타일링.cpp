/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2xn_타일링.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 18:53:58 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/08/02 19:00:36 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

int		main(void)
{
	int			n;
	vector<int> v;

	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	cin >> n;
	for(int i = 3; i <= n; i++)
	{
		int val = (v[i - 1] + v[i - 2]) % 10007;
		v.push_back(val);
	}
	cout << v[n] << endl;
}

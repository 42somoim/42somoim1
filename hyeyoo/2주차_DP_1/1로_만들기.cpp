/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1로_만들기.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 18:49:31 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/08/02 18:52:56 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

int		main(void)
{
	int n;
	vector<int> v;

	cin >> n;
	v.push_back(0);
	v.push_back(0);
	for(int i = 2; i <= n; i++)
	{
		int min_val = v[i - 1];
		if (i % 3 == 0)
			min_val = min(min_val, v[i / 3]);
		if (i % 2 == 0)
			min_val = min(min_val, v[i / 2]);
		v.push_back(min_val + 1);
	}
	cout << v[n] << endl;
}

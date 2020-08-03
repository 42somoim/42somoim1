/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   스티커.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 20:32:57 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/08/02 20:51:40 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

int		main(void)
{
	int				t;

	cin >> t;
	while (t--)
	{
		int			n;
		int			num;
		int			ans = 0;
		vector<int>	v[2];
		vector<int> d[2];

		cin >> n;
		for(int i = 0; i < n; i++)
		{
			cin >> num;
			v[0].push_back(num);
		}
		for(int i = 0; i < n; i++)
		{
			cin >> num;
			v[1].push_back(num);
		}

		d[0].push_back(v[0][0]);
		d[1].push_back(v[1][0]);
		d[0].push_back(d[1][0] + v[0][1]);
		d[1].push_back(d[0][0] + v[1][1]);
		for(int i = 2; i <= n; i++)
		{
			//zero
			int sum = max(d[0][i - 2], max(d[1][i - 2], d[1][i - 1])) + v[0][i];
			d[0].push_back(sum);
			//one
			sum = max(d[0][i - 2], max(d[1][i - 2], d[0][i - 1])) + v[1][i];
			d[1].push_back(sum);
		}
		cout << max(d[1][n], d[0][n]) << endl;
	}
	return (0);
}

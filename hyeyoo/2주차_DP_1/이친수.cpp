/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   이친수.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 20:21:27 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/08/02 20:31:31 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

/*
 * 이친수
 * N = 1
 * 1
 * N = 2
 * 10
 * N = 3
 * 100, 101
 * N = 4
 * 1000, 1001, 1010
 * N = 5
 * 10000, 10001, 10010, 10100
 *
 * 규칙 : 길이 N인 이친수 =  2 * (길이 N - 1의 0으로 끝나는 것) + (길이 N - 1의 1로 끝나는 것)
 */

int		main(void)
{
	int					n;
	vector<long>		v[2];

	v[0].push_back(0);
	v[1].push_back(0);
	v[0].push_back(0);
	v[1].push_back(1);
	cin >> n;
	for(int i = 2; i <= n; i++)
	{
		long zero = v[0][i - 1] + v[1][i - 1];
		long one = v[0][i - 1];
		v[0].push_back(zero);
		v[1].push_back(one);
	}
	cout << v[0][n] + v[1][n] << endl;
	return (0);
}

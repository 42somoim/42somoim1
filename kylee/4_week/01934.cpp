/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01934.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 23:43:18 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 16:33:49 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int				ft_lcm(int a, int b)
{
	int			temp;

	temp = a;
	while (temp % b != 0)
		temp += a;
	return (temp);
}

int				main(void)
{
	int			a;
	int			b;
	int			t;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		cout << ft_lcm(a, b) << "\n";
	}
	return (0);
}
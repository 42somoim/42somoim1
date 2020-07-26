/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11727.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 18:55:58 by kylee             #+#    #+#             */
/*   Updated: 2020/07/26 18:55:58 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#define MAX_NUM 1005
#define NUM_DIV 10007
using namespace std;

int				g_dp[MAX_NUM];

int				ft_rec(int index, int n)
{
	int			ret;

	ret = 0;
	if (index == n)
		return (1);
	if (!g_dp[index])
	{
		ret += ft_rec(index + 1, n);
		ret += (index == n - 1) ? 0 : 2 * ft_rec(index + 2, n);
		g_dp[index] = ret;
	}
	else
	{
		ret = g_dp[index];	
	}
	return (ret % NUM_DIV);
}

int				main(void)
{
	int			n;

	cin >> n;
	cout << ft_rec(0, n);
	return (0);
}
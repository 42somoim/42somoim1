/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1929.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:43:11 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 16:35:15 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int			ft_is_prime(int nb)
{
	int		i;

	i = 2;
	if (nb == 1)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int			main(void)
{
	int		m;
	int		n;

	cin >> m >> n;
	while (m <= n)
	{
		if (ft_is_prime(m))
			cout << m << "\n";
		m++;
	}
	return (0);
}
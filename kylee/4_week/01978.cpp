/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01978.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:26:51 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 16:35:21 by kylee            ###   ########.fr       */
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
	int		n;
	int		temp;
	int		num;

	num = 0;
	cin >> n;
	while (n--)
	{
		cin >> temp;
		num += ft_is_prime(temp);
	}
	cout << num;
}
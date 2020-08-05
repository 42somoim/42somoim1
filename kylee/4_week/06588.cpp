/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06588.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 00:34:09 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 16:35:45 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int				ft_is_prime(int nb)
{
	long long	i;

	i = 2;
	while (i * i <= (long long)nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int				main(void)
{
	int			n;
	int			i;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	while (n)
	{
		i = 3;
		while (!(ft_is_prime(n - i) && ft_is_prime(i)) && i <= n / 2)
			i += 2;
		if (i > n / 2)
			cout << "Goldbach's conjecture is wrong." << "\n";
		else
			cout << n << " = " << i << " + " << n - i << "\n";
		cin >> n;
	}	
}
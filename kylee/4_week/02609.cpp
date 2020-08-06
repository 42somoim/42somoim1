/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02609.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 23:06:09 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 16:33:28 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

void			ft_swap(int *n, int *m)
{
	int			temp;

	temp = *n;
	*n = *m;
	*m = temp;
	return ;
}

int				ft_gcf(int n, int m)
{
	int			temp;

	if (n < m)
		ft_swap(&n, &m);
	temp = m;
	while (!(n % temp == 0 && m % temp == 0))
		temp--;
	return (temp);
}

int				ft_lcm(int n, int m)
{
	int			temp;

	if (n < m)
		ft_swap(&n, &m);
	temp = m;
	while (temp % n != 0)
		temp += m;
	return (temp);
}

int				main(void)
{
	int			n;
	int			m;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	cout << ft_gcf(n, m) << "\n" << ft_lcm(n, m);
}
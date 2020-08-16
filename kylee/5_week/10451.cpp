/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10451.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 09:07:10 by kylee             #+#    #+#             */
/*   Updated: 2020/08/09 09:21:29 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int sc[1005][2];

int c(int s)
{
	if (sc[s][1] == 0)
		return (0);
	sc[s][1] = 0;
	c(sc[s][0]);
	return (1);
}

int main(void)
{
	int	t;
	int	n;
	int	i;
	int	ret;

	cin >> t;
	while (t--)
	{
		cin >> n;
		i = 0;
		ret = 0;
		while (i < n)
		{
			cin >> sc[i + 1][0];
			sc[i + 1][1] = 1;
 			i++;
		}
		i = 0;
		while (i < n)
		{
			ret += c(i + 1);
			i++;
		}
		cout << ret << "\n";
	}
}
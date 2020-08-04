/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01924.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 22:59:44 by kylee             #+#    #+#             */
/*   Updated: 2020/07/23 22:59:45 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;
string week[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int main(void)
{
	int m, d;
	int	day;

	day = 0;
	cin >> m >> d;
	while (--m)
	{
		if (m == 12 || m == 10 || m == 8 || m == 7 || m == 5 || m == 3 || m == 1)
		{
			day += 31;
		}
		else if (m == 4 || m == 6 || m == 9 || m == 11)
		{
			day += 30;
		}
		else if(m == 2)
		{
			day += 28;
		}
	}
	day += d;
	cout << week[day % 7];
}
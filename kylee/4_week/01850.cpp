/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01850.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:37:25 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 16:51:53 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int gcd(long long a, long long b)
{
	if (b == 0)
		return (a);
	else
		return (gcd(b, a % b));
}
int main(void)
{
	long long int a, b;
	cin >> a >> b;
	long long res;

	res = gcd(a, b);
	int i = 0;
	while (i < res)
	{
		cout << "1";
		i++;
	}	
}
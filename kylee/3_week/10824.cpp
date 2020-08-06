/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10824.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:43:00 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 14:47:28 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int main(void)
{
	string a, b, c, d;
	long long ret;

	cin >> a >> b >> c >> d;
	a = a + b;
	c = c + d;
	ret = atoll(&a.at(0)) + atoll(&c.at(0));
	cout << ret;
}
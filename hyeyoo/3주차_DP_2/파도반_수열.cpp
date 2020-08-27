/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   파도반_수열.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 05:05:11 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/08/13 05:15:28 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int main(void)
{
	int t;
	int n;
	long *d;

	d = new long[100 + 1];
	d[1] = d[2] = d[3] = 1;
	d[4] = d[5] = 2;
	for(int i = 6; i <= 100; i++) {
		d[i] = d[i - 1] + d[i - 5];
	}

	cin >> t;
	while (t--) {
		cin >> n;
		cout << d[n] << endl;
	}
	delete[] d;
}

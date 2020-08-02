/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09095.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 18:56:14 by kylee             #+#    #+#             */
/*   Updated: 2020/07/26 18:56:15 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int oper_edit(int, int, int);
void oper(int);
int fac(int);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	int count = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		count = 0;
		cin >> n;
		int temp = 0;
		for (int i = 0; i <= n; i++) {

			for (int j = 0; j <= n/2; j++) {

				for (int k = 0; k <= n/3; k++) {
					temp = i * 1 + j * 2 + k * 3;

					if (temp > n) {
						break;
					}
					else if (temp == n) {
						count += oper_edit(i, j, k);
						//cout << i << " " << j << " " << k << " "<< oper_edit(i,j,k)<<'\n';
					}
				}
			}
		}

		cout << count << '\n';
	}

}


int oper_edit(int n1, int n2, int n3) {
	
	return fac(n1 + n2 + n3) / (fac(n1)*fac(n2)*fac(n3));
	

}

int fac(int n) {
	if (n == 0) {
		return 1;
	}
	else {
		int product = 1;
		for (int i = 1; i <= n; i++) {
			product *= i;
		}
		return product;
	}

}
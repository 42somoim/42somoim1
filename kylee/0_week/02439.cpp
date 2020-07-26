/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02439.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 23:01:20 by kylee             #+#    #+#             */
/*   Updated: 2020/07/23 23:01:21 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i < n - j - 1) {
				cout << " ";
			}
			else {
				cout << "*";
			}
		}
		cout << '\n';
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10952.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 22:54:47 by kylee             #+#    #+#             */
/*   Updated: 2020/07/23 22:54:57 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;

	while (true) {
		cin >> a >> b;
		if (a == 0 && b == 0) {
			break;
		}
		else {
			cout << a + b << '\n';
		}
	}
}
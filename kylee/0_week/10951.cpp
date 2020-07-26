/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10951.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 22:54:22 by kylee             #+#    #+#             */
/*   Updated: 2020/07/23 22:54:25 by kylee            ###   ########.fr       */
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
		if (!cin.eof()) {
			cout << a + b << '\n';
		}
		else {
			break;
		}
	}
}
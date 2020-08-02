/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11021.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 22:55:34 by kylee             #+#    #+#             */
/*   Updated: 2020/07/23 22:55:47 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, a, b;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << "Case #" << i + 1 << ": " << a + b << '\n';
	}
}
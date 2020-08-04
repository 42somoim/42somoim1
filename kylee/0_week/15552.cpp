/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15552.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 22:56:33 by kylee             #+#    #+#             */
/*   Updated: 2020/07/23 22:56:35 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t, a, b;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << a + b << '\n';
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10818.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 23:00:28 by kylee             #+#    #+#             */
/*   Updated: 2020/07/23 23:00:29 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, num, max = 0, min = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (i == 0) {
			max = num;
			min = num;
		}
		if (num >= max) {
			max = num;
		}

		if (num <= min) {
			min = num;
		}
	}
	cout << min << " " << max << '\n';
}
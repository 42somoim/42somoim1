/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02447.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 19:27:47 by kylee             #+#    #+#             */
/*   Updated: 2020/08/27 19:27:48 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;
void star(int, int, int);
char star_array[2207][2207] = {};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			star_array[i][j] = ' ';
		}
	}
	star(n, 0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << star_array[i][j];
		}
		if (i != n - 1) {
			cout << endl;
		}
	}
}

void star(int n, int x, int y) {
	if (n == 3) {
		for(int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i != 1 || j != 1) {
					star_array[y + i][x + j] = '*';
				}
			}
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i != 1 || j != 1) {
					star(n / 3, x + i * (n/3), y + j * (n/3));
				}
			}
		}
	}
}
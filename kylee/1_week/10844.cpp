/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10844.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 18:57:10 by kylee             #+#    #+#             */
/*   Updated: 2020/07/26 18:57:27 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

void oper(int);
const int div_s = 1000000000;
int dp[11][101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, answer = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		oper(i);
	}

	for (int i = 0; i < 10; i++) {
		answer = (answer + dp[i][n])%div_s;
	}
	cout << answer%div_s;
}

void oper(int i) {
	if (i == 1) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[j][i] = 0;
			}
			else {
				dp[j][i] = 1;
			}
		}
	}
	else {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[j][i] = (dp[j + 1][i - 1]) % div_s;
			}
			else if (j == 9) {
				dp[j][i] = (dp[j - 1][i - 1]) % div_s;
			}
			else {
				dp[j][i] = (dp[j - 1][i - 1] % div_s + dp[j + 1][i - 1] % div_s) % div_s;
			}
		}
	}
}
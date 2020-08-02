/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09465.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 18:56:37 by kylee             #+#    #+#             */
/*   Updated: 2020/07/26 18:56:53 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int dp[2][100001];
int max(int, int);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < n; k++) {
				cin >> dp[j][k];
			}
		}

		for (int j = 0; j < n; j++) {
			if (j == 0) {
				//pass;
			}
			else if (j == 1) {
				dp[0][j] += dp[1][j - 1];
				dp[1][j] += dp[0][j - 1];
			}
			else {
				dp[0][j] += max(dp[1][j - 1], dp[1][j - 2]);
				dp[1][j] += max(dp[0][j - 1], dp[0][j - 2]);
			}
			}
		cout << max(dp[1][n-1], dp[0][n-1]) << '\n';
	}
}

int max(int a, int b) {
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}

	return 0;
}
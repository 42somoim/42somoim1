/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11057.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 18:58:07 by kylee             #+#    #+#             */
/*   Updated: 2020/07/26 18:58:08 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, answer = 0;
	cin >> n;
	int dp[10][1001] = { 0 };

	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			for (int j = 0; j < 10; j++) {
				dp[j][i] = 1;
			}
		}
		else {
			for (int j = 0; j < 10; j++) {
				int sum = 0;
				for (int k = 0; k <= j; k++){
					sum = (sum%10007+ dp[k][i-1]%10007)%10007;
				}
				dp[j][i] = sum;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		answer = (answer % 10007 + dp[i][n]%10007)%10007;
	}

	cout << answer;
}
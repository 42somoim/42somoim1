/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02193.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 18:58:38 by kylee             #+#    #+#             */
/*   Updated: 2020/07/26 18:58:39 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

long long int dp[92][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, sum = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			dp[i][0] = 0; // 0으로 끝나는 개수
			dp[i][1] = 1; // 1로 끝나는 개수
		}
		else {
			dp[i][0] = dp[i-1][1] + dp[i-1][0];
			dp[i][1] = dp[i-1][0];
		}
	}

	cout << dp[n-1][1] + dp[n-1][0];
}
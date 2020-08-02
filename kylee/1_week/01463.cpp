/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01463.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 18:55:27 by kylee             #+#    #+#             */
/*   Updated: 2020/07/26 18:55:28 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int dp[1000001];

void oper(int);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		oper(i);
	}
	cout << dp[n];
}

void oper(int x) {
	if (x == 1) {
		dp[x] = 0;
	}
	else {
		if (x % 3 == 0 && x % 2 == 0) {
			//dp[x/3], dp[x/2], dp[x-1] 중 최솟값
			if (dp[x / 3] <= dp[x / 2] && dp[x / 3] <= dp[x - 1]) {
				dp[x] = dp[x / 3] + 1;
			}
			else if (dp[x / 2] <= dp[x / 3] && dp[x / 2] <= dp[x - 1]) {
				dp[x] = dp[x / 2] + 1;
			}
			else {
				dp[x] = dp[x - 1] + 1;
			}
		}
		else if (x % 3 == 0) {
			//dp[x/3], dp[x-1]중 최솟값
			if (dp[x / 3] < dp[x - 1]) {
				dp[x] = dp[x / 3] + 1;
			}
			else {
				dp[x] = dp[x - 1] + 1;
			}
		}
		else if (x % 2 == 0) {
			//dp[x/2], dp[x-1]중 최솟값
			if (dp[x / 2] > dp[x - 1]) {
				dp[x] = dp[x - 1] + 1;
			}
			else {
				dp[x] = dp[x / 2] + 1;
			}
		}
		else {
			//dp[x-1]
			dp[x] = dp[x - 1] + 1;
		}
	}
}
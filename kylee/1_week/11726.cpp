/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11726.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 18:55:40 by kylee             #+#    #+#             */
/*   Updated: 2020/07/26 18:55:45 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void oper(int);

using namespace std;
int dp[1001];
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

void oper(int n) {
	if (n == 1) {
		dp[n] = 1;
	}
	else if (n == 2) {
		dp[n] = 2;
	}
	else {
		dp[n] = (dp[n - 1] + dp[n - 2]) % 10007;
	}
}
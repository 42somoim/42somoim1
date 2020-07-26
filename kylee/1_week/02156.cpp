/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02156.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 18:58:57 by kylee             #+#    #+#             */
/*   Updated: 2020/07/26 18:59:15 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int dp[10005];
int input[10005];

int max(int, int);
int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		input[i] = temp;
	}
	dp[1] = input[1];
	dp[2] = input[2] + input[1];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 1], max(dp[i - 2] + input[i], dp[i - 3] + input[i - 1] + input[i]));
	}

	cout << dp[n];
}

int max(int a, int b) {
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}
}
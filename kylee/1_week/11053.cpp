/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11053.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 18:57:49 by kylee             #+#    #+#             */
/*   Updated: 2020/07/26 18:57:50 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int dp[1001];
int input[1001];

void oper(int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		input[i] = temp;
	}

	for (int i = 0; i < n; i++) {
		oper(i);
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		if (dp[i] > max) {
			max = dp[i];
		}
	}

	cout<<max;
}
void oper(int n) {
	int max = 0;
	if (n == 0) {
		dp[n] = 1;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (input[n] > input[i]) {
				if (dp[i] > max) {
					max = dp[i];
				}
			}
			else {

			}
		}

		dp[n] = max + 1;
	}
}
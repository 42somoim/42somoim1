/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   가장_긴_바이토닉_부분수열.cpp           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 04:21:06 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/08/13 04:28:53 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int main(void)
{
	int n;
	int *arr;
	int *lis_front;
	int *lis_back;

	cin >> n;
	arr = new int[n];
	lis_front = new int[n];
	lis_back = new int[n];

	for(int i = 0; i < n; i++)
		cin >> arr[i];

	for(int i = 0; i < n; i++) {
		lis_front[i] = 1;
		for(int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				lis_front[i] = max(lis_front[i], lis_front[j] + 1);
			}
		}
	}

	for(int i = n - 1; i >= 0; i--) {
		lis_back[i] = 1;
		for(int j = n - 1; j > i; j--) {
			if (arr[j] < arr[i]) {
				lis_back[i] = max(lis_back[i], lis_back[j] + 1);
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans = max(ans, lis_back[i] + lis_front[i] - 1);
	}
	cout << ans << endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   연속합.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 04:29:55 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/08/13 04:36:23 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int main(void)
{
	int n;
	int *arr;
	int *d;
	int ans;

	cin >> n;
	arr = new int[n + 1];
	d = new int[n + 1];

	for(int i = 0; i <= n; i++) {
		if (i > 0)
			cin >> arr[i];
		d[i] = 0;
	}

	ans = 0;
	for(int i = 1; i <= n; i++) {
		d[i] = d[i - 1] + arr[i];
		if (arr[i] > d[i])
			d[i] = arr[i];
		ans = max(ans, d[i]);
	}

	//ans가 0인 경우 (숫자를 선택하지 않았거나, 0을 선택한 경우)
	if (ans == 0) {
		ans = arr[1];
		for(int i = 1; i <= n; i++)
			ans = max(ans, arr[i]);
	}
	cout << ans << endl;
	delete[] arr;
	delete[] d;
}

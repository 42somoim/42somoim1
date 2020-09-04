/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   랜선_자르기.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 22:53:01 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/09/04 23:09:02 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int		getMax(int *arr, int size)
{
	int ans = arr[0];
	for (int i = 1; i < size; i++)
		ans = max(ans, arr[i]);
	return ans;
}

int		getAmount(int *lan, int size, int len)
{
	int amount = 0;
	for (int i = 0; i < size; i++)
		amount += (lan[i] / len);
	return amount;
}

int		solve(int n, int k, int *lan)
{
	int low = 0, high = getMax(lan, k);
	int ans = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		int amount = getAmount(lan, k, mid);
		if (amount >= n) {
			low = mid + 1;
			ans = mid;
		} else {
			high = mid - 1;
		}
	}
	return ans;
}

int		main(void)
{
	int n, k, *lan;
	cin >> k >> n;

	lan = new int[k];
	for (int i = 0; i < k; i++)
		cin >> lan[i];
	cout << solve(n, k, lan);
	delete[] lan;
	return 0;
}

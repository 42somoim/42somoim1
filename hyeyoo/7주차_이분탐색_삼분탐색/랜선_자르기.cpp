/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   랜선_자르기.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 22:53:01 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/09/04 23:17:17 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

long		getMax(long *arr, long size)
{
	long ans = arr[0];
	for (long i = 1; i < size; i++)
		ans = max(ans, arr[i]);
	return ans;
}

long		getAmount(long *lan, long size, long len)
{
	long amount = 0;
	for (long i = 0; i < size; i++)
		amount += (lan[i] / len);
	return amount;
}

long		solve(long n, long k, long *lan)
{
	long low = 0, high = 2147483647;
	long ans = 0;
	while (low <= high) {
		long mid = (low + high) / 2;
		long amount = getAmount(lan, k, mid);
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
	long n, k, *lan;
	cin >> k >> n;

	lan = new long[k];
	for (long i = 0; i < k; i++)
		cin >> lan[i];
	cout << solve(n, k, lan);
	delete[] lan;
	return 0;
}

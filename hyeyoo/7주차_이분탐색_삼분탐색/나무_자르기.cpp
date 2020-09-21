/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   나무_자르기.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 23:30:32 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/09/04 23:41:09 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

using namespace std;

long		max(long x, long y)
{
	return x > y ? x : y;
}

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
		amount += max(0, lan[i] - len);
	return amount;
}

long		solve(long n, long m, long *tree)
{
	long low = 0, high = 2147483647;
	long ans = 0;
	while (low <= high) {
		long mid = (low + high) / 2;
		long amount = getAmount(tree, n, mid);
		if (amount >= m) {
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
	long n, m, *tree;
	cin >> n >> m;
	
	tree = new long[n];
	for (long i = 0; i < n; i++)
		cin >> tree[i];
	std::cout << solve(n, m, tree) << std::endl;
	delete[] tree;
	return 0;
}

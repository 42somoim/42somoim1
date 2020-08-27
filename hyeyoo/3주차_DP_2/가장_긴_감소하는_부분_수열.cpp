/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   가장_긴_감소하는_부분_수열.cpp          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 04:16:16 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/08/13 04:20:07 by hyeyoo           ###   ########.fr       */
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
	arr = new int[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	d = new int[n];
	for(int i = 0; i < n; i++) {
		d[i] = 1;
		for(int j = 0; j < i; j++) {
			if (arr[j] > arr[i]) {
				d[i] = max(d[i], d[j] + 1);
			}
		}
		ans = max(ans, d[i]);
	}
	cout << ans << endl;
	delete[] arr;
	delete[] d;
}

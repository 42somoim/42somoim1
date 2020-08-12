/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   가장_큰_증가_부분_수열.cpp                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 03:58:14 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/08/13 04:14:58 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int main(void)
{
	int n;
	int ans;
	int *arr;
	int *d;
	cin >> n;

	arr = new int[n];
	d = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		d[i] = 0;
	}

	ans = d[0] = arr[0];
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				d[i] = max(d[i], d[j] +  arr[i]);
			} else {
				d[i] = max(d[i], arr[i]);
			}
		}
		ans = max(ans, d[i]);
	}
	cout << ans << endl;
	delete[] arr;
	delete[] d;
	return (0);
}

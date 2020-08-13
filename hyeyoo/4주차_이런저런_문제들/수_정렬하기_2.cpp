/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   수_정렬하기_2.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 17:01:25 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/08/13 17:07:14 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	int *arr;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	arr = new int[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	for(int i = 0; i < n; i++)
		cout << arr[i] << '\n';

	delete[] arr;
}

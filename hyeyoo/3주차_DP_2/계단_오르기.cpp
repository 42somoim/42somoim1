/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   계단_오르기.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 04:38:15 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/08/13 04:43:59 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int main(void)
{
	int n;
	int *arr;
	int *d;

	cin >> n;
	arr = new int[n];
	d = new int[n];

	for(int i = 0; i < n; i++)
		cin >> arr[i];

	if (n >= 1)
		d[0] = arr[0];
	if (n >= 2)
		d[1] = arr[0] + arr[1];
	if (n >= 3)
		d[2] = max(d[0] + arr[2], arr[1] + arr[2]);
	for(int i = 3; i < n; i++) {
		//1칸 점프 or 2칸 점프
		d[i] = max(d[i - 2] + arr[i], d[i - 3] + arr[i - 1] + arr[i]);
	}

	//마지막 칸은 반드시 밟으므로
	cout << d[n - 1] << endl;
	delete[] arr;
	delete[] d;
}

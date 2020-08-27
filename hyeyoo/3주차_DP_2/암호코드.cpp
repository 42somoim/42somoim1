/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   암호코드.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 14:48:55 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/08/13 14:52:48 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string code;
	getline(cin, code);
	int len = code.length();
	int *arr = new int[len + 1];

	for(int i = 1; i <= code.length(); i++) {
		arr[i] = code[i - 1] - '0';
	}

	const int b = 1000000;
	int *d = new int[len + 1];
	for(int i = 1; i <= len; i++) {
		if (1 <= arr[i] && arr[i] <= 9)
			d[i] = (d[i - 1]  + d[i]) % b;
		if (i >= 2) {
			int val = arr[i - 1] * 10 + arr[i];
			if (10 <= val && val <= 26) {
				d[i] = (d[i - 2] + d[i]) % b;
			}
		}
	}
	cout << d[len] << endl;
	delete[] d;
	delete[] arr;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10989.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:25:26 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 16:25:27 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int arr[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr[temp]++;
	}

	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < arr[i]; j++){
			cout << i <<'\n';
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02751.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:23:21 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 16:23:32 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> list;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		list.push_back(temp);
	}

	sort(list.begin(), list.end());

	for (int i = 0; i < n; i++) {
		cout << list[i] << '\n';
	}
}
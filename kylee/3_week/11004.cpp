/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11004.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:26:01 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 16:26:12 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	
	vector<int> list;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		list.push_back(temp);
	}

	sort(list.begin(), list.end());
	cout << list[k - 1];
	
}
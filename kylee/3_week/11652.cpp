/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11652.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:25:49 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 16:25:50 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

vector<long long int> list;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		long long int temp;
		cin >> temp;
		list.push_back(temp);
	}

	sort(list.begin(), list.end());

	int count = 0;
	int max_count = 0;
	long long int max = list[0];
	long long int now = list[0];
	for (int i = 0; i < n; i++) {
		if (now == list[i]) {
			count++;
		}
		else {
			if (max_count < count) {
				max_count = count;
				max = now;
				now = list[i];
				count = 1;
			}
			else {
				now = list[i];
				count = 1;
			}
		}
	}

	if (max_count < count) {
		max = now;
	}

	cout << max;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11720.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 22:57:45 by kylee             #+#    #+#             */
/*   Updated: 2020/07/23 22:57:46 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int size = 0;
	string num;
	int sum = 0;
	cin >> size;
	cin >> num;
	for (int i = 0; i < size; i++) {
		sum += int(num[i]) - 48;
	}

	cout << sum;

}